<?php

/**
 * @file
 * Settings page for the hide_language_links module.
 */

/**
 * Form builder for hide_language_links settings page; system_settings_form().
 */
function hide_language_links_settings() {
  $form = array();
  $default_values = hide_language_links_variables();

  $form['hide_language_links_hide_active_language'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide active language'),
    '#description' => t('Hides the language link for the active language for all users.'),
    '#default_value' => variable_get('hide_language_links_hide_active_language', $default_values['hide_language_links_hide_active_language']),
  );

  $languages = language_list('enabled');
  $language_options = array();
  foreach ($languages[1] as $language) {
    $language_options[$language->language] = "{$language->name} ({$language->native})";
  }

  $form['hide_language_links_languages'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hide specific languages'),
    '#description' => t('Select the languages which should be hidden from users without sufficient access rights.'),
    '#options' => $language_options,
    '#default_value' => variable_get('hide_language_links_languages', $default_values['hide_language_links_languages']),
  );

  $form['hide_language_links_ignore_active_language'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override active language link'),
    '#description' => t('The language link for the active language is shown even if that specific language is set to be hidden. 
                      This setting will be ignored if the active language is explicitly set to be hidden.'),
    '#default_value' => variable_get('hide_language_links_ignore_active_language', $default_values['hide_language_links_ignore_active_language']),
    '#disabled' => variable_get('hide_language_links_hide_active_language') ? TRUE : FALSE,
  );
  return system_settings_form($form);
}