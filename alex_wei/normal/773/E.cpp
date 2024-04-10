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
constexpr int N = 5e5 + 5;
int n, num[N << 3], val[N << 3], laz[N << 3];
void tag(int x, int v) {val[x] += v, laz[x] += v;}
void down(int x) {if(laz[x]) tag(x << 1, laz[x]), tag(x << 1 | 1, laz[x]), laz[x] = 0;}
void build(int l, int r, int x) {
  if(l == r) return val[x] = l, void();
  int m = l + r >> 1;
  build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
  val[x] = min(val[x << 1], val[x << 1 | 1]);
}
void modify(int l, int r, int p, int x) {
  num[x]++;
  if(l == r) return;
  int m = l + r >> 1;
  if(p <= m) modify(l, m, p, x << 1);
  else modify(m + 1, r, p, x << 1 | 1);
}
void add(int l, int r, int p, int x) {
  if(p <= l) return tag(x, -1);
  int m = l + r >> 1;
  down(x);
  if(p <= m) add(l, m, p, x << 1);
  add(m + 1, r, p, x << 1 | 1);
  val[x] = min(val[x << 1], val[x << 1 | 1]);
}
int binary(int l, int r, int x, int pref) {
  if(-(pref + num[x]) > r) return -N;
  if(l == r) return l;
  int m = l + r >> 1;
  int res = binary(l, m, x << 1, pref);
  return res == -N ? binary(m + 1, r, x << 1 | 1, pref + num[x << 1]) : res;
}
int query(int l, int r, int p, int x) {
  if(p <= l) return val[x];
  int m = l + r >> 1, ans = 0;
  down(x);
  if(p <= m) ans = min(ans, query(l, m, p, x << 1));
  ans = min(ans, query(m + 1, r, p, x << 1 | 1));
  return ans;
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n, build(-N, N, 1);
  for(int i = 1; i <= n; i++) {
    int a = read();
    modify(-N, N, a, 1), add(-N, N, a, 1);
    int p = binary(-N, N, 1, 0);
    cout << i + query(-N, N, p, 1) << "\n";
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/22
author: Alex_Wei
start coding at 
finish debugging at 10:09
*/