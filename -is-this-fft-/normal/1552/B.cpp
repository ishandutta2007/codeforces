#include <iostream>

using namespace std;

const int MAX_N = 5e4 + 5;

int str [MAX_N][5];

bool stronger (int u, int v) {
  int wins = 0;
  for (int i = 0; i < 5; i++) {
    if (str[u][i] < str[v][i]) {
      wins++;
    }
  }

  return wins >= 3;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> str[i][j];
    }
  }

  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (stronger(i, ans)) {
      ans = i;
    }
  }

  for (int i = 0; i < n; i++) {
    if (i != ans) {
      if (stronger(i, ans)) {
        cout << -1 << '\n';
        return;
      }
    }
  }

  cout << ans + 1 << '\n';
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