#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 3605;
int fact[N], invfact[N];
int rowdp[N][N][2];
int coldp[N][N][2];

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int inversemod(int p, int q) {
  // assumes p > 0
  // https://codeforces.com/blog/entry/23365
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
}

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> used_row(n), used_col(m);
  while (k--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    used_row[r1] = 1;
    used_row[r2] = 1;
    used_col[c1] = 1;
    used_col[c2] = 1;
  }

  int free_rows = n-accumulate(used_row.begin(), used_row.end(), 0);
  int free_cols = m-accumulate(used_col.begin(), used_col.end(), 0);
  rowdp[0][0][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i/2; j++) {
      for (int k = 0; k < 2; k++) {
        if (!rowdp[i][j][k]) continue;
        if (used_row[i]) {
          add(rowdp[i+1][j][1], rowdp[i][j][k]);
        }
        else {
          add(rowdp[i+1][j][0], rowdp[i][j][k]);
          if (k == 0) {
            add(rowdp[i+1][j+1][1], rowdp[i][j][k]);
          }
        }
      }
    }
  }

  coldp[0][0][1] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= i/2; j++) {
      for (int k = 0; k < 2; k++) {
        if (!coldp[i][j][k]) continue;
        if (used_col[i]) {
          add(coldp[i+1][j][1], coldp[i][j][k]);
        }
        else {
          add(coldp[i+1][j][0], coldp[i][j][k]);
          if (k == 0) {
            add(coldp[i+1][j+1][1], coldp[i][j][k]);
          }
        }
      }
    }
  }

  int ans = 0;
  for (int d1 = 0; d1 <= free_rows; d1++) {
    for (int d2 = 0; d1+2*d2 <= free_rows && d2+2*d1 <= free_cols; d2++) {
      int term = 1;
      for (int x: {
          rowdp[n][d2][0]+rowdp[n][d2][1],
          coldp[m][d1][0]+coldp[m][d1][1],
          fact[free_rows-2*d2],
          invfact[free_rows-2*d2-d1],
          fact[free_cols-2*d1],
          invfact[free_cols-2*d1-d2],
          }) {
        term = 1LL*x*term % MOD;
      }
      add(ans, term);
    }
  }

  cout << ans << '\n';
}