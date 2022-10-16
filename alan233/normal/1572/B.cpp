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

const int N = 200005;

vector<int> ans;
int a[N], n;

void gao(int l, int r) {
  for (int i = r - 2; i >= l; i -= 2) {
    ans.pb(i);
  }
  for (int i = l; i <= r - 2; i += 2) {
    ans.pb(i);
  }
}

int main() {
  int T = read();
  while (T--) {
    n = read();
    int s = 0; ans.clear();
    rep(i, 1, n) a[i] = read(), s ^= a[i];
    if (s) { puts("NO"); continue; }
    bool flag = 0;
    if (n & 1) flag = 1, gao(1, n);
    else {
      rep(i, 1, n) {
        s ^= a[i];
        if ((i & 1) && !s) {
          flag = 1;
          gao(1, i);
          gao(i + 1, n);
          break;
        }
      }
    } 
    if (!flag) { puts("NO"); continue; }
    puts("YES");
    printf("%d\n", SZ(ans));
    for (auto v: ans) printf("%d ", v); puts(""); 
  }
  return 0;
}