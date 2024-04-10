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
constexpr int N = 720720;
constexpr int mod = 998244353;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int n, a, x, y, k, M, f[N];
int sum, ans, pw[20];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> a >> x >> y >> k >> M;
  for(int i = pw[0] = 1; i <= k; i++) pw[i] = 1ll * pw[i - 1] * n % mod;
  for(int i = 0; i < n; i++) {
    if(i) a = (1ll * x * a + y) % M;
    add(sum, a / N * N), f[a % N]++;
  }
  ans = 1ll * k * sum % mod * pw[k - 1] % mod;
  for(int i = 1; i <= k; i++) {
    for(int j = 0; j < N; j++) {
      int c = f[j];
      if(!c) continue;
      add(ans, 1ll * c * j % mod * pw[k - i] % mod);
      f[j] = 1ll * c * (n - 1) % mod, add(f[j - j % i], c);
    }
  }
  cout << ans << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/5
author: Alex_Wei
start coding at 18:27
finish debugging at 18:37
*/