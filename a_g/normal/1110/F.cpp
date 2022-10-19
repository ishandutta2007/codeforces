#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const long long INF = 1e18;
vector<pair<int, int>> children[N];
int R[N], n;
long long ans[N], dist[N];

long long offset = 0;
long long mn[4*N], lazy[4*N];

struct query_by_vtx {
  int l, r, i;
};

void combine(int v) {
  mn[v] = min(mn[2*v], mn[2*v+1]);
}

void init(int v, int tl, int tr) {
  if (tl == tr) {
    mn[v] = dist[tl];
    return;
  }
  int tm = (tl+tr)/2;
  init(2*v, tl, tm);
  init(2*v+1, tm+1, tr);
  combine(v);
}

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    if (tl != tr) {
      lazy[2*v] += lazy[v];
      lazy[2*v+1] += lazy[v];
    }
    mn[v] += lazy[v];
    lazy[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, int x) {
  if (tl >= l && tr <= r) {
    lazy[v] += x;
  }

  push(v, tl, tr);

  if (r < tl || tr < l) {
    return;
  }

  if (tl >= l && tr <= r) {
    return;
  }

  int tm = (tl+tr)/2;
  add(2*v, tl, tm, l, r, x);
  add(2*v+1, tm+1, tr, l, r, x);
  combine(v);
}

long long query(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);

  if (r < tl || tr < l) return INF;

  if (tl >= l && tr <= r) {
    return mn[v];
  }
  
  int tm = (tl+tr)/2;
  long long ans = min(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
  combine(v);
  return ans;
}

vector<query_by_vtx> queries[N];

void dfs1(int v) {
  if (children[v].size()) {
    for (auto& [u, w]: children[v]) {
      dist[u] = dist[v]+w;
      dfs1(u);
    }
    R[v] = R[children[v].back().first];
    dist[v] = INF;
  }
  else {
    R[v] = v;
  }
}

void dfs2(int v) {
  for (query_by_vtx& q: queries[v]) {
    ans[q.i] = offset+query(1, 1, n, q.l, q.r);
  }
  for (auto& [u, w]: children[v]) {
    offset += w;
    add(1, 1, n, u, R[u], -2*w);
    dfs2(u);
    offset -= w;
    add(1, 1, n, u, R[u], 2*w);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int p, w;
    cin >> p >> w;
    children[p].emplace_back(i, w);
  }
  dfs1(1);
  init(1, 1, n);

  for (int i = 0; i < q; i++) {
    int v, l, r;
    cin >> v >> l >> r;
    queries[v].push_back(query_by_vtx{l, r, i});
  }
  dfs2(1);

  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}