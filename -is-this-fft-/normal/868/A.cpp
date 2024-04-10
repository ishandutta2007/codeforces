#include <iostream>

using namespace std;

void success () {
  cout << "YES" << endl;
  exit(0);
}

const int ALPH = 256;

bool hasf [ALPH];
bool hass [ALPH];

int main () {
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;

    if (t == s) {
      success();
    }

    hasf[t[0]] = 1;
    hass[t[1]] = 1;
  }

  if (hass[s[0]] && hasf[s[1]]) {
    success();
  }

  cout << "NO" << endl;
}