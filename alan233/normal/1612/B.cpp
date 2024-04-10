// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

int n, a, b;

void solve() {
  n = read(), a = read(), b = read();
  if (a == n / 2 + 1 && b == n / 2) {
    for (int i = n / 2 + 1; i <= n; i++) printf("%d ", i);
    for (int i = 1; i <= n / 2; i++) printf("%d ", i);
    puts("");
    return ;
  }
  if (a >= b) {
    puts("-1");
    return ;
  }
  vector<int> left, right;
  for (int i = b + 1; i <= n; i++) left.pb(i);
  for (int i = 1; i < a; i++) right.pb(i);
  left.pb(a);
  right.pb(b);
  for (int i = a + 1; i < b; i++) {
    if (SZ(left) < n / 2) left.pb(i);
    else right.pb(i);
  }
  if (SZ(left) > n / 2 || SZ(right) > n / 2) {
    puts("-1");
    return ;
  }
  for (auto v: left) printf("%d ", v);
  for (auto v: right) printf("%d ", v);
  puts("");
} 

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}