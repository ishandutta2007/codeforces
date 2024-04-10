#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;

int N, M, K;
int gp[MAXN];
int a[MAXN], b[MAXN];
vector <pii> adj[MAXN];
vector <int> induced[MAXN];
map <pii, vector <pii>> by_group;
int tmp_clr[MAXN];
int comp[MAXN];
int clr[MAXN];
int bad[MAXN];

void load() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; i++)
    scanf("%d", gp + i);
  for (int i = 0; i < M; i++)
    scanf("%d%d", a + i, b + i);  
}

bool dfs_induced(int x, int c, int curr) {
  comp[x] = curr;
  if (clr[x] != -1)
    return clr[x] == c;
  clr[x] = c;
  for (auto it : induced[x])
    if (!dfs_induced(it, c ^ 1, curr))
      return false;
  return true; 
}

bool dfs_diff(int x, int c) {
  if (tmp_clr[x] != -1)
    return tmp_clr[x] == c;
  tmp_clr[x] = c;
  for (auto it : adj[x])
    if (!dfs_diff(it.first, c ^ it.second))
      return false;
  return true;
}

bool process(const vector <pii> &edges) {
  vector <int> nodes;
  for (auto it : edges) {
    nodes.push_back(comp[it.first]);
    nodes.push_back(comp[it.second]);
  }
  for (auto it : nodes) {
    tmp_clr[it] = -1;
    adj[it].clear();
  }
  for (auto it : edges) {
    adj[comp[it.first]].push_back({comp[it.second], clr[it.first] ^ clr[it.second]});
    adj[comp[it.second]].push_back({comp[it.first], clr[it.first] ^ clr[it.second]});
  }
  
  for (auto it : nodes)
    if (tmp_clr[it] == -1 && !dfs_diff(it, 0))
      return true;
      
  return false;
}

ll solve() {
  memset(clr, -1, sizeof clr);
  for (int i = 0; i < M; i++)
    if (gp[a[i]] == gp[b[i]]) {
      induced[a[i]].push_back(b[i]);
      induced[b[i]].push_back(a[i]);
    }
  
  int cookie = 0;
  for (int i = 1; i <= N; i++)
    if (clr[i] == -1)
      bad[gp[i]] |= !dfs_induced(i, 0, ++cookie);
  
  for (int i = 0; i < M; i++) {
    int ga = gp[a[i]];
    int gb = gp[b[i]];
    if (ga == gb || bad[ga] || bad[gb])
      continue;
    if (ga > gb) {
      swap(a[i], b[i]);
      swap(ga, gb);
    }
    by_group[{ga, gb}].push_back({a[i], b[i]});
  }
    
  int bad_pairs = 0;
  int good = K - accumulate(bad + 1, bad + K + 1, 0);
  for (auto it : by_group)
    bad_pairs += process(it.second);
    
  return (ll)good * (good - 1) / 2 - bad_pairs;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}