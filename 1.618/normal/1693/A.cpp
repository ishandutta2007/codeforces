/*
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
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n, a[maxn];
ll b[maxn];

void solve() {
  scanf("%d", &n);
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum += a[i];
  }
  if (sum) {
    puts("No");
    return;
  }
  bool ok = false;
  b[n] = 0;
  for (int i = n - 1; i >= 1; i--) {
    b[i] = b[i + 1] - a[i + 1];
    if (b[i] < 0) {
      puts("No");
      return;
    }
    if (b[i])
      ok = true;
    if (!b[i] && ok) {
      puts("No");
      return;
    }
  }
  puts("Yes");
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