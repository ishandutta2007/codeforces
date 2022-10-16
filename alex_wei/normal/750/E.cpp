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
constexpr int N = 2e5 + 5;
constexpr int inf = 0x3f3f3f3f;
struct mat {
  int a[5][5];
  mat operator * (const mat &x) const {
    mat z;
    memset(z.a, 0x3f, sizeof(z,a));
    for(int i = 0; i < 5; i++)  
      for(int j = 0; j < 5; j++)
        for(int k = 0; k < 5; k++)
          z.a[i][j] = min(z.a[i][j], a[i][k] + x.a[k][j]);
    return z;
  }
  mat operator / (const mat &x) const {
    mat z;
    memset(z.a, 0x3f, sizeof(z,a));
    for(int j = 0; j < 5; j++)
      for(int k = 0; k < 5; k++)
        z.a[0][j] = min(z.a[0][j], a[0][k] + x.a[k][j]);
    return z;
  }
} val[N << 2], dig[10], I, cur;
int n, q;
char s[N];
void build(int l, int r, int x) {
  if(l == r) return val[x] = dig[s[l] - '0'], void();
  int m = l + r >> 1;
  build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
  val[x] = val[x << 1] * val[x << 1 | 1];
}
void query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return cur = cur / val[x], void();
  int m = l + r >> 1;
  if(ql <= m) query(l, m, ql, qr, x << 1);
  if(m < qr) query(m + 1, r, ql, qr, x << 1 | 1);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  for(int i = 0; i < 10; i++) {
    memset(dig[i].a, 0x3f, sizeof(dig[i].a));
    if(i == 2) dig[i].a[0][0] = 1, dig[i].a[0][1] = 0;
    else dig[i].a[0][0] = 0;
    if(i == 0) dig[i].a[1][1] = 1, dig[i].a[1][2] = 0;
    else dig[i].a[1][1] = 0;
    if(i == 1) dig[i].a[2][2] = 1, dig[i].a[2][3] = 0;
    else dig[i].a[2][2] = 0;
    if(i == 7) dig[i].a[3][3] = 1, dig[i].a[3][4] = 0;
    else if(i == 6) dig[i].a[3][3] = 1;
    else dig[i].a[3][3] = 0;
    dig[i].a[4][4] = i == 6;
  }
  memset(I.a, 0x3f, sizeof(I.a)), I.a[0][0] = 0;
  cin >> n >> q >> s + 1, build(1, n, 1);
  for(int i = 1; i <= q; i++) {
    int l = read(), r = read();
    cur = I, query(1, n, l, r, 1);
    if(cur.a[0][4] > n) puts("-1");
    else print(cur.a[0][4]), putchar('\n');
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/28
author: Alex_Wei
start coding at 13:07
finish debugging at 13:21
*/