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

const int N = 1000005;

int a[N], b[N], L[N], R[N];
int n, e;

bool vis[N]; int pr[N], len;
void xxs(int n) {
  vis[1] = 1;
  rep(i, 2, n) {
    if (!vis[i]) pr[++len] = i;
    rep(j, 1, len) {
      if (pr[j] * i > n) break;
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
}

void solve() {
  n = read(), e = read();
  rep(i, 1, n) a[i] = read();
  ll ans = 0;
  rep(mo, 1, e) {
    int m = 0;
    for (int i = mo; i <= n; i += e) b[++m] = a[i];
    /*
    printf("now mo = %d\n", mo);
    rep(i, 1, m) printf("%d ", b[i]); puts("");
    */
    L[0] = -1;
    for (int i = 1; i <= m; i++) {
      L[i] = (b[i - 1] > 1 ? 0 : L[i - 1] + 1);
    }
    R[m + 1] = -1;
    b[m + 1] = 0;
    for (int i = m; i >= 1; i--) {
      R[i] = (b[i + 1] > 1 ? 0 : R[i + 1] + 1);
    }
    /*
    rep(i, 1, m) {
      printf("L[%d] = %d, R[%d] = %d\n", i, L[i], i, R[i]);
    }
    */
    for (int i = 1; i <= m; i++) {
      if (b[i] > 1 && !vis[b[i]]) {
        ans += 1ll * (L[i] + 1) * (R[i] + 1) - 1;
      }
    }
  }
  print(ans, '\n');
}

int main() {
  xxs(1e6);
  int T = read();
  while (T--) solve();
  return 0;
}