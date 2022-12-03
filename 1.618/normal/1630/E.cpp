/*
result of thinking: Pure.

phi.

start coding: 0:00
AC: 0:50
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

const int mod = 998244353;
#define maxn 1000005
int n, a[maxn], m, cnt[maxn], fct[maxn], invFct[maxn], sum, tot, phi[maxn];

int modpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1)
      res = (ll)res * x % mod;
    y >>= 1;
    x = (ll)x * x % mod;
  }
  return res;
}

int inv(int x) { return modpow(x, mod - 2); }

void compress() {
  vector<int> as;
  for (int i = 1; i <= n; i++)
    as.push_back(a[i]);
  sort(as.begin(), as.end());
  as.erase(unique(as.begin(), as.end()), as.end());
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin() + 1;
  }
  m = as.size();
}

void work(int rep) {
  int res = 0;
  for (int i = 1; i <= m; i++) {
    int foo = cnt[i] / rep;
    res = (res + (ll)foo * (foo - 1)) % mod;
  }
  int foo = n / rep;
  res = (1 - (ll)res * inv((ll)foo * (foo - 1) % mod)) % mod * n % mod;
  int bar = fct[n / rep];
  for (int i = 1; i <= m; i++) {
    bar = (ll)bar * invFct[cnt[i] / rep] % mod;
  }
  tot = (tot + (ll)bar * phi[rep]) % mod;
  sum = (sum + (ll)res * bar % mod * phi[rep]) % mod;
}

void solve() {
  sum = tot = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  compress();
  for (int i = 1; i <= m; i++)
    cnt[i] = 0;
  for (int i = 1; i <= n; i++)
    cnt[a[i]]++;
  int d = cnt[1];
  for (int i = 2; i <= m; i++)
    d = __gcd(d, cnt[i]);
  if (m == 1) {
    puts("1");
    return;
  }
  for (int i = 1; i <= d; i++) {
    if (d % i == 0) {
      work(i);
    }
  }
  printf("%lld\n", ((ll)sum * inv(tot) % mod + mod) % mod);
}

int main() {
  fct[0] = 1;
  for (int i = 1; i <= 1000000; i++)
    fct[i] = (ll)fct[i - 1] * i % mod;
  invFct[1000000] = inv(fct[1000000]);
  for (int i = 1000000; i >= 1; i--)
    invFct[i - 1] = (ll)invFct[i] * i % mod;
  for (int i = 1; i <= 1000000; i++) {
    phi[i] += i;
    for (int j = i * 2; j <= 1000000; j += i) {
      phi[j] -= phi[i];
    }
  }
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}