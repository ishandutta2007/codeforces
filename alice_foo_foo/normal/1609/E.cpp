#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5, INF = 0x3f3f3f3f;

inline int get(int x, int i) {
  return (x >> i) & 1;
}

inline void setb(int &x, int i) {
  x |= (1 << i);
}

struct Node {
  int v[13];
} V[3], p[maxN << 2];

vector<int> useful;
int go[13][13], id[32];

Node merge(Node a, Node b) {
  Node ans;
  memset(ans.v, 0x3f, sizeof(ans.v));
  for (int i = 0; i < 13; i++) {
    if (a.v[i] == INF) continue;
    for (int j = 0; j < 13; j++) {
      if (b.v[j] == INF) continue;
      if (go[i][j] == -1) continue;
      ans.v[go[i][j]] = min(ans.v[go[i][j]], a.v[i] + b.v[j]);
    }
  }
  return ans;
}

char c[maxN];
int n, q;

void update(int u) {
  p[u] = merge(p[u << 1], p[u << 1 | 1]);
}

void build(int u, int l, int r) {
  if (l == r) {
    p[u] = V[c[l] - 'a'];
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  update(u);
}

void modify(int u, int l, int r, int x) {
  if (l == r) {
    p[u] = V[c[x] - 'a'];
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= x) modify(u << 1, l, mid, x);
  else modify(u << 1 | 1, mid + 1, r, x);
  update(u);
}

int main() {
  for (int i = 0; i < 32; i++) {
    if (get(i, 3) && (!get(i, 0) || !get(i, 1))) continue;
    if (get(i, 4) && (!get(i, 1) || !get(i, 2))) continue;
    useful.push_back(i); id[i] = (int)useful.size() - 1;
  }
  for (auto i : useful) for (auto j : useful) {
    if (get(i, 3) && get(j, 2)) {
      go[id[i]][id[j]] = -1;
      continue;
    }
    if (get(i, 0) && get(j, 4)) {
      go[id[i]][id[j]] = -1;
      continue;
    }
    int now = 0;
    for (int k = 0; k <= 2; k++) {
      if (get(i, k) || get(j, k)) setb(now, k);
    }
    if (get(i, 3) || get(j, 3) || (get(i, 0) && get(j, 1))) setb(now, 3);
    if (get(i, 4) || get(j, 4) || (get(i, 1) && get(j, 2))) setb(now, 4);
    go[id[i]][id[j]] = id[now];
  }
  for (int i = 0; i <= 2; i++) {
    Node x;
    memset(x.v, 0x3f, sizeof(x.v));
    x.v[0] = 1; x.v[id[1 << i]] = 0; V[i] = x;
  }
  scanf("%d%d", &n, &q);
  scanf("%s", c + 1);
  build(1, 1, n);
  while (q--) {
    int x; scanf("%d", &x);
    char foo = getchar();
    while (foo < 'a' || foo > 'c') foo = getchar();
    c[x] = foo; modify(1, 1, n, x);
    int ans = INF;
    for (int i = 0; i < 13; i++) ans = min(ans, p[1].v[i]);
    printf("%d\n", ans);
  }
  return 0;
}