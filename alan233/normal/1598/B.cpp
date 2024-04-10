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

const int N = 1005;

int a[N][5], n;

void solve() {
  n = read();
  rep(i, 1, n) {
    rep(j, 0, 4) {
      a[i][j] = read();
    }
  }
  rep(A, 0, 4) {
    rep(B, A + 1, 4) {
      int num0, num1, num01;
      num0 = num1 = num01 = 0;
      bool ok = true;
      rep(i, 1, n) {
        if (!a[i][A] && !a[i][B]) {
          ok = false;
          break;
        }
        if (a[i][A] && a[i][B]) num01++;
        else if (a[i][A]) num0++;
        else num1++;
      }
      if (num0 > n / 2 || num1 > n / 2 || !ok) continue;
      puts("YES");
      return ;
    }
  }
  puts("NO");
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}