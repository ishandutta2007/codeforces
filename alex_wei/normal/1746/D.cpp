#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 5;
int n, k, s[N], ss[N], p[N];
vector<int> e[N];
map<int, ll> mp[N];
ll dfs(int id, int k) {
  if(!k) return 0;
  if(e[id].empty()) return 1ll * k * ss[id];
  auto it = mp[id].find(k);
  if(it != mp[id].end()) return it->second;
  ll res = 0, c = k / e[id].size(), r = k % e[id].size();
  vector<ll> delta;
  for(int it : e[id]) {
    ss[it] = s[it] + ss[id], res += dfs(it, c);
    if(r) delta.push_back(dfs(it, c + 1) - dfs(it, c));
  }
  sort(delta.begin(), delta.end(), [&](ll x, ll y) {return x > y;});
  for(int i = 0; i < r; i++) res += delta[i];
  return mp[id][k] = res;
}
void solve() {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) e[i].clear(), mp[i].clear();
  for(int i = 2; i <= n; i++) cin >> p[i], e[p[i]].push_back(i);
  for(int i = 1; i <= n; i++) cin >> s[i];
  ss[1] = s[1], cout << dfs(1, k) << endl;
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