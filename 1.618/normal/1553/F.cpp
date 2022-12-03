/*


Q.E.D.

start thinking:
BULB:
result of thinking:

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
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
#define maxa 300005
const int SQRT_A = 548;

namespace RSQ {
  #define maxBlkNum 555
  const int SIZ = 300000;
  const int NUM = 548;

  int belong[maxa], l[maxBlkNum], r[maxBlkNum];
  int sumInBlk[maxa], sumOfBlk[maxBlkNum];
  ll sumInBlk2[maxa], sumOfBlk2[maxBlkNum];

  void build() {
    for (int i = 1; i <= NUM; i++) {
      l[i] = (i - 1) * SQRT_A + 1, r[i] = min(i * SQRT_A, SIZ);
      for (int j = l[i]; j <= r[i]; j++)
        belong[j] = i;
    }
  }

  void inc(int pos) {
    int foo = belong[pos];
    for (int i = pos; i <= r[foo]; i++) {
      ++sumInBlk[i];
      sumInBlk2[i] += pos;
    }
    for (int i = foo; i <= NUM; i++) {
      ++sumOfBlk[i];
      sumOfBlk2[i] += pos;
    }
  }

  int qsum(int r) {
    return sumOfBlk[(r - 1) / SQRT_A] + sumInBlk[r];
  }

  int qsum(int l, int r) {
    return qsum(r) - qsum(l - 1);
  }

  ll qsum2(int r) {
    return sumOfBlk2[(r - 1) / SQRT_A] + sumInBlk2[r];
  }

  ll qsum2(int l, int r) {
    return qsum2(r) - qsum2(l - 1);
  }

  #undef maxBlkNum
}

int n, a[maxn], modsum[SQRT_A + 5];
ll suma[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    suma[i] = suma[i - 1] + a[i];
  }
  RSQ::build();

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    RSQ::inc(a[i]);
    for (int j = 1; j <= SQRT_A; j++) {
      modsum[j] += a[i] % j;
    }
    if (a[i] <= SQRT_A)
      ans += modsum[a[i]];
    else {
      int foo = 0;
      for (int j = 1; j * a[i] <= 300000; j++) {
        foo += (ll)RSQ::qsum(j * a[i], min((j + 1) * a[i] - 1, 300000)) * j;
      }
      ans += suma[i] - (ll)foo * a[i];
    }
    ll foo = 0;
    for (int j = 1, k; j <= a[i]; j = k + 1) {
      k = a[i] / (a[i] / j);
      foo += (ll)a[i] / j * RSQ::qsum2(j, k);
    }
    ans += (ll)i * a[i] - foo;
    printf("%lld%c", ans, i == n ? '\n' : ' ');
  }
  return 0;
}