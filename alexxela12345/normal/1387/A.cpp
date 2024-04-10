#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long double ldb;

const ldb EPS = 1e-6;

int n, m;
vector<vector<pair<int, int>>> g;

vector<int> used;

struct Poly {
  int k, b;

  Poly() {}
  Poly(int k, int b) : k(k), b(b) {}
};

Poly operator-(int a, Poly p) {
  return Poly(-p.k, a - p.b);
}

Poly operator+(Poly a, Poly b) {
  return Poly(a.k + b.k, a.b + b.b);
}

Poly X = Poly(1, 0);

vector<Poly> p;
vector<ldb> ans;

bool any;
ldb sol;

void solution(Poly p) {
  ldb k = p.k;
  ldb b = p.b;
  if (p.k == 0) {
    if (p.b != 0) {
      any = false;
    }
  } else {
    any = false;
    sol = -b / k;
  }
}

void dfs(int v) {
  used[v] = 1;
  for (auto pp : g[v]) {
    int u = pp.first;
    int c = pp.second;
    if (!used[u]) {
      p[u] = c - p[v];
      dfs(u);
    } else {
      solution(c - (p[v] + p[u]));
    }
  }
}

void dfs2(int v) {
  used[v] = 2;
  ans[v] = p[v].k * sol + p[v].b;
  for (auto pp : g[v]) {
    int u = pp.first;
    if (used[u] != 2) {
      dfs2(u);
    }
  }
}

vector<int> ks;

void dfs3(int v) {
  used[v] = 3;
  if (p[v].k == -1) {
    ks.push_back(p[v].b);
  } else if (p[v].k == 1) {
    ks.push_back(-p[v].b);
  } else {
    assert(false);
  }
  for (auto pp : g[v]) {
    int u = pp.first;
    if (used[u] != 3) {
      dfs3(u);
    }
  }
}
    

signed main() {
  cout.precision(20);
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  used.assign(n, 0);
  p.resize(n);
  ans.resize(n);
  bool bad = false;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      p[i] = X;
      any = true;
      sol = 0;
      dfs(i);
      if (any) {
	ks.clear();
	dfs3(i);
        sort(ks.begin(), ks.end());
	if (ks.empty()) {
	  sol = 0;
	} else {
	  sol = ks[ks.size() / 2];
	}
      }
      dfs2(i);
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (auto pp : g[i]) {
      int j = pp.first;
      ldb c = pp.second;
      if (abs(ans[i] + ans[j] - c) > 1e-5) {
	ok = false;
	break;
      }
    }
  }
  if (ok && !bad) {
    cout << "YES" << endl;
    for (auto &el : ans) {
      cout << el << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}