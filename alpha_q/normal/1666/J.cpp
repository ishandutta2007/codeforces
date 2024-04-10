#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 205;
const ll INF = 1e16 + 69;

int n, par[N][N], ans[N];
ll c[N][N], pf[N][N], f[N][N];

inline ll get (int x_l, int x_r, int y_l, int y_r) {
  return pf[x_r][y_r] - pf[x_l - 1][y_r] - pf[x_r][y_l - 1] + pf[x_l - 1][y_l - 1];
}

void go (int l = 1, int r = n, int from = 0) {
  if (l > r) return;
  int root = par[l][r];
  ans[root] = from;
  go(l, root - 1, root);
  go(root + 1, r, root);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%lld", c[i] + j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + c[i][j];
    }
  }
  for (int l = n; l >= 1; --l) {
    for (int r = l + 1; r <= n; ++r) {
      f[l][r] = INF;
      for (int root = l; root <= r; ++root) {
        ll cost = 0;
        if (l < root) {
          cost += f[l][root - 1] + get(l, root - 1, 1, l - 1) + get(l, root - 1, root, n);
        }
        if (root < r) {
          cost += f[root + 1][r] + get(root + 1, r, 1, root) + get(root + 1, r, r + 1, n);
        }
        if (cost < f[l][r]) {
          f[l][r] = cost, par[l][r] = root;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) par[i][i] = i;
  go();
  for (int i = 1; i <= n; ++i) {
    if (i > 1) printf(" "); printf("%d", ans[i]);
  }
  cout << '\n';
  return 0;
}