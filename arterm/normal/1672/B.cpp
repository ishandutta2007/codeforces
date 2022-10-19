#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    bool ok = true;
    int cur = 0;
    for (char c : s) {
      if (c == 'B')
        cur++;
      if (c == 'A')
        cur = max(0, cur - 1);
    }

    if (cur == 0 && s[0] == 'B') {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }


  return 0;
}