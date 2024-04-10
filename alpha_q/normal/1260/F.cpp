#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const int MOD = 1e9 + 7;

inline int add (int x, int y) {
  x += y; if (x >= MOD) x -= MOD; return x;
}

inline int subtract (int x, int y) {
  x -= y; if (x < 0) x += MOD; return x;
}

inline int mul (int x, int y) {
  return (ll) x * y % MOD;
}

bitset <N> bad;
vector <int> g[N];
pair <int, int> events[N];
int n, U[N], V[N], curSize, sub[N];
int who[N], subTot[2][N], sz, ids[N], ans, h[N];
int inv[N], globalRoot, len[N], lt[N], rt[N], tot = 1;

void traverse (int u, int par = -1, int far = 0) {
  sub[u] = 1, who[u] = globalRoot, ids[sz++] = u, h[u] = far;
  for (int e : g[u]) {
    int v = U[e] ^ u ^ V[e];
    if (v == par or bad[v]) continue;
    traverse(v, u, far + 1); sub[u] += sub[v];
  }
}

int getCentroid (int u, int par = -1) {
  for (int e : g[u]) {
    int v = U[e] ^ u ^ V[e];
    if (v == par or bad[v]) continue;
    if (sub[v] > curSize / 2) return getCentroid(v, u);
  }
  return u;
}

void decompose (int u = 1) {
  sz = 0, traverse(u);
  curSize = sub[u];
  int cen = getCentroid(u);
  sz = 1, ids[0] = cen, h[cen] = 0;
  for (int e : g[cen]) {
    int v = U[e] ^ cen ^ V[e];
    if (bad[v]) continue;
    globalRoot = v, subTot[0][v] = subTot[1][v] = 0;
    traverse(v, cen, 1);
  }
  who[cen] = cen, subTot[0][cen] = subTot[1][cen] = 0;
  for (int i = 0; i < sz; ++i) {
    events[i << 1] = make_pair(lt[ids[i]], ids[i]);
    events[i << 1 | 1] = make_pair(rt[ids[i]] + 1, -ids[i]); 
  }
  sort(events, events + sz + sz);
  int globalTot[2] = {0, 0}, last = 0, tmp = 0;
  for (int i = 0; i < sz + sz; last = events[i++].first) {
    int cur = events[i].first - last, at = events[i].second, val = len[abs(at)];
    if (at < 0) {
      at = -at;
      if (val) val = MOD - val;
    }
    ans = add(ans, mul(cur, tmp));
    globalTot[0] = add(globalTot[0], val);
    globalTot[1] = add(globalTot[1], mul(h[at], val));
    subTot[0][who[at]] = add(subTot[0][who[at]], val);
    subTot[1][who[at]] = add(subTot[1][who[at]], mul(h[at], val));
    tmp = add(tmp, mul(mul(val, h[at]), subtract(globalTot[0], subTot[0][who[at]])));
    tmp = add(tmp, mul(val, subtract(globalTot[1], subTot[1][who[at]])));
  }
  bad[cen] = 1;
  for (int e : g[cen]) {
    int v = U[e] ^ cen ^ V[e];
    if (bad[v]) continue;
    decompose(v);
  }
}

int main() {
  inv[1] = 1;
  for (int i = 2; i < N; ++i) {
    inv[i] = mul(MOD / i, inv[MOD % i]);
    if (inv[i]) inv[i] = MOD - inv[i];
  }
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", lt + i, rt + i);
    len[i] = rt[i] - lt[i] + 1;
    tot = mul(tot, len[i]);
    len[i] = inv[len[i]];
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", U + i, V + i);
    g[U[i]].emplace_back(i);
    g[V[i]].emplace_back(i);
  }
  decompose();
  cout << mul(ans, tot) << '\n';
  return 0;
}