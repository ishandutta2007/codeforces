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
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 100 + 5;
constexpr int mod = 1e9 + 7;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}
int n, R, p1, p2, p3, p4;
bool in(int x, int y) {return x * x + y * y <= R * R;}
struct row {
  int a[N];
  void print() {
    for(int i = 0; i <= n + 1; i++) cout << a[i] << " ";
    cout << "\n";
  }
  row operator + (const row &x) const {
    row z = *this;
    for(int i = 0; i < N; i++) add(z.a[i], x.a[i]);
    return z;
  }
  row operator - (const row &x) const {
    row z = *this;
    for(int i = 0; i < N; i++) add(z.a[i], mod - x.a[i]);
    return z;
  }
  row operator * (const int &x) const {
    row z = *this;
    for(int i = 0; i < N; i++) z.a[i] = 1ll * z.a[i] * x % mod;
    return z;
  }
  row operator / (const int &x) const {return *this * ksm(x, mod - 2);}
} I, A[N], f[N][N];
#define xx (x + R + 2)
#define yy (y + R + 2)
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> R >> p1 >> p2 >> p3 >> p4, n = R + R;
  int inv = ksm(p1 + p2 + p3 + p4, mod - 2);
  p1 = 1ll * p1 * inv % mod;
  p2 = 1ll * p2 * inv % mod;
  p3 = 1ll * p3 * inv % mod;
  p4 = 1ll * p4 * inv % mod;
  I.a[n + 1] = 1;
  for(int x = -R; x <= R; x++) {
    int y = sqrt(R * R - x * x);
    f[xx][yy].a[x + R] = 1;
  }
  for(int y = R; y >= -R; y--)
    for(int x = -R; x <= R; x++)
      if(in(x, y) && in(x, y + 1)) {
        f[xx][yy] = (f[xx][yy + 1] - f[xx - 1][yy + 1] * p1 -
          f[xx + 1][yy + 1] * p3 - f[xx][yy + 2] * p4 - I) / p2;
      }
  for(int y = R; y >= -R; y--)
    for(int x = -R; x <= R; x++)
      if(in(x, y) && !in(x, y - 1)) {
        A[x + R] = f[xx][yy] - f[xx - 1][yy] * p1 -
          f[xx][yy - 1] * p2 - f[xx + 1][yy] * p3 - f[xx][yy + 1] * p4 - I;
        A[x + R].a[n + 1] = mod - A[x + R].a[n + 1];
      }
  for(int i = 0; i <= n; i++) {
    for(int j = i + 1; j <= n && !A[i].a[i]; j++) if(A[j].a[i]) swap(A[i], A[j]);
    assert(A[i].a[i]);
    A[i] = A[i] / A[i].a[i];
    for(int j = 0; j <= n; j++) if(i != j) A[j] = A[j] - A[i] * A[j].a[i];
  }
  int ans = 0;
  for(int i = 0; i <= n; i++) add(ans, 1ll * f[R + 2][R + 2].a[i] * A[i].a[n + 1] % mod);
  cout << (ans + f[R + 2][R + 2].a[n + 1]) % mod << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/25
author: Alex_Wei
start coding at 15:58
finish debugging at 16:55
*/