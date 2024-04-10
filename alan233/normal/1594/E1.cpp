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

const int N = 65;
const int mod = 1e9 + 7;

int dp[N][6];

void add(int &x, int y) {
  x += y; if (x >= mod) x -= mod;
}

int n;

int main() {
  n = read();
  for (int i = 0; i < 6; i++) dp[n][i] = 1;
  for (int i = n - 1; i >= 1; i--) {
    for (int c1 = 0; c1 < 6; c1++) {
      for (int c2 = 0; c2 < 6; c2++) {
        for (int c = 0; c < 6; c++) {
          if (c != c1 && c != (c1 ^ 1) && c != c2 && c != (c2 ^ 1))
            add(dp[i][c], 1ll * dp[i + 1][c1] * dp[i + 1][c2] % mod);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 6; i++) add(ans, dp[1][i]);
  print(ans, '\n');
  return 0;
}