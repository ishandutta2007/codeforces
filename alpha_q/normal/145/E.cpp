#include <bits/stdc++.h>

using namespace std;

struct node {
  int zero, one;
  int inc, dec;
  node () {} 
  node (int _z, int _o, int _i, int _d) {
    zero = _z, one = _o, inc = _i, dec = _d;
  }
};

const int N = 1000005;

int n, m;
node t[4 * N];
int lazy[4 * N];
char s[N], cmd[10];

node merge (node a, node b) {
  node c;
  c.zero = a.zero + b.zero;
  c.one = a.one + b.one;
  c.inc = max(a.zero + b.inc, a.inc + b.one);
  c.dec = max(a.dec + b.zero, a.one + b.dec);
  return c;
}

void propagate (int u, int b, int e) {
  swap(t[u].zero, t[u].one);
  swap(t[u].inc, t[u].dec);
  if (b != e) {
    lazy[u << 1] ^= 1;
    lazy[u << 1 | 1] ^= 1;
  }
  lazy[u] = 0;
}

void init (int u, int b, int e) {
  if (b == e) {
    if (s[b] == '4') t[u] = node(1, 0, 1, 1);
    else t[u] = node(0, 1, 1, 1);
    return;
  }
  int mid = b + e >> 1;
  init(u << 1, b, mid);
  init(u << 1 | 1, mid + 1, e);
  t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

void update (int u, int b, int e, int l, int r) {
  if (lazy[u]) propagate(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lazy[u] = 1;
    propagate(u, b, e);
    return;
  }
  int mid = b + e >> 1;
  update(u << 1, b, mid, l, r);
  update(u << 1 | 1, mid + 1, e, l, r);
  t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

int main() {
  scanf("%d %d %s", &n, &m, s + 1);
  init(1, 1, n);
  while (m--) {
    scanf("%s", cmd);
    if (cmd[0] == 'c') {
      if (lazy[1]) propagate(1, 1, n);
      printf("%d\n", t[1].inc);
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      update(1, 1, n, l, r);
    }
  }
  return 0;
}