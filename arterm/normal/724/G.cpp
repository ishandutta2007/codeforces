#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int M = 200100;
const int mod = 1e9 + 7;
const int N = 80;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0)
    x += mod;
  return x;
}

int mul(ll x, ll y, int mod=mod) {
  return x * y % mod;
}

int bin(int x, ll to, int mod=mod) {
  int y = 1;
  while (to) {
    if (to & 1) {
      y = mul(x, y, mod);
    }
    x = mul(x, x, mod);
    to >>= 1;
  }
  return y;
}

int inv(int x) {
  assert(x != 0);
  return bin(x, mod - 2);
}

int n, m;
vector<int> g[M];
int a[M], b[M];
ll c[M];
vector<ll> x, cyc;
ll d[M];
int used[M];
bool one[N];

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v >> c[i];
    --u, --v;
    a[i] = u, b[i] = v;
    g[u].push_back(i);
    g[v].push_back(i);
  }
}

void dfs(int v, int by, ll cur) {
  used[v] = 1;
  d[v] = cur;
  x.push_back(d[v]);

  for (int id : g[v]) {
    if (id == by)
      continue;

    int to = a[id] ^ b[id] ^ v;
    if (used[to] == 1) {
      cyc.push_back(d[v] ^ d[to] ^ c[id]);
    } else if (used[to] == 0) {
      dfs(to, id, cur ^ c[id]);
    } else {
      ;
    }
  }

  used[v] = 2;
}

int bit(ll x, int i) {
  return (x >> i) & 1;
}

int gaub(vector<ll> &a) {
  int last = 0; 
  int n = a.size();

  for (int i = 0; i < 60; ++i) {
    int x = -1;

    for (int j = last; j < n; ++j)
      if (bit(a[j], i))
        x = j;

    if (x == -1)
      continue;

    swap(a[last], a[x]);
    
    for (int j = 0; j < n; ++j)
      if (j != last && bit(a[j], i))
        a[j] ^= a[last];

    ++last;
  }

  return last;
}


void kill() {
  ll ans = 0;

  for (int i = 0; i < n; ++i) 
    if (!used[i]) {
      x.clear();
      cyc.clear();

      dfs(i, -1, 0ll);

      fill(one, one + N, false);
      for (ll x : cyc)
        for (int i = 0; i < 60; ++i)
          if (bit(x, i))
            one[i] = true;

      //cerr << "cyc.s = " << cyc.size() << endl;
      //cerr << "cyc[0] = " << cyc[0] << endl;

      int rank = gaub(cyc);

      ll n = x.size();
      ll bon = 0;
      ll ways = (n * (n - 1) / 2) % mod;

      for (int i = 0; i < 60; ++i)
        if (one[i]) {
          bon = add(bon, mul(ways, mul(bin(2, i), bin(2, rank - 1))));
        } else {
          int A = 0, B = 0;
          for (ll cur : x)
            if (bit(cur, i))
              ++A;
            else
              ++B;

          ans = add(ans, mul(mul(A, B), mul(bin(2, i), bin(2, rank))));
        }

      ans = add(ans, bon);
    }

  cout << ans << endl;
}

signed main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}