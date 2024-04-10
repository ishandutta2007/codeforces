#include <bits/stdc++.h>
using namespace std;

const int N = 18;
long long dp[1<<N][N], dp2[N+1][1<<N], ans[1<<N];
bool a[N][N];
map<vector<int>, vector<int>> partition_to_masks;

vector<int> cur;
int p = 0;

void dfs(int n, vector<long long> partition_dp) {
  int s = accumulate(cur.begin(), cur.end(), 0);
  if (s == n) {
    long long val = 0;
    for (int mask = 0; mask < (1<<n); mask++) {
      val += ((n-__builtin_popcount(mask))&1 ? -1 : 1)*partition_dp[mask];
    }
    for (int mask: partition_to_masks[cur]) {
      ans[mask] = val;
    }
    return;
  }
  for (int i = (cur.empty() ? 1 : cur.back()); i+s <= n; i++) {
    if (i+s < n && 2*i+s > n) continue;
    cur.push_back(i);
    vector<long long> newdp(1<<n);
    for (int mask = 0; mask < (1<<n); mask++) {
      newdp[mask] = partition_dp[mask]*dp2[i][mask];
    }
    dfs(n, newdp);
    cur.pop_back();
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int mask = 0; mask < (1<<(n-1)); mask++) {
    vector<int> partition;
    for (int i = 0; i < n;) {
      int d = __builtin_popcount(mask)-__builtin_popcount(mask+(1<<i));
      partition.push_back(d+2);
      i += d+2;
    }
    sort(partition.begin(), partition.end());
    partition_to_masks[partition].push_back(mask);
  }

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

  dfs(n, vector<long long>(1<<n, 1));

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