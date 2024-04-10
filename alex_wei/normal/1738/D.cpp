#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 5;
int n, b[N];
vector<int> e[N], ans;
void dfs(int id) {
  ans.push_back(id);
  for(int it : e[id]) if(e[it].empty()) dfs(it);
  for(int it : e[id]) if(!e[it].empty()) dfs(it);
}
void solve() {
  cin >> n, ans.clear();
  for(int i = 0; i <= n + 1; i++) e[i].clear();
  for(int i = 1; i <= n; i++) cin >> b[i];
  int mn = 0, mx = n + 1;
  for(int i = 1; i <= n; i++) {
    e[b[i]].push_back(i);
    if(i > b[i]) mx = min(mx, i - 1), mn = max(mn, b[i]);
    else mx = min(mx, b[i] - 1), mn = max(mn, i);
  }
  if(e[0].size()) dfs(0);
  else dfs(n + 1);
  cout << mn << "\n";
  for(int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}