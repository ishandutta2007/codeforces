#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


const int mod = 998244353;

int add(int x) {  
  return x;
}

template<typename... T>
int add(int x, T... y) {  
  x += add(y...);
  if (x >= mod)
        x -= mod;
  return x;
}

template<typename... T>
int udd(int &x, T... y) { 
  return x = add(x, y...);
}

template<typename... T>
int sub(int x, T... y) { 
  return add(x, mod - add(y...));
}

int mul(int x) { 
  return x;
}

template<typename... T>
int mul(int x, T... y) { 
  return 1ll * x * mul(y...) % mod;
}

int bin(int x, int to) { 
  int y = 1;
  while (to) { 
        if (to & 1)
                  y = mul(x, y);
            x = mul(x, x);
                to >>= 1;
  }
  return y;
}

int inv(int x) { 
  assert(x != 0);
  return bin(x, mod - 2);
}

const int M = 37;
const int T = 17;

ll a[M];
int m;
int r = 0;
int n;
int rep[M];
int ans[M];

int bit(ll mask, ll i) {
  return (mask >> i) & 1;
}

int pop(ll mask) {
  return __builtin_popcountll(mask);
}

void gaub_add(ll x) {
  for (int i = 0; i < r; ++i) 
    if (bit(x, rep[i]))
      x ^= a[i];

  if (x != 0) {
    int k = 0;
    while (!bit(x, k)) ++k;

    for (int i = 0; i < r; ++i)
      if (bit(a[i], k))
        a[i] ^= x;

    for (int i = 0; i < r; ++i)
      assert(rep[i] != k);

    rep[r] = k;
    a[r] = x;
    ++r;
  }
}

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    gaub_add(x);
  }
}

void kill_small() {
  for (int mask = 0; mask < (1ll << r); ++mask) {
    ll cur = 0;
    for (int i = 0; i < r; ++i)
      if (bit(mask, i))
        cur ^= a[i];

    udd(ans[pop(cur)], 1);
  }
}

int d[M][(1 << T)];

void kill_big() {
  vector<int> rem;
  for (int k = 0; k < m; ++k) {
    bool ok = true;
    for (int i = 0; i < r; ++i)
      if (rep[i] == k)
        ok = false;
    if (ok) rem.push_back(k);
  }

  ll t = rem.size();

  d[0][0] = 1;

  for (int i = 0; i < r; ++i) {
    int now = 0;

    for (int j = 0; j < t; ++j)
      if (bit(a[i], rem[j]))
        now |= 1 << j;

    for (int j = i; j >= 0; --j)
      for (int mask = 0; mask < (1 << t); ++mask)
        if (d[j][mask]) 
          udd(d[j + 1][mask ^ now], d[j][mask]);
  }

  for (int j = 0; j <= r; ++j)
    for (int mask = 0; mask < (1 << t); ++mask)
      udd(ans[pop(mask) + j], d[j][mask]);
}

void kill() {
  if (m - r <= T)
    kill_big();
  else
    kill_small();

  for (int i = 0; i <= m; ++i)
    ans[i] = mul(ans[i], bin(2, n - r));
  for (int i = 0; i <= m; ++i)
    cout << ans[i] << " ";
  cout << "\n";
}
 

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}