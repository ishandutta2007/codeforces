#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  int amx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    amx = max(x, amx);
  }

  int m;
  cin >> m;
  
  int bmx = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;

    bmx = max(x, bmx);
  }

  if (amx >= bmx) {
    cout << "Alice" << '\n';
  } else {
    cout << "Bob" << '\n';
  }

  if (amx > bmx) {
    cout << "Alice" << '\n';
  } else {
    cout << "Bob" << '\n';
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