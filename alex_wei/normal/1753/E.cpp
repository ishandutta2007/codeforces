// LUOGU_RID: 91281020
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
constexpr int N = 1e6 + 5;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll ans;
int n, b, p, m;
int c, mul[32], pick[32];
vector<ll> a[32], s[32];
pair<ll, ll> check(ll v) {
  static ll pre[32];
  pre[0] = 1;
  for(int i = 1; i <= c; i++) {
    pre[i] = pre[i - 1];
    if(!pick[i - 1]) pre[i] *= mul[i - 1];
  }
  ll cnt = 0, sum = 0, prod = 1;
  for(int i = c; ~i; i--) {
    int l = -1, r = (int) a[i].size() - 1;
    while(l < r) {
      int m = l + r + 2 >> 1;
      if(a[i][m] * prod * (pre[i] - 1) >= v) l = m;
      else r = m - 1;
    }
    if(l >= 0) cnt += l + 1, sum += s[i][l] * prod * (pre[i] - 1);
    if(i && !pick[i - 1]) prod *= mul[i - 1];
  }
  return make_pair(cnt, sum + prod);
}
void solve() {
  ll rem = b, sum = 0, prod = 1, move = 1;
  for(int i = c; ~i; i--) {
    if(!s[i].empty()) sum += s[i].back() * prod;
    if(i) {
      if(pick[i - 1]) move *= mul[i - 1], rem -= m;
      else prod *= mul[i - 1];
    }
  }
  if(rem < 0) return;
  rem /= p;
  ll l = 1, r = inf;
  while(l < r) {
    ll m = l + r >> 1;
    auto dat = check(m);
    if(dat.first <= rem) r = m;
    else l = m + 1;
  }
  auto dat = check(l);
  // cout << l << " " << dat.second << " " << dat.first << " " << sum << " " << move << "\n";
  ans = max(ans, (sum + dat.second + (l - 1) * (rem - dat.first)) * move);
}
void dfs(int id) {
  solve();
  for(int i = id + 1; i < c; i++) {
    bool canpick = 1;
    for(int j = 0; j < i; j++)
      if(mul[j] == mul[i] && !pick[j])
        canpick = 0;
    if(!canpick) continue;
    pick[i] = 1, dfs(i), pick[i] = 0;
  }
}
int main() {
  cin >> n >> b >> p >> m;
  for(int i = 1; i <= n; i++) {
    char s = getchar();
    while(s != '*' && s != '+') s = getchar();
    int a = read();
    if(s == '*' && a == 1) i--, n--;
    else if(s == '*') mul[c++] = a;
    else ::a[c].push_back(a);
  }
  for(int i = 1; i <= c; i++) sort(a[i].begin(), a[i].end());
  for(int i = 0; i <= c; i++) {
    sort(a[i].begin(), a[i].end());
    reverse(a[i].begin(), a[i].end());
    for(int it : a[i]) s[i].push_back(s[i].empty() ? it : s[i].back() + it);
  }
  dfs(-1), cout << ans << "\n";
  return 0;
}