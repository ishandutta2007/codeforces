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

const int N = 1000005; /* ! */
const int mod = 998244353;

bool ans[N];
int a, b, ok[N], len;

void solve() {
  a = read(), b = read();
  if (a < b) swap(a, b); 
  rep(i, 0, a + b) ans[i] = 0;
  if ((a + b) % 2 == 0) {
    int qwq = (a + b) / 2;
    qwq = abs(qwq - a);
    for (int t = qwq; t <= qwq + 2 * ((a + b) / 2 - qwq); t += 2)
      ans[t] = 1;
  } else {
    int qwq = (a + b + 1) / 2;
    qwq = abs(qwq - a);
    for (int t = qwq; t <= qwq + 2 * ((a + b - 1) / 2 - qwq); t += 2)
      ans[t] = 1;
    qwq = (a + b - 1) / 2;
    qwq = abs(qwq - a);
    for (int t = qwq; t <= qwq + 2 * ((a + b + 1) / 2 - qwq); t += 2)
      ans[t] = 1;
  }
  len = 0;
  rep(i, 0, a + b) if (ans[i]) ok[++len] = i;
  printf("%d\n", len);
  rep(i, 1, len) print(ok[i], " \n"[i == len]);
}

int main() {
  int T = read();
  while (T--) {
    solve();
  } 
}