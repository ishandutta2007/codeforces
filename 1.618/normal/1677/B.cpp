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

#define maxn 1000005
char s[maxn];
int n, m, sum[maxn], ans1[maxn], ans2[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= n * m; i++)
    sum[i] = sum[i - 1] + (s[i] == '1');
  for (int i = 1; i <= m; i++) {
    ans1[i] = (sum[i] > 0);
    for (int j = i + m; j <= n * m; j += m)
      ans1[j] = ans1[j - m] + (sum[j] > sum[j - m]);
  }
  for (int i = 0; i <= n * m + 1; i++)
    ans2[i] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= n * m; j += m) {
      if (s[j] == '1') {
        ans2[j]++;
        break;
      }
    }
  }
  for (int i = 1; i <= n * m; i++)
    ans2[i] += ans2[i - 1];
  for (int i = 1; i <= n * m; i++)
    printf("%d%c", ans1[i] + ans2[i], " \n"[i == n * m]);
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