/*
result of thinking: Lost.

1 <= k <= 1e7
T_Ta[i]lcm(1,2,...,k)...

start coding:
AC:
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
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

const int LCM = 12252240;
const int mod = 998244353;
int n, a, x, y, k, m, pown[25], cnt[12252245], foo[12252245];

int main() {
  scanf("%d%d%d%d%d%d", &n, &a, &x, &y, &k, &m);
  pown[0] = 1;
  for (int i = 1; i <= k; i++)
    pown[i] = (ll)pown[i - 1] * n % mod;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cnt[a % LCM]++;
    ans = (ans + (ll)a / LCM * LCM * pown[k - 1] % mod * k) % mod;
    a = ((ll)a * x + y) % m;
  }
  for (int i = 1; i <= k; i++) {
    memset(foo, 0, sizeof(foo));
    for (int j = 0; j < LCM; j++) {
      ans = (ans + (ll)j * cnt[j] % mod * pown[k - i]) % mod;
      foo[j] = (foo[j] + ll(n - 1) * cnt[j]) % mod;
      foo[j / i * i] = (foo[j / i * i] + cnt[j]) % mod;
    }
    swap(foo, cnt);
  }
  printf("%d\n", (ans % mod + mod) % mod);
  return 0;
}