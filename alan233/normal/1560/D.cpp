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

int len;

void solve() {
  char a[100]; scanf("%s", a + 1);
  len = strlen(a + 1);
  for (int i = 1; i <= len; i++) a[i] ^= '0';
  int ans = 1e9;
  for (ll x = 1, t = 0; t <= 60; x <<= 1, t++) {
    char b[100]; int lenb = 0;
    ll _x = x;
    while (_x) b[++lenb] = _x % 10, _x /= 10;
    reverse(b + 1, b + lenb + 1);
    int j = 1, remove = 0;
    for (int i = 1; i <= len; i++) {
      if (j <= lenb && a[i] == b[j]) ++j;
      else remove++;
    }
    remove += lenb - j + 1;
    ans = min(ans, remove);
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