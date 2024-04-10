/*
start thinking:
BULB:
result of thinking:

.
wqs.

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

#define maxn 2010
mt19937 rng;
int n;
ll a, b, p[maxn], q[maxn], bogo0[maxn], bogo1[maxn], bogo2[maxn], bogo3[maxn];

ll numa, numb, ans;
ll checkb(ll x, ll y) {
  ans = numa = numb = 0;
  for (int i = 1; i <= n; i++) {
    ll _ans = bogo0[i], _numa = 0, _numb = 0;
    if (chmax(_ans, 10000000 * p[i] - x + bogo1[i]))
      _numa = 1, _numb = 0;
    if (chmax(_ans, 10000000 * q[i] - y + bogo2[i]))
      _numa = 0, _numb = 1;
    if (chmax(_ans, 10000000 * (p[i] + q[i]) - p[i] * q[i] - x - y + bogo3[i]))
      _numa = 1, _numb = 1;
    ans += _ans, numa += _numa, numb += _numb;
  }
  return numb;
}

ll checka(ll x) {
  ll lb = 0, rb = 1e14;
  while (lb < rb) {
    ll mid = (lb + rb) >> 1;
    if (checkb(x, mid) > b)
      lb = mid + 1;
    else
      rb = mid;
  }
  checkb(x, lb);
  ans += b * lb;
  return numa;
}

bool Med;
int main() {
  rng.seed(time(0));
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    double x;
    scanf("%lf", &x);
    p[i] = round(x * 1000) * 10000;
  }
  for (int i = 1; i <= n; i++) {
    double x;
    scanf("%lf", &x);
    q[i] = round(x * 1000) * 10000;
  }
  for (int i = 1; i <= n; i++) {
    bogo0[i] = rng() % 10000;
    bogo1[i] = rng() % 10000;
    bogo2[i] = rng() % 10000;
    bogo3[i] = rng() % 10000;
  }
  ll lb = 0, rb = 1e14;
  while (lb < rb) {
    ll mid = (lb + rb) >> 1;
    if (checka(mid) > a)
      lb = mid + 1;
    else
      rb = mid;
  }
  checka(lb);
  printf("%.6f\n", (ans + a * lb) / 1e14);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}