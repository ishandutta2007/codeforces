#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

struct edge {
  int u, v, w_base;
  double w = 0;

  bool operator<(const edge& rhs) const {
    return w < rhs.w;
  }
};

struct dsu_t {
  vector<int> p;

  dsu_t(int n): p(n) {
    iota(all(p), 0);
  }

  int get(int v) { return v == p[v] ? v : (p[v] = get(p[v])); }

  bool unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) { return false; }
    p[u] = v;
    return true;
  }
};

struct Sol {
  li sum{};
  li coef{};

  li eval(int x) const {
    return sum + x * coef;
  }
};

void solve(bool read) {
  int n, m;
  cin >> n >> m;

  vector<edge> edges;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    edges.push_back(edge{u, v, w, (double)w});
  }

  vector<int> key_w;
  key_w.push_back(0);
  key_w.push_back(2e8);

  for (int i = 0; i < edges.size(); ++i) {
    key_w.push_back(edges[i].w_base);
    for (int j = 0; j < edges.size(); ++j) {
      key_w.push_back((edges[i].w_base + edges[j].w_base + 1) / 2);
    }
  }
  sort(all(key_w));
  key_w.erase(unique(all(key_w)), key_w.end());

  vector<Sol> sols;
  for (int x : key_w) {
    for (auto& it : edges) {
      it.w = abs(it.w_base - (x + 0.1));
    }
    sort(all(edges));

    Sol sol;

    dsu_t dsu(n);
    for (auto it : edges) {
      if (dsu.unite(it.u, it.v)) {
        // x - w
        int sign = (x >= it.w_base) ? 1 : -1;
        sol.coef += sign;
        sol.sum += it.w_base * (-sign);
      }
    }

    sols.push_back(sol);
  }

  int p, k;
  li a, b, c;
  cin >> p >> k >> a >> b >> c;

  auto query = [&](int x) {
    int i = prev(upper_bound(all(key_w), x)) - key_w.begin();
    li res = sols[i].eval(x);
    //cout << "query: " << x << " result: " << res << "\n";
    return res;
  };

  li ans = 0;

  li last_q = 0;
  for (int i = 0; i < p; ++i) {
    int q;
    if (true) {
      cin >> q;
    } else {
      q = i;
    }
    ans ^= query(q);
    last_q = q;
  }
  for (int i = p; i < k; ++i) {
    last_q = (last_q * a + b) % c;
    ans ^= query(last_q);
  }

#if 0
  for (int x = 0; x < 1000; ++x) {
    li res = query(x);

    for (auto& it : edges) {
      it.w = abs(it.w_base - x);
    }
    sort(all(edges));

    Sol sol;

    dsu_t dsu(n);
    li expected = 0;
    for (auto it : edges) {
      if (dsu.unite(it.u, it.v)) {
        expected += it.w;
      }
    }

    if (res != expected) {
      cout << "res: " << res << " expected: " << expected << " query: " << x << endl;
      abort();
    }
  }
#endif

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  //cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //solve(false);

  return 0;
}