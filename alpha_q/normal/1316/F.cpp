#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 600010;
const int MOD = 1e9 + 7;
const ll INV = 1 + MOD >> 1;

int m;

struct SegTree {
  ll t[4 * N], lazy[4 * N];

  void init (int u = 1, int b = 1, int e = m) {
    t[u] = 0, lazy[u] = 1;
    if (b == e) return;
    int mid = b + e >> 1;
    init(u << 1, b, mid), init(u << 1 | 1, mid + 1, e);
  }

  inline void push (int u, int b, int e) {
    t[u] = t[u] * lazy[u] % MOD;
    if (b ^ e) {
      lazy[u << 1] = lazy[u] * lazy[u << 1] % MOD;
      lazy[u << 1 | 1] = lazy[u] * lazy[u << 1 | 1] % MOD;
    }
    lazy[u] = 1;
  }

  void put (int p, ll v, int u = 1, int b = 1, int e = m) {
    if (lazy[u] != 1) push(u, b, e);
    if (b > p or e < p) return;
    if (b == e) return void(t[u] = v);
    int mid = b + e >> 1;
    put(p, v, u << 1, b, mid);
    put(p, v, u << 1 | 1, mid + 1, e);
    t[u] = (t[u << 1] + t[u << 1 | 1]) % MOD;
  }

  void update (int l, int r, ll v, int u = 1, int b = 1, int e = m) {
    if (lazy[u] != 1) push(u, b, e);
    if (l > r or b > r or e < l) return;
    if (b >= l and e <= r) {
      lazy[u] = v * lazy[u] % MOD;
      return push(u, b, e);
    }
    int mid = b + e >> 1;
    update(l, r, v, u << 1, b, mid); 
    update(l, r, v, u << 1 | 1, mid + 1, e);
    t[u] = (t[u << 1] + t[u << 1 | 1]) % MOD;
  }

  ll query (int l, int r, int u = 1, int b = 1, int e = m) {
    if (l > r or b > r or e < l) return 0;
    if (lazy[u] != 1) push(u, b, e);
    if (b >= l and e <= r) return t[u];
    int mid = b + e >> 1;
    return (query(l, r, u << 1, b, mid) + query(l, r, u << 1 | 1, mid + 1, e)) % MOD;
  }
};

SegTree below, above;
ll a[N], b[N], two[N], inv[N], sf[N];
int n, q, id[N], rev[N], pos[N], f[N];

void update (int p, int v) {
  while (p < N) f[p] += v, p += p & -p;
}

int pref (int p) {
  int ret = 0;
  while (p) ret += f[p], p -= p & -p;
  return ret;
}

int main() {
  two[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    two[i] = 2 * two[i - 1] % MOD;
    inv[i] = INV * inv[i - 1] % MOD;
  }
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = n; i >= 1; --i) {
    sf[i] = (sf[i + 1] + b[i] * inv[i]) % MOD;
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ll cur = two[i] * b[i] % MOD;
    cur = cur * sf[i + 1] % MOD;
    ans += cur, ans %= MOD;
  }
  cout << ans * INV % MOD << '\n';
  for (int i = 1; i <= n; ++i) b[i] = i;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    scanf("%d %lld", pos + i, a + n + i);
  }
  m = n + q; below.init(), above.init();
  for (int i = 1; i <= m; ++i) {
    id[i] = i;
  }
  sort(id + 1, id + m + 1, [] (int i, int j) {
    return a[i] < a[j];
  });
  for (int i = 1; i <= m; ++i) {
    rev[id[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    update(rev[i], 1);
  }
  for (int i = 1; i <= n; ++i) {
    int at = pref(rev[i]);
    below.put(rev[i], a[i] * inv[at] % MOD);
    above.put(rev[i], a[i] * two[at] % MOD);
  }
  for (int i = 1; i <= q; ++i) {
    ll &cur = b[pos[i]];
    int at = pref(rev[cur]);
    ll sub = (two[at] * a[cur] % MOD) * below.query(rev[cur] + 1, m) % MOD;
    sub = (sub + (inv[at] * a[cur] % MOD) * above.query(1, rev[cur] - 1)) % MOD;
    sub = (sub - above.query(1, rev[cur] - 1) * below.query(rev[cur] + 1, m)) % MOD;
    below.put(rev[cur], 0); above.put(rev[cur], 0);
    below.update(rev[cur], m, 2); above.update(rev[cur], m, INV);
    update(rev[cur], -1); cur = n + i; 
    update(rev[cur], +1); at = pref(rev[cur]);
    below.put(rev[cur], a[cur] * inv[at] % MOD);
    above.put(rev[cur], a[cur] * two[at] % MOD);
    below.update(rev[cur] + 1, m, INV); above.update(rev[cur] + 1, m, 2);
    ll add = (two[at] * a[cur] % MOD) * below.query(rev[cur] + 1, m) % MOD;
    add = (add + (inv[at] * a[cur] % MOD) * above.query(1, rev[cur] - 1)) % MOD;
    add = (add - above.query(1, rev[cur] - 1) * below.query(rev[cur] + 1, m)) % MOD;
    ans += add - sub, ans %= MOD, ans += MOD, ans %= MOD;
    printf("%lld\n", (ans * INV % MOD));
  }
  return 0;
}