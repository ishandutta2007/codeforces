#include <iostream>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  int rpar = -1;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;

      if (c == 'R') {
        if (rpar == -1) {
          rpar = (i + j) % 2;
        } else if ((i + j) % 2 != rpar) {
          ok = false;
        }
      } else if (c == 'W') {
        if (rpar == -1) {
          rpar = (i + j + 1) % 2;
        } else if ((i + j + 1) % 2 != rpar) {
          ok = false;
        }
      }
    }
  }

  if (!ok) {
    cout << "NO" << '\n';
    return;
  }

  if (rpar == -1) rpar = 0;

  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == rpar) {
        cout << 'R';
      } else {
        cout << 'W';
      }
    }
    cout << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}