#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
using ld = long double;
// using lll = __int128;
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
inline void print(ll x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 2e3 + 5;
constexpr int mod = 1e9 + 7;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int n, f[N][N << 1], g[N][N << 1];
char s[N], t[N];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> s + 1 >> t + 1;
    for(int i = 0; i <= n; i++) {
      memset(f[i], 0, sizeof(f[i]));
      memset(g[i], 0, sizeof(g[i]));
    }
    f[0][N] = 1;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < N << 1; j++)
        if(f[i][j] || g[i][j])
          for(int x = 0; x < 2; x++)
            for(int y = 0; y < 2; y++) {
              if(s[i + 1] != '?' && s[i + 1] != x + '0') continue;
              if(t[i + 1] != '?' && t[i + 1] != y + '0') continue;
              int nx = x ^ (i & 1), ny = y ^ (i & 1);
              add(f[i + 1][j + nx - ny], f[i][j]);
              add(g[i + 1][j + nx - ny], g[i][j]);
              add(g[i + 1][j + nx - ny], 1ll * f[i][j] * abs(j - N) % mod);
            }
    cout << g[n][N] << "\n";
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/7
author: Alex_Wei
start coding at 10:11
finish debugging at 10:17
*/