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

int f[512], g[512], n;

int main() {
  n = read();
  for (int i = 0; i < 512; i++) f[i] = 512;
  f[0] = 0;
  rep(i, 1, n) {
    int x = read();
    for (int j = 0; j < 512; j++) g[j] = 512;
    for (int j = 0; j < 512; j++) {
      ckmin(g[j], f[j]);
      if (f[j ^ x] < x) ckmin(g[j], x);
    }
    for (int j = 0; j < 512; j++) {
      f[j] = g[j];
    }
  }
  vector<int> QAQ;
  for (int i = 0; i < 512; i++) if (f[i] != 512) QAQ.pb(i);
  print(SZ(QAQ), '\n');
  for (auto v: QAQ) printf("%d ", v);
  puts("");
  return 0;
}