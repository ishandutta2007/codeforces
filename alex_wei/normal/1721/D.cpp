#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a, b;
vector<pair<vector<int>, vector<int>>> cur;
void solve() {
  cin >> n;
  a.clear(), b.clear(), cur.clear();
  for(int i = 1, v; i <= n; i++) cin >> v, a.push_back(v);
  for(int i = 1, v; i <= n; i++) cin >> v, b.push_back(v);
  cur.push_back({a, b});
  int ans = 0;
  for(int i = 29; ~i; i--) {
    bool ok = 1;
    auto tmp = cur;
    tmp.clear();
    for(auto it : cur) {
      vector<int> a0, a1, b0, b1;
      for(int v : it.first) v >> i & 1 ? a1.push_back(v) : a0.push_back(v);
      for(int v : it.second) v >> i & 1 ? b1.push_back(v) : b0.push_back(v);
      if(a0.size() == b1.size()) {
        if(!a0.empty()) tmp.push_back({a0, b1});
        if(!a1.empty()) tmp.push_back({a1, b0});
      }
      else ok = 0;
    }
    if(ok) ans += 1 << i, cur = tmp;
  }
  cout << ans << "\n";
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