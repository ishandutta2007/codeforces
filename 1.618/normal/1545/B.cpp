/*


Q.E.D.

BULB: 90min!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
result of thinking:

0.

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
const ll mod = 998244353;
ll fct[maxn], invFct[maxn];
ll modpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      (res *= x) %= mod;
    y >>= 1;
    (x *= x) %= mod;
  }
  return res;
}
ll c(ll x, ll y) {
  return fct[x] * invFct[y] % mod * invFct[x - y] % mod;
}

int n;
char s[maxn];

void solve() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  int lst = 0, o = 0, e = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      ++(((i - lst) & 1) ? o : e);
      lst = i;
    }
  }
  ++(((n + 1 - lst) & 1) ? o : e);
  printf("%lld\n", c((n + 1 + o) / 2 - 1, o + e - 1));
}

int main() {
  fct[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    fct[i] = fct[i - 1] * i % mod;
  }
  invFct[100000] = modpow(fct[100000], mod - 2);
  for (int i = 100000; i >= 1; i--)
    invFct[i - 1] = invFct[i] * i % mod;

  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "did not RE" << endl;
  return 0;
}