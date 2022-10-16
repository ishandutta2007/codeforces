#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
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
constexpr int N = 1e5 + 5;
constexpr int B = 320;
int n, w, blk[N];
vector<int> buc[N];
struct blocker {
  int dt, hd, tl, d[B];
  ll a[B], laz;
  ll cross(int i, int j, int k) {return (j - i) * (a[k] - a[j]) - (k - j) * (a[j] - a[i]);}
  void rebuild() {
    hd = 0, tl = -1;
    for(int i = 0; i < B; i++) {
      while(hd < tl && cross(d[tl - 1], d[tl], i) >= 0) tl--;
      d[++tl] = i;
    }
  }
  pll modify(int sz) {
    if(sz == B) laz++;
    else {
      for(int i = 0; i < sz; i++) a[i] += dt + i;
      for(int i = 0; i < B; i++) a[i] += laz * (dt + i);
      laz = 0, rebuild();
    }
    while(hd < tl && a[d[hd]] + laz * d[hd] <= a[d[hd + 1]] + laz * d[hd + 1]) hd++;
    return {a[d[hd]] + laz * (d[hd] + dt), d[hd] + dt};
  }
} b[B];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> w;
  for(int i = 0; i < N; i++) blk[i] = i / B;
  for(int i = 0; i < B; i++) b[i].d[0] = B - 1, b[i].dt = i * B;
  int num = n, mxb = 0;
  for(int i = 1, a, b; i <= n; i++) {
    a = read(), b = read();
    mxb = max(mxb, b);
    buc[b].push_back(a);
  }
  pll ans = {0, 0};
  for(int i = 0; i <= mxb + 1; i++) {
    cout << ans.first + 1ll * num * i * w << " " << ans.second << "\n";
    for(int it : buc[i]) {
      int c = blk[it];
      for(int i = 0; i < c; i++) ans = max(ans, b[i].modify(B));
      ans = max(ans, b[c].modify(it - c * B + 1)), num--;
    }
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/17
author: Alex_Wei
start coding at 12:24
finish debugging at 13:45
*/