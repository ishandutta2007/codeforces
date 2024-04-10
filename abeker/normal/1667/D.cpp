#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
vector <int> adj[MAXN];
vector <pair <int, int>> ans;
int clr[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    adj[i].clear();
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

bool dfs_prep(int x, int p) {
  clr[x] = adj[x].size() % 2;
  for (auto it : adj[x]) 
    if (it != p) {
      if (!dfs_prep(it, x))
        return false;
      clr[x] -= clr[it];
    }
  return abs(clr[x]) == (x > 1);
}

void dfs_solve(int x, int p) {
  vector <vector <int>> by_clr(2);
  for (auto it : adj[x])
    by_clr[(1 - clr[it == p ? x : it]) / 2].push_back(it);
  for (int i = 0; i < adj[x].size(); i++) {
    int tmp = by_clr[i % 2].back();
    by_clr[i % 2].pop_back();
    if (tmp == p)
      ans.push_back({p, x});
    else
      dfs_solve(tmp, x);
  }
}

void solve() {
  if (!dfs_prep(1, 0)) {
    puts("NO");
    return;
  }
  ans.clear();
  dfs_solve(1, 0);
  reverse(ans.begin(), ans.end());
  puts("YES");
  for (auto it : ans)
    printf("%d %d\n", it.first, it.second);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}