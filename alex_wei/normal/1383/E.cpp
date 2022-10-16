#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
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
constexpr int N = 1e6 + 5;
constexpr int mod = 1e9 + 7;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int n, cnt, zero, f[N], s[N], a[N], stc[N], top;
char t[N];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> t + 1, n = strlen(t + 1);
  for(int i = 1; i <= n; i++) {
    if(t[i] == '1') a[++cnt] = zero, zero = 0;
    else zero++;
  }
  a[++cnt] = zero;
  if(cnt == 1) cout << n << "\n", exit(0);
  int ans = f[1] = s[1] = stc[0] = 1;
  for(int i = 2; i < cnt; i++) {
    f[i] = 1ll * f[i - 1] * (a[i] + 1) % mod;
    while(top && a[i] >= a[stc[top]]) {
      int coef = s[stc[top] - 1] + mod - s[stc[top - 1] - 1];
      add(f[i], 1ll * coef * (a[i] - a[stc[top]]) % mod), top--;
    }
    stc[++top] = i, add(ans, f[i]);
    s[i] = s[i - 1], add(s[i], f[i]);
  }
  cout << 1ll * ans * (a[1] + 1) % mod * (a[cnt] + 1) % mod << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/2
author: Alex_Wei
start coding at 11:17
finish debugging at 11:31
*/