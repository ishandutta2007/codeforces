/*
start thinking:
BULB:
result of thinking: Lost.

Instead of  centroid = i ,  centroid \in subtree(i)  f[i].
.

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
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
const int mod = 998244353;
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

int n, S, fct[maxn], invfct[maxn], inv[maxn], f[maxn], ans[maxn];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  S = (n + 1) / 2;
  fct[0] = 1;
  for (int i = 1; i <= n; i++)
    fct[i] = (ll)fct[i - 1] * i % mod;
  invfct[n] = modpow(fct[n], mod - 2);
  for (int i = n; i >= 1; i--) {
    invfct[i - 1] = (ll)invfct[i] * i % mod;
    inv[i] = (ll)invfct[i] * fct[i - 1] % mod;
  }
  for (int i = 1; i <= S; i++)
    f[i] = (ll)fct[n - i] * fct[n - S] % mod * invfct[n - S - i + 1] % mod;
  for (int i = S; i >= 1; i--) {
    ans[i] = (f[i] - (ll)ans[i + 1] * inv[i] + ans[i + 1]) % mod;
  }
  for (int i = 1; i <= n; i++)
    printf("%d%c", (ans[i] - ans[i + 1] + 2ll * mod) % mod, " \n"[i == n]);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}