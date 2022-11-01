#include <bits/stdc++.h>

using namespace std;

const int N = 800005;

struct node {
  int mn, occ;
  node () {
    mn = occ = 0;
  } 
  node (int _m, int _o) {
    mn = _m, occ = _o;
  }
};

vector <int> v;
int n, m, l[N], r[N];
node t[4 * N];
int lazy[4 * N];

node merge (node a, node b) {
  node c;
  if (a.mn < b.mn) {
    c = a;
  } else if (a.mn > b.mn) {
    c = b;
  } else {
    c = a, c.occ += b.occ;
  }
  return c;
}

void propagate (int u, int b, int e) {
  t[u].mn += lazy[u];
  if (b != e) {
    lazy[u << 1] += lazy[u];
    lazy[u << 1 | 1] += lazy[u];
  }
  lazy[u] = 0;
}

void init (int u, int b, int e) {
  if (b == e) {
    t[u].mn = 0;
    t[u].occ = 1;
    return;
  }
  int mid = b + e >> 1;
  init(u << 1, b, mid);
  init(u << 1 | 1, mid + 1, e);
  t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

void update (int u, int b, int e, int l, int r, int v) {
  if (lazy[u] != 0) propagate(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lazy[u] += v;
    propagate(u, b, e);
    return;
  }
  int mid = b + e >> 1;
  update(u << 1, b, mid, l, r, v);
  update(u << 1 | 1, mid + 1, e, l, r, v);
  t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

int count (void) {
  if (lazy[1] != 0) propagate(1, 1, m);
  return t[1].mn == 0 ? m - t[1].occ : m;
}

map <int, int> mp;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", l + i, r + i);
    v.push_back(l[i]), v.push_back(r[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int it = 1;
  mp[v[0]] = 1;
  for (int i = 1; i < v.size(); ++i) {
    ++it;
    if (v[i - 1] + 1 < v[i]) {
      ++it;
    }
    mp[v[i]] = it;
  }
  for (int i = 1; i <= n; ++i) {
    l[i] = mp[l[i]], r[i] = mp[r[i]];
    m = max(m, l[i]), m = max(m, r[i]);
  }
  init(1, 1, m);
  for (int i = 1; i <= n; ++i) {
    update(1, 1, m, l[i], r[i], 1);
  }
  int tot = count();
  for (int i = 1; i <= n; ++i) {
    update(1, 1, m, l[i], r[i], -1);
    int now = count();
    if (now == tot) {
      printf("%d\n", i);
      return 0;
    }
    update(1, 1, m, l[i], r[i], 1);
  }
  puts("-1");
  return 0;
}