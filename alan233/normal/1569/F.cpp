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

const int N = 12;

bool mp[N][N];
int n, m, K;

int be[N], num[7];
int vis[1 << N][N][N], ok[1 << N][N][N], tag;
bool dfs(int mask, int u, int v) {
  if (!mask) return 1;
  if (vis[mask][u][v] == tag) return ok[mask][u][v];
  vis[mask][u][v] = tag;
  rep(i, 0, n - 1) if ((mask >> i & 1)) {
    rep(j, i + 1, n - 1) if (i != j && (mask >> j & 1) && be[i] == be[j]) {
      if (!(mp[u][i] && mp[v][j]) && !(mp[u][j] && mp[v][i])) continue;
//      printf("dfs %d %d %d -> i = %d, j = %d\n", mask, u, v, i, j);
      if (dfs(mask ^ (1 << i) ^ (1 << j), i, j)) return ok[mask][u][v] = 1;
    }
  }
  return ok[mask][u][v] = 0;
}
bool chk(int k) {
  int mask = (1 << n) - 1;
  rep(i, 0, n - 1) {
    rep(j, i + 1, n - 1) {
      ++tag;
//      cerr << "i = " << i << ", j = " << j << '\n';
//      printf("i = %d, j = %d, ", i, j);
//      printf("1 = %d, 2 = %d, 3 = %d\n", mp[i][j], be[i] == be[j], dfs(mask ^ (1 << i) ^ (1 << j), i, j));
      if (mp[i][j] && be[i] == be[j] && dfs(mask ^ (1 << i) ^ (1 << j), i, j)) {
        return 1;
      }
    }
  }
  return 0;
}
ll ans = 0;
void dfs(int u, int k) {
  if (u == n) {
//    cerr << "?!?\n";
    bool ok = 1; rep(i, 1, k) ok &= ~num[i] & 1; if (!ok) return ;
//    cerr << "!\n";
    if (chk(k)) {
//      cerr << "valid!\n"; 
      ll cf = 1;
      per(i, K, K - k + 1) cf *= i;
      ans += cf;
    }
//    cerr << "?\n";
//    system("pause");
    return ;
  }
  for (int i = 1; i <= min(6, k + 1); i++) {
    be[u] = i, num[i]++;
    dfs(u + 1, max(k, i));
    be[u] = 0, num[i]--;
  }
}

bool _[N]; int ah = 0;
void d(int u) {
  _[u] = 1, ah++;
  for (int i = 0; i < n; i++) if (!_[i] && mp[u][i]) {
    d(i);
  }
}

int main() {
  n = read(), m = read(), K = read();
  rep(i, 1, m) {
    int u = read() - 1, v = read() - 1;
    mp[u][v] = mp[v][u] = 1;
  }
//  rep(i, 0, n - 1) {
//    rep(j, 0, n - 1) {
//      printf("%d ", mp[i][j]);
//    }
//    puts("");
//  }
//  system("pause");
  d(0); if (ah != n) return puts("0"), 0;
  dfs(0, 0);
  print(ans, '\n');
  return 0;
}