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

#define N 55
char a[N], ans[N][N];
int n;

void solve() {
  scanf("%d%s", &n, a + 1);
  vector<int> zz;
  for (int i = 1; i <= n; i++) {
    if (a[i] == '2') zz.pb(i);
  }
  if (1 <= SZ(zz) && SZ(zz) <= 2) {
    puts("NO");
    return ;
  }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) ans[i][j] = '='; 
  }
  for (int i = 0; i < SZ(zz); i++) {
    int j = (i + 1) % SZ(zz);
    ans[zz[i]][zz[j]] = '+', ans[zz[j]][zz[i]] = '-';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) putchar('X');
      else putchar(ans[i][j]);
    }
    putchar('\n');
  }
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}