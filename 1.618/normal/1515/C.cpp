/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
#define mp make_pair
typedef pair<int, int> P;
int n, m, x, ans[maxn];
P blk[maxn];

void solve() {
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &blk[i].first);
    blk[i].second = i;
  }
  sort(blk + 1, blk + n + 1);
  for (int i = 1; i <= n; i++) {
    ans[blk[i].second] = i % m + 1;
  }
  puts("YES"); 
  for (int i = 1; i <= n; i++) {
    printf("%d%c", ans[i], i == n ? '\n' : ' ');
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}