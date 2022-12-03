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
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
const int B = 200;
int n, a[maxn], ans;

void small(int d) {
  static int b[maxn];
  for (int i = 1; i <= n; i++)
    b[i] = a[i] - i * d;
  sort(b + 1, b + n + 1);
  for (int i = 1, j; i <= n; i = j) {
    for (j = i; j <= n && b[j] == b[i]; j++);
    chmax(ans, j - i);
  }
}

void big(int m) {
  static int b[maxn]; int bk = 0;
  for (int i = max(1, m - a[m] / B); i <= min(n, m + (100000 - a[m]) / B); i++) {
    if (i != m && (a[i] - a[m]) % (i - m) == 0)
      b[++bk] = (a[i] - a[m]) / (i - m);
  }
  sort(b + 1, b + bk + 1);
  for (int i = 1, j; i <= bk; i = j) {
    for (j = i; j <= bk && b[j] == b[i]; j++);
    chmax(ans, j - i + 1);
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  ans = 0;
  for (int i = -B; i <= B; i++)
    small(i);
  for (int i = 1; i <= n; i++)
    big(i);
  printf("%d\n", n - ans);
  return 0;
}