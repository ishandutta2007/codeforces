#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ull = unsigned long long;
inline ll read() {
  ll x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 512;
ll k, t, a[N][N], b[N][N], c[N][N];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> k;
  int S = (1 << k) - 1;
  for(int i = 0; i < 1 << k; i++)
    for(int j = 0; j < 1 << k; j++)
      a[i][j] = read();
  cin >> t;
  for(int i = 0; i < t; i++) {
    int x = read(), y = read();
    b[x - 1][y - 1] = 1;
  }
  for(int _ = 0; _ < k; _++) {
    memset(c, 0, sizeof(c));
    for(int x = 0; x < 1 << k; x++)
      for(int y = 0; y < 1 << k; y++)
        if(b[x][y])
          for(int u = 0; u < 1 << k; u++)
            for(int v = 0; v < 1 << k; v++)
              if(a[u][v])
                c[(x + u) & S][(y + v) & S] ^= a[u][v];
    memcpy(a, c, sizeof(c));
    memset(c, 0, sizeof(c));
    for(int x = 0; x < 1 << k; x++)
      for(int y = 0; y < 1 << k; y++)
        if(b[x][y])
          for(int u = 0; u < 1 << k; u++)
            for(int v = 0; v < 1 << k; v++)
              if(b[u][v])
                c[(x + u) & S][(y + v) & S] ^= 1;
    memcpy(b, c, sizeof(c));
  }
  int ans = 0;
  for(int i = 0; i < 1 << k; i++)
    for(int j = 0; j < 1 << k; j++)
      ans += a[i][j] > 0;
  cout << ans << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/16
author: Alex_Wei
start coding at 11:25
finish debugging at 11:43
*/