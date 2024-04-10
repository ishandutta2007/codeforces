// Author: wlzhouzhuan
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

const int inf = 1e9;

#define run(i, l, r) for (int i = l; i < r; i++)
// f[mask][j]:  mask  j  () 
int f[1 << 14][101];
// g[mask][j]:  mask  j  t[j]  
int g[1 << 14][101];

struct node {
  int x, y, t;
  friend bool operator < (const node &x, const node &y) {
    return x.t < y.t;
  }
} a[101];

int xa[14], ya[14];
int dist[101], ans = 0, n, m;

int main() {
  n = read(), m = read();
  run(i, 0, n) xa[i] = read(), ya[i] = read();
  run(i, 0, m) a[i].x = read(), a[i].y = read(), a[i].t = read();
  sort(a, a + m);
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  run(S, 0, 1 << n) {
    per(i, m - 1, 0) ckmin(f[S][i], f[S][i + 1]);
    run(y, 0, m) {
      dist[y] = inf;
      run(i, 0, n) if (S >> i & 1) {
        ckmin(dist[y], abs(xa[i] - a[y].x) + abs(ya[i] - a[y].y));
      }
    }
    run(y, 0, m) {
      g[S][y] = -inf;
      if (S == 0) g[S][y] = 1; //  
      rep(i, 0, y) { //  
        if (f[S][i] + dist[y] <= a[y].t) {
          ckmax(g[S][y], i + 1);
        }
      }
      run(x, 0, y) { //  
        if (a[x].t + abs(a[x].x - a[y].x) + abs(a[x].y - a[y].y) <= a[y].t ||
            a[x].t + dist[y] <= a[y].t) {
          ckmax(g[S][y], g[S][x] + 1);   
        }
      }
      ckmax(ans, g[S][y]);
    }
    run(i, 0, n) { //  
      if (S >> i & 1) continue;
      int new_dist = inf;
      run(j, 0, n) {
        if (S >> j & 1) {
          ckmin(new_dist, abs(xa[i] - xa[j]) + abs(ya[i] - ya[j]));
        }
      }
      run(j, 0, m) { // 
        if (g[S][j] >= 0) {
          ckmin(f[S ^ 1 << i][g[S][j]], a[j].t + min(new_dist, abs(a[j].x - xa[i]) + abs(a[j].y - ya[i])));
        } 
      }
      if (S == 0) new_dist = 0;
      rep(j, 0, m) { // 
        ckmin(f[S ^ 1 << i][j], f[S][j] + new_dist); 
      }
    } 
  }
  printf("%d\n", ans);
  return 0;
}