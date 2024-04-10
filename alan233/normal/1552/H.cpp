// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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

int main() {
  printf("? 40000\n");
  rep(i, 1, 200) rep(j, 1, 200) printf("%d %d ", i, j);
  puts(""), fflush(stdout);
  int area; scanf("%d", &area);
  int l = 1, r = 8, S = 0;
  while (l < r) {
    int mid = l + r >> 1, h = 1 << mid;
    printf("? %d\n", (200 / h) * 200);
    rep(i, 1, 200 / h) rep(j, 1, 200) printf("%d %d ", h * i, j);
    puts(""), fflush(stdout);
    int _; scanf("%d", &_);
    if (h * _ == area) l = mid + 1;
    else r = mid, S = _;
  } 
//  printf("I know! l = %d, S = %d\n", l, S);
  int n = abs(2 * S - area / (1 << l - 1));
//  assert(area % (1 << l - 1) == 0);
  int m = area / n;
//  printf("n = %d, m = %d\n", n, m);
//  assert(n + m - 2 >= 0);
  printf("! %d\n", 2 * (n + m - 2)), fflush(stdout);
  return 0; 
}