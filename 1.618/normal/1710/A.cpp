/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
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

#define maxk 100005
int n, m, k, a[maxk], b[maxk];

void solve() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
  bool ok = false, odd = false;
  ll cnt = 0;
  for (int i = 1; i <= k; i++) {
    if (a[i] < 2 * m)
      a[i] = 0;
    cnt += a[i] / m;
    odd |= a[i] / m > 2;
  }
  ok |= cnt >= n && (n % 2 == 0 || odd);
  cnt = odd = 0;
  for (int i = 1; i <= k; i++) {
    if (b[i] < 2 * n)
      b[i] = 0;
    cnt += b[i] / n;
    odd |= b[i] / n > 2;
  }
  ok |= cnt >= m && (m % 2 == 0 || odd);
  puts(ok ? "Yes" : "No");
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}