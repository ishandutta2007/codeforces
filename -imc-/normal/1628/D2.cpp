#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

li MOD = 1e9 + 7;

//vector<vector<li>> ans;
const int maxN = 1e6 + 7;

li modpow(li x, li p) {
  li ans = 1;
  while (p) {
    if (p % 2 == 1) {
      ans = (ans * x) % MOD;
    }
    x = (x * x) % MOD;
    p /= 2;
  }
  return ans;
}

vector<li> fac;

li c(li N, li M) {
  if (M < 0) {
    return 0;
  }
  return ((fac[N] * modpow(fac[N - M], MOD - 2)) % MOD * modpow(fac[M], MOD - 2)) % MOD;
}

void solve(bool read = true) {
  li N, M, k;
  cin >> N >> M >> k;

  if (fac.empty()) {
    fac.resize(maxN);
    fac[0] = 1;
    for (int i = 1; i < fac.size(); ++i) {
      fac[i] = fac[i - 1] * i % MOD;
    }
  }

  li inv2 = 500000004;
  li ans = 0;

#if 0
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) {
        mat[i][j] = 0;
      } else if (j != i) {
        mat[i][j] = (mat[i - 1][j] + mat[i - 1][j - 1]) % MOD;
      } else {
        mat[i][j] = modpow(2, i - 1) * i % MOD;
      }
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }
#endif

  if (M == N) {
    ans = modpow(2, N - 1) * N % MOD;
  } else {
    for (int i = 1; i <= M; ++i) {
      //cout << c(N - i, M - i) << " " << i << " " << modpow(2, i - 1) << "\n";
      li B = modpow(2, i - 1) * i % MOD;

      li c1 = N - i - 1;
      li c2 = M - i;
      li w = c(c1, c2);

      //cout << "weight of " << B << " is " << w << " = c(" << c1 << "," << c2 << ")" << endl;
      ans = (ans + B * w) % MOD;
    }
  }

#if 1
  for (int i = 0; i < N - 1; ++i) {
    ans = ans * inv2 % MOD;
  }

  ans = ans * k % MOD;
#endif

  cout << ans << "\n";

  /*
  if (read) {
    cin >> N >> M >> k;
  } else {
    N = M = 2000;
    k = 1;
  }

  //ans.assign(N + 1, vector<li>(N + 1));

  for (int n = 0; n <= N; ++n) {
    for (int m = 0; m <= n; ++m) {
      if (n == m) {
        ans[n][m] = k * n % MOD;
      } else if (m == 0) {
        ans[n][m] = 0;
      } else {
        ans[n][m] = (ans[n - 1][m] + ans[n - 1][m - 1]) * inv2 % MOD;
      }
    }
  }

  cout << ans[N][M] << "\n";*/
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#else
  for (int i = 0; i < 1000; ++i) {
    solve(false);
  }
#endif

  return 0;
}