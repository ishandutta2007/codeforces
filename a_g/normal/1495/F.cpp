#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1495/submission/109740936
const int N = 2e5+2;
const int K = 18;
int p[N], par[N][K], freq[N], depth[N];
bool on[N];
long long c[N], csum[N];
set<int> s;
long long ans = 0;

int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  int d = depth[v]-depth[u];
  for (int k = K-1; k >= 0; k--) {
    if ((d>>k)&1) {
      v = par[v][k];
    }
  }
  if (u == v) return u;
  for (int k = K-1; k >= 0; k--) {
    if (par[u][k] != par[v][k]) {
      u = par[u][k];
      v = par[v][k];
    }
  }
  return par[u][0];
}

void add(int v) {
  auto it = s.lower_bound(v);
  int l = *prev(it);
  if (it == s.end()) {
    ans += csum[v]-csum[lca(l, v)];
  }
  else {
    int r = *it;
    ans += csum[v]-csum[lca(l, v)]-csum[lca(r, v)]+csum[lca(l, r)];
  }
  s.insert(v);
}

void sub(int v) {
  s.erase(v);
  auto it = s.lower_bound(v);
  int l = *prev(it);
  if (it == s.end()) {
    ans -= csum[v]-csum[lca(l, v)];
  }
  else {
    int r = *it;
    ans -= csum[v]-csum[lca(l, v)]-csum[lca(r, v)]+csum[lca(l, r)];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  p[0] = n+1;
  vector<int> stk(1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    while (p[stk.back()] < p[i]) stk.pop_back();
    par[i][0] = stk.back();
    depth[i] = depth[stk.back()]+1;
    for (int j = 1; j < K; j++) {
      par[i][j] = par[par[i][j-1]][j-1];
    }
    stk.emplace_back(i);
  }
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    c[i] += a;
  }
  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    c[i] -= b;
    c[par[i][0]] += b;
  }
  for (int i = n; i >= 1; i--) {
    if (c[i] < 0) {
      c[par[i][0]] += c[i];
      c[i] = 0;
    }
  }
  for (int i = 0; i <= n; i++) {
    csum[i] = c[i]+csum[par[i][0]];
  }

  freq[0] = 1;
  s.insert(0);
  ans = c[0];
  // if active verices are v1, v2, v3, ...
  // then the answer is csum[v1]-csum[lca(v1, v2)]+csum[v2]-csum[lca(v2, v3)]+...?

  while (q--) {
    int x;
    cin >> x;
    int v = par[x][0];
    if (!on[x]) {
      if (!freq[par[x][0]]++) {
        add(par[x][0]);
      }
      on[x] = 1;
    }
    else if (on[x]) {
      if (!--freq[par[x][0]]) {
        sub(par[x][0]);
      }
      on[x] = 0;
    }
    cout << ans << '\n';
  }
}