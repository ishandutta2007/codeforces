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

#define maxn 200005
int n, l, r, cnt[maxn];

void solve() {
  memset(cnt, 0, sizeof(cnt));
  scanf("%d%d%d", &n, &l, &r);
  for (int i = 1; i <= l; i++) {
    int c;
    scanf("%d", &c);
    cnt[c]++;
  }
  for (int i = l + 1; i <= n; i++) {
    int c;
    scanf("%d", &c);
    cnt[c]--;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++)
    sum += cnt[i];
  if (sum < 0) {
    for (int i = 1; i <= n; i++)  
      cnt[i] = -cnt[i];
  }
  int odd = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += abs(cnt[i]);
    if (cnt[i] > 0) {
      odd += (cnt[i] & 1);
    } else {
      odd += cnt[i];
    }
  }
  ans /= 2;
  if (odd > 0)
    ans += odd / 2;
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}