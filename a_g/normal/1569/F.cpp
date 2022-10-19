#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
vector<vector<bool>> adj;
vector<unsigned int> pow6(12);
unordered_map<unsigned int, bool> validgroups;
vector<int> labelcounts(12);
ll ans = 0;

bool valid (vector<vector<int>>& groups) {
  vector<vector<bool>> dp(1<<(n/2), vector<bool>(n/2, 0));
  vector<int> is_queued(1<<(n/2));
  queue<int> q;
  for (int i = 0; i < n/2; i++) {
    if (adj[groups[i][0]][groups[i][1]]) {
      dp[1<<i][i] = 1;
    }
    q.push(1<<i);
    is_queued[1<<i] = 1;
  }
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (int i = 0; i < n/2; i++) {
      if (!(s&(1<<i))) {
        int newset = s|(1<<i);
        for (int j = 0; j < n/2; j++) {
          if (dp[s][j] && 
              (
               (adj[groups[i][0]][groups[j][0]] && adj[groups[i][1]][groups[j][1]])
               || 
               (adj[groups[i][0]][groups[j][1]] && adj[groups[i][1]][groups[j][0]])
              )
             ) {
            dp[newset][i] = 1;
          }
        }
        if (!is_queued[newset]) {
          q.push(newset);
          is_queued[newset] = 1;
        }
      }
    }
  }
  for (int i = 0; i < n/2; i++) {
    if (dp[(1<<(n/2))-1][i]) return 1;
  }
  return 0;
}

unsigned int ghash(vector<vector<int>>& grouping) {
  unsigned int ans = 0;
  for (int i = 0; i < grouping.size(); i++) {
    for (int j: grouping[i]) ans += i*pow6[j];
  }
  return ans;
}

bool majorizer(const vector<int>& a, const vector<int>& b) {
  return a[0] < b[0];
}

bool dfs(vector<vector<int>> grouping) {
  unsigned int hashval = ghash(grouping);
  if (validgroups.count(hashval)) {
    return validgroups[hashval];
  }
  bool good = 0;
  int u = grouping.size();
  if (u == n/2) {
    good = valid(grouping);
  }
  for (int k = 0; k < u; k++) {
    int m = grouping[k].size();
    if (m == 2) continue;
    for (int i = 1; i < (1<<(m-1))-1; i++) {
      if (__builtin_parity(i)&1) continue;
      vector<vector<int>> y = grouping;
      y[k].clear();
      y.push_back(vector<int>());
      y[k].push_back(grouping[k][0]);
      for (int j = 0; j < m-1; j++) {
        if ((i>>j)&1) y[u].push_back(grouping[k][j+1]);
        else y[k].push_back(grouping[k][j+1]);
      }
      sort(y.begin(), y.end(), majorizer);
      if (dfs(y)) {
        good = 1;
      }
    }
  }
  validgroups[hashval] = good;
  if (good) ans += labelcounts[u];
  return good;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  pow6[0] = 1;
  for (int i = 0; i < 11; i++) {
    pow6[i+1] = 6*pow6[i];
  }
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    adj.emplace_back(n);
  }
  labelcounts[1] = k;
  for (int i = 1; i < 11; i++) {
    labelcounts[i+1] = labelcounts[i]*(k-i);
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  vector<vector<int>> start;
  start.push_back(vector<int>(n));
  iota(start[0].begin(), start[0].end(), 0);
  dfs(start);
  cout << ans << endl;
}