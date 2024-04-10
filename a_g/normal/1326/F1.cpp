#include <bits/stdc++.h>
using namespace std;

const int N = 18;
long long dp[1<<N][N], dp2[N][1<<N], ans[1<<N];
bool a[N][N];

const int P = 1e5+3;
const int R = 7;
long long hash_to_cnt[P];
int pw[N];
int par = 0;
int vis = 0;

int add(int x, int y) {
  x += y;
  return (x >= P ? x-P : x);
}

void dfs(int n, int x, int cursum, int curhash, vector<long long> partition_dp) {
  vis++;
  if (cursum == n) {
    par++;
    long long val = 0;
    for (int mask = 0; mask < (1<<n); mask++) {
      val += ((n-__builtin_popcount(mask))&1 ? -1 : 1)*partition_dp[mask];
    }
    hash_to_cnt[curhash] = val;
    return;
  }
  for (int i = x; i+cursum <= n; i++) {
    if (i+cursum < n && 2*i+cursum > n) continue;
    vector<long long> newdp(1<<n);
    for (int mask = 0; mask < (1<<n); mask++) {
      newdp[mask] = partition_dp[mask]*dp2[i][mask];
    }
    dfs(n, i, cursum+i, add(curhash, pw[i-1]), newdp);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = R*pw[i-1] % P;
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = s[j] == '1';
    }
  }
  for (int mask = 1; mask < (1<<n); mask++) {
    for (int v = 0; v < n; v++) {
      if ((mask>>v)&1) {
        for (int u = 0; u < n; u++) {
          if (u == v) continue;
          if ((mask>>u)&1 && a[v][u]) {
            dp[mask][v] += dp[mask^(1<<v)][u];
          }
        }
        if ((mask&(mask-1)) == 0) {
          dp[mask][v] = 1;
        }
        dp2[__builtin_popcount(mask)][mask] += dp[mask][v];
      }
    }
  }

  for (int len = 0; len <= n; len++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1<<n); j++) {
        if ((j>>i)&1) {
          dp2[len][j] += dp2[len][j^(1<<i)];
        }
      }
    }
  }

  dfs(n, 1, 0, 0, vector<long long>(1<<n, 1));
  for (int mask = 0; mask < (1<<(n-1)); mask++) {
    int maskhash = 0;
    for (int i = 0; i < n;) {
      int d = __builtin_popcount(mask)-__builtin_popcount(mask+(1<<i));
      maskhash = add(maskhash, pw[d+1]);
      i += d+2;
    }
    ans[mask] = hash_to_cnt[maskhash];
  }

  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < (1<<(n-1)); j++) {
      if ((j>>i)&1) {
        ans[j^(1<<i)] -= ans[j];
      }
    }
  }
  for (int i = 0; i < (1<<(n-1)); i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}