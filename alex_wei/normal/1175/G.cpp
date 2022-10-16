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
constexpr int N = 2e4 + 5;
constexpr int K = N << 4;
int n, T, a[N], f[N], g[N];
int top, stc[N];
int node, R[N], ls[K], rs[K], val[K];
int cnt, k[N], b[N];
int get(int id, int x) {return k[id] * x + b[id];}
void modify(int pre, int &x, int l, int r, int v) {
  x = ++node;
  ls[x] = ls[pre], rs[x] = rs[pre], val[x] = val[pre];
  int m = l + r >> 1;
  if(get(v, m) < get(val[x], m)) swap(val[x], v);
  if(get(v, l) < get(val[x], l)) modify(ls[pre], ls[x], l, m, v);
  if(get(v, r) < get(val[x], r)) modify(rs[pre], rs[x], m + 1, r, v);
}
int query(int l, int r, int p, int x) {
  int ans = get(val[x], p);
  if(l == r || !x) return ans;
  int m = l + r >> 1;
  return min(ans, p <= m ? query(l, m, p, ls[x]) : query(m + 1, r, p, rs[x]));
}
deque<int> d[N];
ll dx(int i, int j) {return j - i;}
ll dy(int i, int j) {return f[j - 1] - f[i - 1];}
ll cross(int i, int j, int k) {
  return dx(i, j) * dy(j, k) - dy(i, j) * dx(j, k);
}
void merge(deque<int> &u, deque<int> &v) {
  if(u.size() < v.size()) {
    while(!u.empty()) {
      while(v.size() > 1 && cross(u.back(), v[0], v[1]) <= 0) v.pop_front();
      v.push_front(u.back()), u.pop_back();
    }
  }
  else {
    while(!v.empty()) {
      while(u.size() > 1 && cross(u[u.size() - 2], u.back(), v[0]) <= 0) u.pop_back();
      u.push_back(v.front()), v.pop_front();
    }
    v.swap(u);
  }
}
int calc(deque<int> &d, int k) {
  int l = 0, r = d.size() - 1;
  while(l < r) {
    int m = l + r >> 1;
    if(dx(d[m], d[m + 1]) * k >= dy(d[m], d[m + 1])) l = m + 1;
    else r = m;
  }
  return f[d[l] - 1] - (d[l] - 1) * k;
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> T, b[0] = INT_MAX >> 1;
  for(int i = 1; i <= n; i++) a[i] = read();
  memset(f, 0x3f, sizeof(f)), f[0] = 0;
  for(int _ = 1; _ <= T; _++) {
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
    memset(val, 0, sizeof(val));
    node = cnt = top = 0;
    for(int i = 1; i <= n; i++) {
      d[i].clear(), d[i].push_back(i);
      while(top && a[stc[top]] <= a[i]) merge(d[stc[top--]], d[i]);
      k[++cnt] = a[i], b[cnt] = calc(d[i], a[i]);
      modify(R[stc[top]], R[i], 1, n, cnt);
      stc[++top] = i, g[i] = query(1, n, i, R[i]);
    }
    swap(f, g);
  }
  cout << f[n] << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/12
author: Alex_Wei
start coding at 16:10
finish debugging at 16:39
*/