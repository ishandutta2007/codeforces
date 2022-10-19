#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
bool closed[N][N];
int dp[N][N][2];
int freecells;
int n, m;
long long ans;

void upd(int x, int y) {
  if (x > n || y > m) return;
  int old = dp[x][y][0] + dp[x][y][1];
  dp[x][y][0] = (dp[x-1][y][1] + 1);
  dp[x][y][1] = (dp[x][y-1][0] + 1);
  if (closed[x][y]) {
    dp[x][y][0] = 0;
    dp[x][y][1] = 0;
  }
  ans += (dp[x][y][0]+dp[x][y][1])-old;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> n >> m >> q;
  freecells = n*m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      upd(i, j);
    }
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    freecells += 2*closed[x][y]-1;
    closed[x][y] = 1-closed[x][y];
    upd(x, y);
    for (int d = 0; min(x, y)+d <= min(n, m); d++) {
      upd(x+d+1, y+d);
      upd(x+d, y+d+1);
      upd(x+d+1, y+d+1);
    }
    cout << ans-freecells << '\n';
  }
}