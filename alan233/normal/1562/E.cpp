// Author: wlzhouzhuan
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

const int N = 5005;

char a[N];
int f[N], lcp[N][N], n;
int ans;

void solve() {
  ans = 0;
  scanf("%d%s", &n, a + 1);
  a[n + 1] = 0;
  rep(i, 0, n + 2) rep(j, 0, n + 2) lcp[i][j] = 0;
  memset(f, 0, 4 * (n + 1));
  for (int i = n; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] == a[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1; 
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i] = f[i] + n - i + 1;
    for (int j = i + 1; j <= n; j++) {
      if (lcp[i][j] < n - j + 1 && a[i + lcp[i][j]] < a[j + lcp[i][j]])
        ckmax(f[j], f[i] - lcp[i][j]);
    }
    ckmax(ans, f[i]);
  }
  print(ans, '\n');
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}