// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 45;
const int K = 15;

vector<int> zz[K];
int used[N], n, k;

int _[K][N];
void dfs(int u, int zero) {
  if (u == k + 1) {
    rep(i, 1, zero) if (used[i] != 0) {
      puts("REJECTED"), exit(0);
    }
    rep(i, zero + 1, n) if (used[i] != 1) {
      puts("REJECTED"), exit(0);
    }
    return ;
  }
  memcpy(_[u], used, sizeof(used));
  int z0 = 0, z1 = 0;
  for (auto v: zz[u]) {
    if (used[v] == -1) z1++;
    if (used[v] == 0) z0++;  
  }
  rep(i, 0, z1) {
    rep(j, 0, SZ(zz[u]) - 1) used[zz[u][j]] = (j >= i + z0);
    dfs(u + 1, zero + i); 
  }
  memcpy(used, _[u], sizeof(_[u]));
}

int main() {
  n = read(), k = read();
  if (n == 1) return puts("ACCEPTED"), 0;
  rep(i, 1, k) {
    int s = read();
    while (s--) {
      int x = read();
      zz[i].pb(x);
    }
  }
  rep(i, 1, n) used[i] = -1;
  dfs(1, 0);
  puts("ACCEPTED");
  return 0;
}