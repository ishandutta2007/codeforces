/*
start thinking:
BULB:
result of thinking: Pure.

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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxs 262149
int n, rk[19][maxs];
char s[maxs];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < (1 << n); i++)
    rk[0][i] = s[i] - 'a';
  for (int i = 1; i <= n; i++) {
    vector<P> foo(1 << n);
    for (int j = 0; j < (1 << n); j++)
      foo[j] = {rk[i - 1][j], rk[i - 1][j ^ 1]};
    sort(foo.begin(), foo.end());
    foo.erase(unique(foo.begin(), foo.end()), foo.end());
    for (int j = 0; j < (1 << n); j += 1 << (n - i + 1)) {
      for (int k = j; k < j + (1 << (n - i)); k++) {
        rk[i][k] = lower_bound(foo.begin(), foo.end(), 
          mp(rk[i - 1][j | (k - j) << 1], rk[i - 1][j | (k - j) << 1 ^ 1])) - foo.begin();
        rk[i][k | (1 << (n - i))] = lower_bound(foo.begin(), foo.end(),
          mp(rk[i - 1][j | (k - j) << 1 ^ 1], rk[i - 1][j | (k - j) << 1])) - foo.begin();
      }
    }
  }
  int ans = min_element(rk[n], rk[n] + (1 << n)) - rk[n], j = 0;
  for (int i = 0; i < n; i++)
    j |= (ans >> (n - i - 1) & 1) << i;
  for (int i = 0; i < (1 << n); i++)
    printf("%c", s[i ^ j]);
  puts("");
  return 0;
}