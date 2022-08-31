#include <iostream>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  m = min(m, n);

  for (int i = 0; i < m; i++) {
    auto nu = s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '0') {
        int nb = 0;
        if (j != 0 && s[j - 1] == '1') nb++;
        if (j != n - 1 && s[j + 1] == '1') nb++;
        if (nb == 1) {
          nu[j] = '1';
        }
      }
    }
    s = nu;
  }

  cout << s << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}