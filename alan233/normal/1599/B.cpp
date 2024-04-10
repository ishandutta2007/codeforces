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

char dira[55], dirb[55];
int a, b;
long long n;

int main() {
  int T = read();
  while (T--) {
    scanf("%lld", &n);
    scanf("%d%d%s%s", &a, &b, dira, dirb);
    bool _dira = dira[0] == 'r';
    bool _dirb = dirb[0] == 'r';
    if (a == 0) _dira = 1;
    else if (a == n - 1) _dira = 0;
    if (b == 0) _dirb = 1;
    else if (b == n - 1) _dirb = 0;
    if (a == b && _dira == _dirb) {
      printf("%lld\n", _dira ? 0 : n - 1);
    } else {
      printf("%lld\n", ((a < b) == (((b - a) % 2 + 2) % 2)) ? 0 : n - 1);
    }
  }
  return 0;
}