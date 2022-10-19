#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> c[N];
int l[N], r[N];
long long dp[N];
int ans = 0;

void dfs(int v) {
  dp[v] = 0;
  for (int u: c[v]) {
    dfs(u);
    dp[v] += dp[u];
  }
  if (dp[v] < l[v]) {
    ans++;
    dp[v] = r[v];
  }
  dp[v] = min<long long>(dp[v], r[v]);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      c[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      cin >> l[i] >> r[i];
    }
    dfs(1);


    cout << ans << '\n';

    for (int i = 1; i <= n; i++) {
      c[i].clear();
    }
    ans = 0;
  }
}