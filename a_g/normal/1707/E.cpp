#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int L = __lg(N)+1;
const int K = 20;

struct interval {
  int l, r;
};

interval tbl[K][L][N];

interval operator + (interval x, interval y) {
  return interval{min(x.l, y.l), max(x.r, y.r)};
}

interval f(interval x, int k) {
  int j = __lg(x.r-x.l+1);
  return tbl[k][j][x.l]+tbl[k][j][x.r-(1<<j)+1];
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    tbl[0][0][i] = interval{x, x};
  }
  for (int j = 1; j < L; j++) {
    for (int i = 1; i+(1<<j) <= n+1; i++) {
      tbl[0][j][i] = tbl[0][j-1][i]+tbl[0][j-1][i+(1<<(j-1))];
    }
  }

  for (int k = 1; k < K; k++) {
    for (int j = 0; j < L; j++) {
      for (int i = 1; i+(1<<j) <= n+1; i++) {
        tbl[k][j][i] = f(tbl[k-1][j][i], k-1);
      }
    }
  }

  while (q--) {
    interval z;
    cin >> z.l >> z.r;
    if (z.l == 1 && z.r == n) {
      cout << "0\n";
      continue;
    }
    interval z_far = f(z, K-1);
    if (z_far.l != 1 || z_far.r != n) {
      cout << "-1\n";
      continue;
    }
    int ans = 1;
    for (int k = K-2; k >= 0; k--) {
      interval zp = f(z, k);
      if (zp.l != 1 || zp.r != n) {
        ans += (1<<k);
        z = zp;
      }
    }
    cout << ans << '\n';
  }
}