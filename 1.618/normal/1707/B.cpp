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

struct Seq {
  int num0;
  multiset<int> pos;

  Seq go() {
    if (pos.empty()) {
      return {num0 - 1, pos};
    }
    multiset<int> foo;
    int bar = 0;
    for (auto it = next(pos.begin()); it != pos.end(); it++) {
      if (*it == *prev(it)) {
        bar++;
      } else {
        foo.insert(*it - *prev(it));
      }
    }
    if (num0) {
      foo.insert(*pos.begin());
      return (Seq){bar + num0 - 1, foo};
    } else {
      return (Seq){bar, foo};
    }
  }
} a;

void solve() {
  a.num0 = 0;
  a.pos.clear();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (!x)
      a.num0++;
    else
      a.pos.insert(x);
  }
  for (int i = 1; i < n; i++)
    a = a.go();
  if (a.num0)
    puts("0");
  else
    printf("%d\n", *a.pos.begin());
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}