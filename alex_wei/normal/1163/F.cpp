#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
const int N = 2e5 + 5;
int n, m, q;
int u[N], v[N], w[N];
vector<int> P;
struct Segtree {
  long long val[N << 2];
  Segtree() {memset(val, 0x3f, sizeof(val));}
  void modify(int l, int r, int ql, int qr, int x, long long v) {
    if(ql > qr) return;
    if(ql <= l && r <= qr) return val[x] = min(val[x], v), void();
    int m = l + r >> 1;
    if(ql <= m) modify(l, m, ql, qr, x << 1, v);
    if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
  }
  long long query(int p) {
    int l = 1, r = P.size(), x = 1;
    long long ans = val[1];
    while(l < r) {
      int m = l + r >> 1;
      if(p <= m) r = m, x <<= 1;
      else l = m + 1, x = x << 1 | 1;
      ans = min(ans, val[x]);
    }
    return ans; // add this line
  }
} tr;
struct edge {
  int v, w, id;
};
vector<edge> e[N];
int index[N], tag[N];
int pr[N], su[N], eid[N];
long long pre[N], suf[N];
void dijkstra() {
  priority_queue<pll, vector<pll>, greater<pll>> q;
  memset(pre, 0x3f, sizeof(pre));
  q.push({pre[1] = 0, pr[1] = 1});
  while(!q.empty()) {
    pll t = q.top();
    q.pop();
    int id = t.second;
    if(pre[id] != t.first) continue;
    for(edge _ : e[id]) {
      int it = _.v;
      long long d = t.first + _.w;
      if(d < pre[it]) {
        q.push({pre[it] = d, it});
        pr[it] = id, eid[it] = _.id;
      }
    }
  }
  for(int i = n; i != 1; i = pr[i]) P.push_back(i);
  for(int it : P) pr[it] = it;
  reverse(P.begin(), P.end());
  for(int i = 1; i <= P.size(); i++) index[P[i - 1]] = i, tag[eid[P[i - 1]]] = i;
  function<int(int)> findp = [&](int id) {return pr[id] == id ? id : pr[id] = findp(pr[id]);};
  memset(suf, 0x3f, sizeof(suf));
  for(int i = 1; i <= n; i++) {
    pr[i] = findp(i);
    if(i == pr[i]) q.push({suf[i] = pre[n] - pre[i], su[i] = i});
  }
  while(!q.empty()) {
    pll t = q.top();
    q.pop();
    int id = t.second;
    if(suf[id] != t.first) continue;
    for(edge _ : e[id]) {
      int it = _.v;
      long long d = t.first + _.w;
      if(d < suf[it]) {
        assert(su[it] != it);
        q.push({suf[it] = d, it});
        su[it] = id;
      }
    }
  }
  function<int(int)> finds = [&](int id) {return su[id] == id ? id : su[id] = finds(su[id]);};
  for(int i = 1; i <= n; i++) su[i] = finds(i);
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  cin >> n >> m >> q;
  for(int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    e[u[i]].push_back({v[i], w[i], i});
    e[v[i]].push_back({u[i], w[i], i});
  }
  dijkstra();
  for(int i = 1; i <= n; i++)
    for(edge _ : e[i]) {
      if(tag[_.id]) continue;
      int it = _.v;
      long long val = pre[i] + suf[it] + _.w;
      tr.modify(1, P.size(), index[pr[i]] + 1, index[su[it]], 1, val);
    }
  for(int i = 1; i <= q; i++) {
    int t, x;
    scanf("%d%d", &t, &x);
    long long ans = 1e18;
    if(tag[t]) {
      ans = min(ans, pre[n] + x - w[t]);
      ans = min(ans, tr.query(tag[t]));
    }
    else {
      ans = min(ans, pre[n]);
      ans = min(ans, pre[u[t]] + x + suf[v[t]]); // i -> t
      ans = min(ans, pre[v[t]] + x + suf[u[t]]); // i -> t
    }
    printf("%lld\n", ans);
  }
  return 0;
}
/*
2022/5/24
*/