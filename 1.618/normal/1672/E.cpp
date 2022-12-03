/*
start thinking:
BULB:
result of thinking: Lost.

(W), , r,  W / r.

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
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

int query(int w) {
  printf("? %d\n", w);
  fflush(stdout);
  int h;
  scanf("%d", &h);
  return h ? h : inf;
}

int n;

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  int lb = 1, rb = 4004000;
  while (lb < rb) {
    int mid = (lb + rb) >> 1;
    if (query(mid) == 1)
      rb = mid;
    else
      lb = mid + 1;
  }
  ll ans = infll;
  for (int i = 1; i <= n; i++)
    chmin(ans, (ll)query(lb / i) * (lb / i));
  printf("! %lld\n", ans);
  fflush(stdout);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}