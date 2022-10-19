#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int INF = 1e9;
const int N = 105;
vector<int> G[N];
int fact[N];
int invfact[N];

struct pt {
  int x, y;
};

int dist(pt& a, pt& b) {
  return abs(a.x-b.x) + abs(a.y-b.y);
}

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  int n;
  cin >> n;
  vector<pt> p(n);
  for (pt& z: p) {
    cin >> z.x >> z.y;
  }

  vector<int> md(n, INF);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      md[i] = min(md[i], dist(p[i], p[j]));
    }
  }
  
  vector<bool> bad(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist(p[i], p[j]) == md[i]) {
        G[i].push_back(j);
        if (md[j] != md[i]) bad[i] = 1;
      }
    }
  }

  vector<int> sorted_md = md;
  sort(sorted_md.begin(), sorted_md.end());
  sorted_md.resize(unique(sorted_md.begin(), sorted_md.end())-sorted_md.begin());

  vector<int> comp(n+1);
  comp[0] = 1;
  auto multiply_with = [&] (vector<int> v) {
    vector<int> ncomp(n+1);
    for (int k: v) {
      for (int j = 0; j+k <= n; j++) {
        ncomp[j+k] = (ncomp[j+k]+comp[j])% MOD;
      }
    }
    swap(comp, ncomp);
  };

  for (int d: sorted_md) {
    vector<int> vtxs;
    for (int i = 0; i < n; i++) {
      if (md[i] == d) {
        vtxs.push_back(i);
      }
    }

    vector<bool> vis(n);
    vector<int> c;
    function<void(int)> dfs = [&] (int v) {
      if (vis[v]) return;
      vis[v] = 1;
      c.push_back(v);
      for (int u: G[v]) {
        if (md[u] == d) {
          dfs(u);
        }
      }
    };

    for (int v: vtxs) {
      if (vis[v]) continue;
      dfs(v);
      bool good = 1;
      for (int u: c) {
        if (bad[u]) good = 0;
      }
      int k = c.size();
      for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
          if (dist(p[c[i]], p[c[j]]) != d) {
            good = 0;
          }
        }
      }
      if (good) multiply_with({1, k});
      else multiply_with({k});

      c.clear();
    }
  }
  
  int ans = 0;
  for (int m = 1; m <= n; m++) {
    //cout << comp[m] << ' ';
    ans += 1LL * comp[m] * (1LL * fact[n] * invfact[n-m] % MOD) % MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
}