#include <iostream>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 1e3 + 5;

int arr [MAX_N][MAX_N];
int l [MAX_N][MAX_N];
int r [MAX_N][MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        l[i][j] = arr[i][j];
        r[i][j] = arr[i][j];
        continue;
      }

      l[i][j] = INF;
      r[i][j] = -INF;
      if (i != 0) {
        l[i][j] = min(l[i][j], l[i - 1][j] + arr[i][j]);
        r[i][j] = max(r[i][j], r[i - 1][j] + arr[i][j]);
      }

      if (j != 0) {
        l[i][j] = min(l[i][j], l[i][j - 1] + arr[i][j]);
        r[i][j] = max(r[i][j], r[i][j - 1] + arr[i][j]);
      }
    }
  }

  if (l[n - 1][m - 1] % 2 != 0) {
    cout << "NO" << '\n';
    return;
  }

  if (l[n - 1][m - 1] <= 0 && 0 <= r[n - 1][m - 1]) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
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