#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
inline int read() {
  int x = 0;
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
constexpr int K = 1 << 8;
constexpr int N = 1e5 + 5;
constexpr int inf = 0x3f3f3f3f;
char s[N];
vector<int> buc[8];
ll ans[18], h[8][K];
int n, col[N], T[N], f[N][8], g[8][8];
void FWT(ll *f, int op) {
  for(int k = 1; k < K; k <<= 1)
    for(int i = 0; i < K; i += k << 1)
      for(int j = 0; j < k; j++)
        f[i | j] += op * f[i | j | k];
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> s + 1;
  memset(f, 0x3f, sizeof(f));
  memset(g, 0x3f, sizeof(g));
  for(int i = 1; i <= n; i++) buc[col[i] = s[i] - 'a'].push_back(i);
  for(int c = 0; c < 8; c++) {
    g[c][c] = 0;
    if(buc[c].empty()) continue;
    ans[1] += 1ll * buc[c].size() * (buc[c].size() - 1) / 2;
    queue<int> q;
    for(int it : buc[c]) f[it][c] = 0, q.push(it);
    while(!q.empty()) {
      int t = q.front();
      q.pop();
      if(g[col[t]][c] == inf) {
        g[col[t]][c] = f[t][c];
        for(int it : buc[col[t]]) {
          if(f[it][c] != inf) continue;
          f[it][c] = f[t][c] + 1, q.push(it);
        }
      }
      for(int d : {-1, 1}) {
        if(t + d < 1 || t + d > n) continue;
        if(f[t + d][c] == inf) f[t + d][c] = f[t][c] + 1, q.push(t + d);
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 8; j++)
      if(f[i][j] == g[col[i]][j])
        T[i] |= 1 << j;
    h[col[i]][T[i]]++;
  }
  for(int i = 0; i < 8; i++) FWT(h[i], 1);
  for(int x = 0; x < 8; x++)
    for(int y = x + 1; y < 8; y++) {
      if(buc[x].empty() || buc[y].empty()) continue;
      int v = N;
      ll v0 = 0, v1 = 1ll * buc[x].size() * buc[y].size(), v2 = 0;
      for(int c = 0; c < 8; c++) v = min(v, g[x][c] + g[y][c] + 1);
      int S = 0, _S = 0;
      for(int c = 0; c < 8; c++)
        if(g[x][c] + g[y][c] + 1 == v) S |= 1 << c;
        else if(g[x][c] + g[y][c] + 1 == v + 1) _S |= 1 << c;
      static ll a[K], b[K];
      memset(a, 0, sizeof(a));
      for(int i = 0; i < K; i++) a[i] = h[x][i] * h[y][i];
      FWT(a, -1);
      for(int i = 0; i < K; i++) if(i & S) v0 += a[i];
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));
      for(int it : buc[x]) if(!(T[it] & S)) a[T[it]]++;
      for(int it : buc[y]) if(!(T[it] & S)) b[T[it]]++;
      FWT(a, 1), FWT(b, 1);
      for(int i = 0; i < K; i++) a[i] *= b[i];
      FWT(a, -1);
      for(int i = 0; i < K; i++) if(!(i & _S)) v2 += a[i];
      v1 -= v0 + v2;
      ans[v] += v0;
      ans[v + 1] += v1;
      ans[v + 2] += v2;
    }
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= min(n, i + 15); j++) {
      int v = N;
      for(int c = 0; c < 8; c++) v = min(v, f[i][c] + f[j][c] + 1);
      if(j - i < v) ans[v]--, ans[j - i]++;
    }
  }
  for(int i = 15; i; i--) if(ans[i]) cout << i << " " << ans[i] << "\n", exit(0);
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/5
author: Alex_Wei
start coding at 20:16
finish debugging at 21:47
*/