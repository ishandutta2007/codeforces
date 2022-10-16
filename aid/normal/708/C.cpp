#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 400 * 1000 + 5;
int ts[MAXN], dp[MAXN], n;
char ans[MAXN];
vector<int> g[MAXN];

void getDp(int v, int p) {
  ts[v] = 1;
  for(size_t i = 0; i < g[v].size(); i++) {
    int u = g[v][i];
    if(u == p) {
      swap(g[v][i], g[v].back());
      g[v].pop_back();
      break;
    }
  }
  dp[v] = 0;
  for(size_t i = 0; i < g[v].size(); i++) {
    int u = g[v][i];
    getDp(u, v);
    ts[v] += ts[u];
    dp[v] = max(dp[v], dp[u]);
  }
  if(2 * ts[v] <= n)
    dp[v] = max(dp[v], ts[v]);
}

void dfs(int v, int dpup) {
  if(2 * (n - ts[v]) > n) {
    if(2 * (n - ts[v] - dpup) <= n)
      ans[v] = true;
    else
      ans[v] = false;
  }
  else {
    bool found = false;
    for(size_t i = 0; i < g[v].size(); i++) {
      int u = g[v][i];
      if(2 * ts[u] > n) {
        if(2 * (ts[u] - dp[u]) <= n)
          ans[v] = true;
        else
          ans[v] = false;
        found = true;
        break;
      }
    }
    if(!found)
      ans[v] = true;
  }
  int sz = g[v].size();
  vector<int> pref(sz + 1), suff(sz + 1);
  pref[0] = 0;
  for(int i = 0; i < sz; i++)
    pref[i + 1] = max(pref[i], dp[g[v][i]]);
  suff[sz] = 0;
  for(int i = sz - 1; i >= 0; i--)
    suff[i] = max(suff[i + 1], dp[g[v][i]]);
  for(int i = 0; i < sz; i++) {
    int u = g[v][i], ndp = max(max(pref[i], suff[i + 1]), dpup);
    if(2 * (n - ts[u]) <= n)
      ndp = max(ndp, n - ts[u]);
    dfs(u, ndp);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  getDp(0, -1);
  dfs(0, 0);
  for(int i = 0; i < n; i++)
    cout << (int)ans[i] << ' ';
  cout << '\n';
  return 0;
}