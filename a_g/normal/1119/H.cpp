#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int M = 3;

void fwht(vector<int>& a) {
  int n = (int)a.size();
  assert((n&(n-1)) == 0);
  for (int z = 1; z < n; z <<= 1) {
    for (int i = 0; i < n; i++) {
      if (i&z) {
        int x = a[i];
        int y = a[i^z];
        a[i] = (y-x)%MOD;
        a[i^z] = (y+x)%MOD;
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> X(1<<M);
  for (int i = 0; i < M; i++) cin >> X[1<<i];
  fwht(X);
  vector<vector<int>> pw(1<<M, vector<int>(n+1, 1));
  for (int i = 0; i < 1<<M; i++) {
    for (int j = 1; j <= n; j++) {
      pw[i][j] = 1LL*pw[i][j-1]*X[i] % MOD;
    }
  }

  vector<int> C(1<<(k+M));
  array<int, M> A;
  for (int i = 0; i < n; i++) {
    for (int& x: A) cin >> x;
    for (int i = 0; i < (1<<M); i++) {
      int c = 0;
      for (int j = 0; j < M; j++) {
        if ((i>>j)&1) c ^= A[j];
      }
      C[c<<M|i]++;
    }
  }
  fwht(C);
  int l = 1;
  for (int i = 0; i < k; i++) l = 1LL*l*(MOD+1)/2 % MOD;
  vector<int> ans(1<<k, l);
  for (int i = 0; i < (1<<(k+M)); i++) {
    ans[i>>M] = 1LL*ans[i>>M]*pw[i&((1<<M)-1)][C[i]>>M] % MOD;
  }
  fwht(ans);
  for (int& x: ans) {
    if (x < 0) x += MOD;
    cout << x << ' ';
  }
  cout << '\n';
}