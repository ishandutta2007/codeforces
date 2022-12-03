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
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
int n;
char s[maxn];

void solve() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  if (n == 1 || s[1] <= s[2]) {
    printf("%c%c\n", s[1], s[1]);
    return;
  }
  int i;
  for (i = 1; i < n && s[i] >= s[i + 1]; i++);
  for (int j = 1; j <= i; j++)
    printf("%c", s[j]);
  for (int j = i; j >= 1; j--)
    printf("%c", s[j]);
  puts("");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}