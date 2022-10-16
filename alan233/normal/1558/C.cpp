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

const int N = 2025;
vector<int> ans;
int p[N], pos[N], n;
void Swap(int x) {
  if (x != 1) ans.pb(x);
  reverse(p + 1, p + x + 1);
  rep(i, 1, n) pos[p[i]] = i;
}

void solve() {
  ans.clear();
  n = read();
  rep(i, 1, n) p[i] = read();
  Swap(1);
  rep(i, 1, n) if ((p[i] - i) % 2) {
    puts("-1");
    return ;
  } 
  for (int i = n; i >= 3; i -= 2) {
    Swap(pos[i]);
    Swap(pos[i - 1] - 1);
    Swap(pos[i - 1] + 1);
    Swap(pos[i]);
    Swap(i);
  }
  print(SZ(ans), '\n');
  for (auto v: ans) print(v, ' ');
  putchar('\n');
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}