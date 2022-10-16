#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using i128 = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline ll read() {
  ll x = 0, sgn = 0;
  char s = getchar();
  while(!isdigit(s)) sgn |= s == '-', s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
ll n, m, f[64][2][2][2]; // bit, carry, popcount, limit
void solve() {
  cin >> n >> m;
  memset(f, 0, sizeof(f));
  f[63][0][0][1] = 1;
  for(int i = 63; i; i--)
    for(int c = 0; c < 2; c++)
      for(int p = 0; p < 2; p++)
        for(int l = 0; l < 2; l++)
          if(f[i][c][p][l]) {
            for(int v = 0; v < 2; v++)
              for(int cc = 0; cc < 2; cc++) {
                int b = m >> i - 1 & 1, d = n >> i - 1 & 1;
                if(!b && l && v) continue;
                if((cc + v + d >= 2) != c) continue;
                f[i - 1][cc][p ^ cc ^ d][l & (v == b)] += f[i][c][p][l];
              }
          }
  cout << f[0][0][1][0] << "\n";
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve();
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/25
author: Alex_Wei
start coding at
finish debugging at 9:26
*/