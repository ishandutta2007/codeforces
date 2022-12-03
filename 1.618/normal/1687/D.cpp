/*
start thinking:
BULB:
result of thinking: Pure.

.
 squ[i] <= a1 + k <= squ[i] + i
 d[j]  a1 + k  "a1 + k "
 lb, rb 
 O(NlnN), N = 2e6.

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

#define maxn 2000005
ll squ[maxn], d[maxn], a1;
int n, nxt[maxn], pre[maxn];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  for (int i = 1; i <= 2000001; i++)
    squ[i] = (ll)i * i;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lld", d + i);
  a1 = d[1];
  for (int i = 1; i <= n; i++) {
    d[i] -= a1;
    pre[d[i]] = nxt[d[i]] = d[i];
  }
  for (int i = 2; i <= n; i++) {
    for (int j = d[i] - 1; j > d[i - 1]; j--)
      nxt[j] = d[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = d[i] + 1; j < d[i + 1]; j++)
      pre[j] = d[i];
  }
  for (int i = 1; ; i++) {
    ll mini = max(0ll, a1 - squ[i]), maxi = i;
    for (int j = i; squ[j] - squ[i] <= d[n]; j++) {
      auto foo = squ[j] - squ[i] + j;
      chmin(maxi, foo - (foo <= d[n] ? pre[foo] : d[n]));
      if (foo < d[n])
        chmax(mini, squ[j + 1] - squ[i] - nxt[foo + 1]);
    }
    if (maxi >= mini) {
      printf("%lld\n", squ[i] + mini - a1);
      return 0;
    }
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}