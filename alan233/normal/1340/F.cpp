// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }

namespace IO {
  const int SIZE = 1 << 16;
  char ibuf[SIZE]; int iS, iT;
  char obuf[SIZE]; int oT;
  inline char gc() {
    if (iS == iT)
      iS = 0, iT = fread(ibuf, 1, SIZE, stdin);
    return iS == iT ? EOF : ibuf[iS++];
  }
  inline void pc(char c) {
    obuf[oT++] = c;
    if (oT == SIZE)
      fwrite(obuf, 1, SIZE, stdout), oT = 0;
  }
  inline int read() {
    int x = 0, f = 0;
    char c = gc();
    while (!isdigit(c)) f |= c == '-', c = gc();
    while (isdigit(c)) x = 10 * x + c - '0', c = gc();
    return f ? -x : x; 
  }
  inline void print(int64_t x) {
    static char bufn[64];
    int len = 0;
    if (x < 0) x = -x, pc('-');
    while (x >= 10) bufn[len++] = x % 10 + '0', x /= 10;
    bufn[len++] = x + '0';
    while (len--) pc(bufn[len]);
  }
  inline void print(int64_t x, char ch) {
    print(x), pc(ch);
  }
  struct ff {
    ~ff() {
      if (oT)
        fwrite(obuf, 1, oT, stdout);
    }
  } flusher;
}
using namespace IO;

const int N = 100005;

int a[N], n, q;

const int mod = 998244853;
const int base1 = 117;
const int base2 = 137;

int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}

int pw1[N], pw2[N], ipw1[N], ipw2[N];
void init(int n) {
  pw1[0] = ipw1[0] = pw2[0] = ipw2[0] = 1;
  pw1[1] = base1, ipw1[1] = qpow(base1);
  pw2[1] = base2, ipw2[1] = qpow(base2);
  rep(i, 2, n) {
    pw1[i] = 1ll * pw1[i - 1] * pw1[1] % mod;
    ipw1[i] = 1ll * ipw1[i - 1] * ipw1[1] % mod;
    pw2[i] = 1ll * pw2[i - 1] * pw2[1] % mod;
    ipw2[i] = 1ll * ipw2[i - 1] * ipw2[1] % mod;
  }
}

struct H { // hash
  int len, hsh1, hsh2;
};
bool operator != (H x, H y) {
  return x.len != y.len || x.hsh1 != y.hsh1 || x.hsh2 != y.hsh2;
}
H operator + (H x, H y) {
  return {x.len + y.len,
          (x.hsh1 + 1ll * y.hsh1 * pw1[x.len]) % mod,
          (x.hsh2 + 1ll * y.hsh2 * pw2[x.len]) % mod};
}
H operator - (H x, H y) {
  return {x.len - y.len,
          1ll * (mod + x.hsh1 - y.hsh1) * ipw1[y.len] % mod,
          1ll * (mod + x.hsh2 - y.hsh2) * ipw2[y.len] % mod};
}

#define ls (u << 1)
#define rs (u << 1 | 1)
struct node {
  H l, r;
  bool bad;
  node() {
    l = r = {0, 0, 0};
    bad = 0;
  }
  void set(int x) {
    bad = 0;
    if (x > 0) r = {1, x, x}, l = {0, 0, 0};
    else l = {1, -x, -x}, r = {0, 0, 0};
  }
} tr[N << 2];

H askL(int u, int l, int r, int len) {
  assert(l <= r);
  if (!len) return {0, 0, 0};
  if (tr[u].l.len == len) return tr[u].l;
  int mid = l + r >> 1;
  if (tr[ls].bad || tr[ls].l.len >= len) return askL(ls, l, mid, len);
  else return tr[ls].l + (askL(rs, mid + 1, r, len - tr[ls].l.len + tr[ls].r.len) - tr[ls].r);
}
H askR(int u, int l, int r, int len) {
  assert(l <= r);
  if (!len) return {0, 0, 0};
  if (tr[u].r.len == len) return tr[u].r;
  int mid = l + r >> 1;
  if (tr[rs].bad || tr[rs].r.len >= len) return askR(rs, mid + 1, r, len);
  else return tr[rs].r + (askR(ls, l, mid, len - tr[rs].r.len + tr[rs].l.len) - tr[rs].l);
}

node merge(node x, node y, int u, int l, int r) {
  node z;
  if (x.bad || y.bad) {
    z.bad = 1;
    return z; 
  }
  int mid = l + r >> 1;
  if (x.r.len < y.l.len) {
    H tmp = askL(rs, mid + 1, r, x.r.len);
    if (x.r != tmp) z.bad = 1;
    else z.l = x.l + (y.l - tmp), z.r = y.r;
  } else {
    H tmp = askR(ls, l, mid, y.l.len);
    if (y.l != tmp) z.bad = 1;
    else z.l = x.l, z.r = y.r + (x.r - tmp);
  }
  return z;
}

void build(int u, int l, int r) {
  if (l == r) {
    tr[u].set(a[l]);
    return ;
  }
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  tr[u] = merge(tr[ls], tr[rs], u, l, r);
}
void update(int u, int l, int r, int pos) {
  if (l == r) {
    tr[u].set(a[l]);
    return ;
  }
  int mid = l + r >> 1;
  if (pos <= mid) update(ls, l, mid, pos);
  else update(rs, mid + 1, r, pos);
  tr[u] = merge(tr[ls], tr[rs], u, l, r);
}
node query(int u, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return tr[u];
  int mid = l + r >> 1;
  if (qr <= mid) return query(ls, l, mid, ql, qr);
  if (ql > mid) return query(rs, mid + 1, r, ql, qr);
  return merge(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr), u, l, r);
}

int main() {
  n = read(), read(); init(n);
  rep(i, 1, n) a[i] = read();
  build(1, 1, n);
  q = read();
  while (q--) {
    int opt = read(), l = read(), r = read();
    if (opt == 1) {
      a[l] = r;
      update(1, 1, n, l);
    } else {
      node ans = query(1, 1, n, l, r);
      puts(!ans.bad && !ans.l.len && !ans.r.len ? "Yes" : "No");
    }
  }
  return 0;
}