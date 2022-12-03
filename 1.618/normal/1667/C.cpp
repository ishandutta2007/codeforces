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
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

int n, k;

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  k = (2 * n + 1) / 3;
  printf("%d\n", k);
  if (n <= 2) {
    puts("1 1");
    return 0;
  }
  k = n - k;
  for (int i = 1; i <= k; i++) {
    printf("%d %d\n", i, k + 1 - i);
  }
  for (int i = k + 1; i < k + k; i++) {
    printf("%d %d\n", i, 3 * k - i);
  }
  if (n % 3 == 0) {
    printf("%d %d\n", 2 * k, 2 * k);
  } else if (n % 3 == 1) {
    printf("%d %d\n", 2 * k, 2 * k + 1);
    printf("%d %d\n", 2 * k + 1, 2 * k);
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}