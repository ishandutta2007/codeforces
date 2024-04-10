#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int c = count(s.begin(), s.end(), '1');
    if ((1LL*c*m) % n != 0) {
      cout << "-1\n";
      continue;
    }
    int target = 1LL*c*m/n;
    vector<int> pref(2*n+1);
    for (int i = 0; i < 2*n; i++) {
      pref[i+1] = pref[i] + (s[i%n] == '1');
    }
    for (int i = 0; i+m <= 2*n; i++) {
      if (pref[i+m]-pref[i] == target) {
        if (i+m <= n) {
          cout << "1\n";
          cout << i+1 << " " << i+m << '\n';
        }
        else {
          cout << "2\n";
          cout << 1 << " " << i+m-n << '\n';
          cout << i+1 << " " << n << '\n';
        }
        break;
      }
    }
  }
}