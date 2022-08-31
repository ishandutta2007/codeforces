#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 505;
const int INF = 1e9 + 2000;

ll arr [MAX_N][MAX_N];

void solve () {
  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      cin >> arr[i][j];
      if (i >= n && j >= n) {
        ans += arr[i][j];
      }
    }
  }

  ll add = INF;
  add = min(add, arr[0][n]);
  add = min(add, arr[0][2 * n - 1]);
  add = min(add, arr[n - 1][n]);
  add = min(add, arr[n - 1][2 * n - 1]);
  
  add = min(add, arr[n][0]);
  add = min(add, arr[2 * n - 1][0]);
  add = min(add, arr[n][n - 1]);
  add = min(add, arr[2 * n - 1][n - 1]);

  cout << ans + add << '\n';
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