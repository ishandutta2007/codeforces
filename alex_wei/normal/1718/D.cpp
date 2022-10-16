#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5 + 5;
constexpr int V = 1e6 + 5;
constexpr int inf = 1e9;
int n, q, flag, p[N], a[N], s[N];
int stc[N], ls[N], rs[N], f[N];
struct limit {int l, r;};
vector<limit> lim;
void dfs1(int id) {
  if(!id) return;
  dfs1(ls[id]), dfs1(rs[id]);
  if(a[id]) f[id] = a[id] + 1;
  else f[id] = max(1, max(f[ls[id]], f[rs[id]]));
}
void dfs2(int id, int up) {
  if(!id) return;
  if(!a[id]) lim.push_back({f[id], up});
  else flag |= f[id] > up, up = a[id] - 1;
  dfs2(ls[id], up), dfs2(rs[id], up);
}
void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> p[i], ls[i] = rs[i] = 0;
  for(int i = 1, top = 0; i <= n; i++) {
    while(top && p[stc[top]] < p[i]) ls[i] = stc[top--];
    rs[stc[top]] = i, stc[++top] = i;
  }
  ls[0] = rs[0] = flag = 0;
  int k = 0;
  for(int i = 1; i <= n; i++) cin >> a[i], k += !a[i];
  dfs1(stc[1]), lim.clear(), dfs2(stc[1], V);
  set<int> st;
  for(int i = 1; i < k; i++) cin >> s[i], st.insert(s[i]);
  int L = 0, R = inf;
  sort(lim.begin(), lim.end(), [&](limit x, limit y) {return x.l > y.l;});
  for(auto it : lim) {
    int l = it.l, r = it.r;
    auto pt = st.upper_bound(r);
    if(pt == st.begin() || *--pt < l) {
      if(L) {flag = 1; break;}
      L = l;
    }
    else st.erase(pt);
  }
  sort(lim.begin(), lim.end(), [&](limit x, limit y) {return x.r < y.r;});
  st.clear();
  for(int i = 1; i < k; i++) st.insert(s[i]);
  for(auto it : lim) {
    int l = it.l, r = it.r;
    auto pt = st.lower_bound(l);
    if(pt == st.end() || *pt > r) {
      if(R < inf) {flag = 1; break;}
      R = r;
    }
    else st.erase(pt);
  }
  for(int i = 1; i <= q; i++) {
    int d;
    cin >> d;
    puts(!flag && L <= d && d <= R ? "YES" : "NO");
  }
}
int main() {
  ios::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}