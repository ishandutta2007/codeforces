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

#define maxn 100005
int n, ca[maxn], cb[maxn], to[maxn];
bool vis[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", ca + i);
  for (int i = 1; i <= n; i++) {
    scanf("%d", cb + i);
    to[cb[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    vis[i] = false;
  int num = 0;
  for (int i = 1; i <= n; i++) {
    int len = 0;
    for (int j = i; !vis[j]; j = to[ca[j]]) {
      vis[j] = true;
      len++;
    }
    num += len / 2;
  }
  ll ans = 0;
  for (int i = 1; i <= num; i++)
    ans += n - i + 1 - i;
  printf("%lld\n", ans * 2);
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