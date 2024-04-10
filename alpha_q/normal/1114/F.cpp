#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 301;
const int N = 400010;
const int MOD = 1e9 + 7;

int n, q;
char cmd[69];
vector <ll> pr;
ll a[N], mask[M], mul[M];
ll prod[4 * N], orz[4 * N];
ll lzProd[4 * N], lzOrz[4 * N];

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

bool isPrime (int x) {
  for (int i = 2; i * i <= x; ++i) if (x % i == 0) return 0;
  return 1;
}

void init (int u = 1, int b = 1, int e = n) {
  lzProd[u] = 1, lzOrz[u] = 0;
  if (b == e) {
    prod[u] = a[b], orz[u] = mask[a[b]];
    return;
  }
  int mid = b + e >> 1;
  init(u << 1, b, mid), init(u << 1 | 1, mid + 1, e);
  prod[u] = prod[u << 1] * prod[u << 1 | 1] % MOD;
  orz[u] = orz[u << 1] | orz[u << 1 | 1];
}

void push (int u, int b, int e) {
  prod[u] *= bigMod(lzProd[u], e - b + 1), prod[u] %= MOD, orz[u] |= lzOrz[u];
  if (b ^ e) {
    lzProd[u << 1] *= lzProd[u], lzProd[u << 1] %= MOD;
    lzProd[u << 1 | 1] *= lzProd[u], lzProd[u << 1 | 1] %= MOD;
    lzOrz[u << 1] |= lzOrz[u], lzOrz[u << 1 | 1] |= lzOrz[u];
  }
  lzProd[u] = 1, lzOrz[u] = 0;
}

void update (int l, int r, int x, int u = 1, int b = 1, int e = n) {
  if (lzProd[u] > 1 or lzOrz[u]) push(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lzProd[u] *= x, lzProd[u] %= MOD, lzOrz[u] |= mask[x];
    return push(u, b, e);
  }
  int mid = b + e >> 1;
  update(l, r, x, u << 1, b, mid), update(l, r, x, u << 1 | 1, mid + 1, e);
  prod[u] = prod[u << 1] * prod[u << 1 | 1] % MOD;
  orz[u] = orz[u << 1] | orz[u << 1 | 1];
}

pair <ll, ll> query (int l, int r, int u = 1, int b = 1, int e = n) {
  if (b > r or e < l) return make_pair(1, 0);
  if (lzProd[u] > 1 or lzOrz[u]) push(u, b, e);
  if (b >= l and e <= r) return make_pair(prod[u], orz[u]);
  int mid = b + e >> 1;
  pair <ll, ll> one = query(l, r, u << 1, b, mid);
  pair <ll, ll> two = query(l, r, u << 1 | 1, mid + 1, e);
  return make_pair(one.first * two.first % MOD, one.second | two.second);
}

int main() {
  for (int i = 2; i < M; ++i) if (isPrime(i)) pr.emplace_back(i);
  int sz = pr.size();
  for (int i = 1; i < M; ++i) {
    for (int j = 0; j < sz; ++j) if (i % pr[j] == 0) mask[i] |= 1LL << j;
  }
  for (int i = 0; i < sz; ++i) mul[i] = (pr[i] - 1) * bigMod(pr[i], -1) % MOD;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
  init();
  while (q--) {
    int l, r, x;
    scanf("%s %d %d", cmd, &l, &r);
    if (cmd[0] == 'T') {
      pair <ll, ll> yo = query(l, r);
      ll ans = yo.first;
      for (int i = 0; i < sz; ++i) if (yo.second & 1LL << i) ans *= mul[i], ans %= MOD;
      printf("%lld\n", ans);
    } else {
      scanf("%d", &x);
      update(l, r, x);
    }
  }
  return 0;
}