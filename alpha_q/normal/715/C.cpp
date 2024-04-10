#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int phi (int x) {
  int ret = x;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      ret /= i, ret *= (i - 1);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) ret /= x, ret *= (x - 1);
  return ret;
}

int bigMod (int a, int e, int mod) {
  int ret = 1;
  while (e) {
    if (e & 1) ret = (long long) ret * a % mod;
    a = (long long) a * a % mod, e >>= 1;
  }
  return ret;
}

const int N = 100010;

long long ans;
bitset <N> bad;
vector <int> g[N];
gp_hash_table <int, int> freq;
int n, m, U[N], V[N], W[N], inv, curSize, sub[N], ten[N];

void traverse (int u, int par = -1) {
  sub[u] = 1;
  for (int e : g[u]) {
    int v = U[e] ^ u ^ V[e], w = W[e];
    if (v == par or bad[v]) continue;
    traverse(v, u); sub[u] += sub[v];
  }
}

int getCentroid (int u, int par = -1) {
  for (int e : g[u]) {
    int v = U[e] ^ u ^ V[e], w = W[e];
    if (v == par or bad[v]) continue;
    if (sub[v] > curSize / 2) return getCentroid(v, u);
  }
  return u;
}

void updateAns (int u, int val, int par, int flag = 1, int far = 1) {
  if (flag and val == 0) ++ans;
  int req = (long long) (m - val) * bigMod(inv, far, m) % m;
  ans += freq[req];
  for (int e : g[u]) {
    int v = U[e] ^ u ^ V[e], w = W[e];
    if (v == par or bad[v]) continue;
    updateAns(v, (10LL * val + w) % m, u, flag, far + 1);
  }
}

void updateTree (int u, int val, int par, int flag = 1, int far = 1) {
  if (flag and val == 0) ++ans;
  ++freq[val];
  for (int e : g[u]) {
    int v = U[e] ^ u ^ V[e], w = W[e];
    if (v == par or bad[v]) continue;
    updateTree(v, ((long long) ten[far] * w + val) % m, u, flag, far + 1);
  }
}

void decompose (int u = 1) {
  traverse(u);
  curSize = sub[u];
  int cen = getCentroid(u);
  freq.clear();
  for (int e : g[cen]) {
    int v = U[e] ^ cen ^ V[e], w = W[e] % m;
    if (bad[v]) continue;
    updateAns(v, w, cen);
    updateTree(v, w, cen);
  }
  reverse(g[cen].begin(), g[cen].end());
  freq.clear();
  for (int e : g[cen]) {
    int v = U[e] ^ cen ^ V[e], w = W[e] % m;
    if (bad[v]) continue;
    updateAns(v, w, cen, 0); 
    updateTree(v, w, cen, 0);
  }
  bad[cen] = 1;
  for (int e : g[cen]) {
    int v = U[e] ^ cen ^ V[e];
    if (bad[v]) continue;
    decompose(v);
  }
}

int main() {
  cin >> n >> m;
  ten[0] = 1;
  for (int i = 1; i < N; ++i) ten[i] = 10LL * ten[i - 1] % m;
  inv = bigMod(10, phi(m) - 1, m);
  for (int i = 1; i < n; ++i) {
    scanf("%d %d %d", U + i, V + i, W + i);
    ++U[i], ++V[i];
    g[U[i]].emplace_back(i), g[V[i]].emplace_back(i);
  }
  decompose();
  cout << ans << '\n';
  return 0;
}