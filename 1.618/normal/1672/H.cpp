/*
start thinking:
BULB:
result of thinking: Aided.

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
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n, q, sum[2][maxn];
char a[maxn];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &q);
  scanf("%s", a + 1);
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      sum[j][i] = sum[j][i - 1] + (a[i - 1] == j + '0' && a[i] == j + '0');
    }
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", max(sum[0][r] - sum[0][l], sum[1][r] - sum[1][l]) + 1);
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}