/*
start thinking:
BULB:
result of thinking: Pure.

 IQ  IQ .
 y = 0,  (i, a[i]),  y  > cur_y 
cur_y,  cur_y  q.

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

#define maxn 100005
int n, q, a[maxn];
bool on[maxn];

void solve() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    on[i] = false;
  }
  int y = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] <= y) {
      on[i] = true;
    } else if (y < q) {
      y++;
      on[i] = true;
    }
  }
  for (int i = 1; i <= n; i++)
    printf("%d", (int)on[i]);
  puts("");
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