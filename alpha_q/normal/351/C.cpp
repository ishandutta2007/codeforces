#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 69;
const ll INF = 1e16 + 5;

int n, m, a[N], b[N];
ll cost[N][N][N], base[N][N], tmp[N][N], ret[N][N];

void mult (ll a[N][N], ll b[N][N], ll c[N][N]) {
  for (int i = 0; i <= n + n; ++i) {
    for (int j = 0; j <= n + n; ++j) {
      c[i][j] = INF;
      for (int k = 0; k <= n + n; ++k) {
        c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
      }
    }    
  }
}

void copy (ll a[N][N], ll b[N][N]) {
  for (int i = 0; i <= n + n; ++i) {
    for (int j = 0; j <= n + n; ++j) {
      b[i][j] = a[i][j];
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n + n; ++j) {
      for (int k = 0; k <= n + n; ++k) {
        if (!i) {
          cost[i][j][k] = j == k ? 0 : INF;
          continue;
        }
        cost[i][j][k] = INF;
        if (k) cost[i][j][k] = min(cost[i][j][k], a[i - 1] + cost[i - 1][j][k - 1]);
        if (k < n + n) cost[i][j][k] = min(cost[i][j][k], b[i - 1] + cost[i - 1][j][k + 1]);
      }
    }
  }
  for (int i = 0; i <= n + n; ++i) {
    for (int j = 0; j <= n + n; ++j) base[i][j] = cost[n][i][j];
  }
  for (int i = 0; i <= n + n; ++i) {
    for (int j = 0; j <= n + n; ++j) {
      ret[i][j] = i == j ? 0 : INF;
    }
  }
  while (m) {
    if (m & 1) mult(base, ret, tmp), copy(tmp, ret);
    mult(base, base, tmp), copy(tmp, base), m >>= 1;
  }
  cout << ret[0][0] << '\n';
  return 0;
}