#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef unsigned long long ull;

const int N = 200005;

struct hsh {
  ull sum, prod, xxor;
  hsh () {
    sum = xxor = 0, prod = 1;
  }
  hsh (ull sm, ull pr, ull xx) {
    sum = sm, prod = pr, xxor = xx;
  }
  bool operator == (const hsh &rhs) const {
    return sum == rhs.sum and prod == rhs.prod and xxor == rhs.xxor;
  }
};

int n, par[N], childs[N], d[N], ord[N];
vector <int> g[N], lay[N];
hsh h[N], tr[N + N];
pair <int, int> ran[N];

inline hsh add (hsh x, ull v) {
  return hsh(x.sum + v, x.prod * v, x.xxor ^ v);
}

inline hsh add (hsh x, hsh y) {
  return hsh(x.sum + y.sum, x.prod * y.prod, x.xxor ^ y.xxor);
}

void go (int u, int from = -1, int dep = 0) {
  d[u] = dep, par[u] = from;
  for (int v : g[u]) {
    if (v == from) continue;
    h[u] = add(h[u], v);
    ++childs[u];
    go(v, u, dep + 1);
  }
}

hsh query (int l, int r) {
  hsh ans = hsh(0, 1, 0);
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = add(ans, tr[l++]);
    if (r & 1) ans = add(ans, tr[--r]);
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", ord + i);
    tr[n + i] = hsh(ord[i], ord[i], ord[i]);
  }
  if (ord[0] != 1) {
    puts("No");
    return 0;
  }
  for (int i = n - 1; i > 0; --i) {
    tr[i] = add(tr[i << 1], tr[i << 1 | 1]); 
  }
  go(1);
  int ptr = 1;
  for (int i = 0; i < n; ++i) {
    int u = ord[i], sz = childs[u];
    if (h[u] == query(ptr, ptr + sz)) {
      ptr += sz;
      continue;
    }
    puts("No");
    return 0;
  }
  puts("Yes");
  return 0;
}