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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
char s[maxn];

void solve() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  static bool app[35];
  memset(app, 0, sizeof(app));
  int opt = n;
  for (int i = n; i >= 1; i--) {
    if (!app[s[i] - 'a'])
      opt = i;
    app[s[i] - 'a'] = true;
  }
  printf("%s\n", s + opt);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}