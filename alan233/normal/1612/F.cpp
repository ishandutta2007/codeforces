// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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

gp_hash_table<int, int> qwq[200005];
gp_hash_table<int, int> dis[200005];
int n, m, qq;

 int ans = 1e9;

void dfs(int x, int y, int step) {
  if (step >= ans) return ;
  // printf("dfs %d %d %d\n", x, y, step);
  if (x == n && y == m) {
    ans = min(ans, step);
    return ;
  }
  int can = x + y + (qwq[x].find(y) != qwq[x].end());
  if (min(n, can) > x) dfs(min(n, can), y, step + 1);
  if (min(m, can) > y) dfs(x, min(m, can), step + 1);
}

int far[2][200005];
int rot;

int main() {
  n = read(), m = read();
  if (n > m) swap(n, m), rot = 1;
  qq = read();
  rep(i, 1, qq) {
    int x = read(), y = read();
    if (rot) swap(x, y);
    qwq[x][y] = 1;
  }

  /*if (min(n, m) <= 20) {
    dfs(1, 1, 0);
    cout << ans << '\n';
    return 0;
  }*/

  far[0][1] = 1;
  for (int i = 2; i <= n; i++) far[0][i] = -1e9;

  for (int step = 1; ; step++) {
    for (int i = 1; i <= n; i++) far[step & 1][i] = -1e9;
    for (int x = 1; x <= n; x++) {
      int y = far[~step & 1][x];
      int can = x + y + (qwq[x].find(y) != qwq[x].end());
      if (can < 1) continue;
      pii go = {min(n, can), y};
      ckmax(far[step & 1][go.fir], go.sec);
      go = {x, min(m, can)};
      ckmax(far[step & 1][go.fir], go.sec);
    }
    if (far[step & 1][n] == m) {
      printf("%d\n", step);
      return 0;
    }
  }
  return 0;
}