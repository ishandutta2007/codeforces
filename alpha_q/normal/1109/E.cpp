#include <bits/stdc++.h>

using namespace std;

const int M = 10;
const int N = 100010;

vector <int> pr;
int n, mod, q, sz, a[N], phi;

int bigMod (int a, int e) {
  if (e == -1) e = phi - 1;
  int ret = 1;
  while (e) {
    if (e & 1) ret = ret * 1LL * a % mod;
    a = a * 1LL * a % mod, e >>= 1;
  }
  return ret;
}

struct field {
  int unit, pwr[M];

  field () {}
  field (int x) {
    for (int i = 0; i < sz; ++i) {
      int e = 0;
      while (x % pr[i] == 0) ++e, x /= pr[i];
      pwr[i] = e;
    }
    unit = x % mod;
  }

  int get() {
    int ret = unit % mod;
    for (int i = 0; i < sz; ++i) ret = ret * 1LL * bigMod(pr[i], pwr[i]) % mod;
    return ret;
  }

  field operator * (const field &oth) const {
    field res;
    for (int i = 0; i < sz; ++i) res.pwr[i] = pwr[i] + oth.pwr[i];
    res.unit = unit * 1LL * oth.unit % mod;
    return res;
  }

  field operator / (const field &oth) const {
    field res;
    for (int i = 0; i < sz; ++i) res.pwr[i] = pwr[i] - oth.pwr[i];
    res.unit = unit * 1LL * bigMod(oth.unit, -1) % mod;
    return res;
  }
};

bitset <4 * N> tag;
field keep[4 * N];
int t[4 * N], lazy[4 * N];

void init (int u = 1, int b = 1, int e = n) {
  lazy[u] = 1;
  keep[u] = field(1);
  if (b == e) {
    t[u] = a[b] % mod;
    keep[u] = field(a[b]);
    return;
  }
  int m = b + e >> 1;
  init(u + u, b, m), init(u + u + 1, m + 1, e);
  t[u] = t[u + u] + t[u + u + 1];
  if (t[u] >= mod) t[u] -= mod;
}

inline void prop (int u, int b, int e) {
  t[u] = t[u] * 1LL * lazy[u] % mod;
  if (b - e) {
    lazy[u + u] = lazy[u + u] * 1LL * lazy[u] % mod;
    lazy[u + u + 1] = lazy[u + u + 1] * 1LL * lazy[u] % mod;
  }
  lazy[u] = 1;
}

inline void push (int u, int b, int e) {
  tag[u] = 0;
  if (b - e) {
    tag[u + u] = tag[u + u + 1] = 1;
    keep[u + u] = keep[u + u] * keep[u];
    keep[u + u + 1] = keep[u + u + 1] * keep[u];
    keep[u] = field(1);
  }
}

void pupdate (int p, int v, int u = 1, int b = 1, int e = n) {
  if (lazy[u] != 1) prop(u, b, e);
  if (b > p or e < p) return;
  if (b == e) return void(t[u] = v % mod);
  int m = b + e >> 1;
  pupdate(p, v, u + u, b, m);
  pupdate(p, v, u + u + 1, m + 1, e);
  t[u] = t[u + u] + t[u + u + 1];
  if (t[u] >= mod) t[u] -= mod;  
}

void update (int l, int r, int v, int u = 1, int b = 1, int e = n) {
  if (lazy[u] != 1) prop(u, b, e);
  if (tag[u]) push(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    tag[u] = 1, keep[u] = keep[u] * field(v);
    lazy[u] = lazy[u] * 1LL * v % mod;
    return prop(u, b, e); 
  }
  int m = b + e >> 1;
  update(l, r, v, u + u, b, m);
  update(l, r, v, u + u + 1, m + 1, e);
  t[u] = t[u + u] + t[u + u + 1];
  if (t[u] >= mod) t[u] -= mod;  
}

int query (int l, int r, int u = 1, int b = 1, int e = n) {
  if (b > r or e < l) return 0;
  if (lazy[u] != 1) prop(u, b, e);
  if (b >= l and e <= r) return t[u];
  int m = b + e >> 1;
  int ret = query(l, r, u + u, b, m) + query(l, r, u + u + 1, m + 1, e);
  if (ret >= mod) ret -= mod; return ret;
}

void put (int p, field fl, int u = 1, int b = 1, int e = n) {
  if (tag[u]) push(u, b, e);
  if (b == e) return void(keep[u] = fl);
  int m = b + e >> 1;
  if (p <= m) return put(p, fl, u + u, b, m);
  return put(p, fl, u + u + 1, m + 1, e);
}

field get (int p, int u = 1, int b = 1, int e = n) {
  if (tag[u]) push(u, b, e);
  if (b == e) return keep[u];
  int m = b + e >> 1;
  if (p <= m) return get(p, u + u, b, m);
  return get(p, u + u + 1, m + 1, e);
}

int main() {
  cin >> n >> mod;
  int tmp = mod; phi = mod;
  for (int i = 2; i * i <= tmp; ++i) {
    if (tmp % i == 0) {
      int e = 0;
      while (tmp % i == 0) tmp /= i, ++e;
      pr.push_back(i);
      phi /= i, phi *= (i - 1);
    }
  }
  if (tmp > 1) {
    pr.push_back(tmp);
    phi /= tmp, phi *= (tmp - 1);
  }
  sz = pr.size();
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  init();
  cin >> q; while (q--) {
    int cmd, l, r, v;
    scanf("%d %d %d", &cmd, &l, &r);
    if (cmd == 1) {
      scanf("%d", &v);
      update(l, r, v);
    } else if (cmd == 2) {
      field cur = get(l) / field(r);
      put(l, cur); pupdate(l, cur.get());
    } else {
      printf("%d\n", query(l, r));
    }
  } 
  return 0;
}