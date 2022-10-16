#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 5;
int n, deg[N], col[N];
vector<int> e[N];
set<pair<int, int>> s;
void dfs(int id, int c) {
  if(col[id]) return;
  col[id] = c;
  for(int it : e[id]) dfs(it, c);
}
void solve() {
  cin >> n;
  s.clear();
  for(int i = 1; i <= n; i++) e[i].clear(), col[i] = 0;
  for(int i = 1; i <= n; i++) cin >> deg[i], s.insert({deg[i], i});
  while(!s.empty()) {
    pair<int, int> t = *--s.end();
    s.erase(--s.end());
    int d = t.first, id = t.second;
    for(int j = 0; j < d; j++) {
      cout << "? " << id << endl;
      int res; cin >> res;
      e[id].push_back(res);
      e[res].push_back(id);
      auto pt = s.find({deg[res], res});
      if(pt == s.end()) break;
      else s.erase(pt);
    }
  }
  for(int i = 1; i <= n; i++) dfs(i, i);
  cout << "! ";
  for(int i = 1; i <= n; i++) cout << col[i] << " ";
  cout << endl;
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}