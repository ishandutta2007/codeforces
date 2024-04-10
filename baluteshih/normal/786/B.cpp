#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back

const ll INF = 1e18;
vector<pll> G[300005];
int seg[400005][2], cnt, num[100005];
ll dis[300005];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void edge(int a, int b, int w) {
  G[a].pb(pll(w, b));
}

void build(int l, int r, int rt) {
  if(l == r) {
    seg[rt][0] = seg[rt][1] = cnt;
    num[l] = cnt++;
    return;
  }
  int m = l + r >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  seg[rt][0] = cnt++;
  seg[rt][1] = cnt++;
  edge(seg[rt << 1][0], seg[rt][0], 0);
  edge(seg[rt << 1 | 1][0], seg[rt][0], 0);
  edge(seg[rt][1], seg[rt << 1][1], 0);
  edge(seg[rt][1], seg[rt << 1 | 1][1], 0);
}

void add_edge(int L, int R, int l, int r, int rt, int v, int w, int type) {
  if(L <= l && R >= r) {
    if(type == 0)
      edge(num[v], seg[rt][1], w);
    else
      edge(seg[rt][0], num[v], w);
    return;
  }
  int m = l + r >> 1;
  if(L <= m)
    add_edge(L, R, l, m, rt << 1, v, w, type);
  if(R > m)
    add_edge(L, R, m + 1, r, rt << 1 | 1, v, w, type);
}

int main() {
  int n, q, s, t, v, l, r, w;
  cin >> n >> q >> s;
  build(1, n, 1);
  fill(dis, dis + cnt, INF);
  while(q--) {
    cin >> t >> v >> l;
    if(t == 1)
      r = l;
    else
      cin >> r;
    cin >> w;
    if(t <= 2)
      add_edge(l, r, 1, n, 1, v, w, 0);
    else
      add_edge(l, r, 1, n, 1, v, w, 1);
  }
  dis[num[s]] = 0;
  pq.push(pll(0, num[s]));
  while(!pq.empty()) {
    pll u = pq.top();
    pq.pop();
    if(dis[u.second] != u.first)
      continue;
    for(pll e: G[u.second])
      if(dis[e.second] > u.first + e.first) {
        dis[e.second] = u.first + e.first;
        pq.push(pll(dis[e.second], e.second));
      }
  }
  for(int i = 1; i <= n; ++i)
    if(dis[num[i]] == INF)
      cout << "-1" << " \n"[i==n];
    else
      cout << dis[num[i]] << " \n"[i==n];
}