#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 2e5 + 10;
int n, q, tot, data[maxn];

vector <int> E[maxn];

int fa[maxn], tid[maxn], sz[maxn];

void dfs(int u, int f) {
  static int now;
  tid[u] = ++now;
  fa[u] = f, sz[u] = 1;
  for (int v : E[u]) if (v != f) {
    dfs(v, u), sz[u] += sz[v];
  }
}

int main() {
  cin >> n >> q;
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    E[u].push_back(v), E[v].push_back(u);
  }
  dfs(1, 0);
  while (q--) {
    tot = 0;
    int k = read();
    while (k--) {
      int u = read();
      if (u != 1) data[++tot] = fa[u];
    }
    if (!tot) {
      puts("YES"); continue;
    }
    sort(data + 1, data + tot + 1, [] (int x, int y) {
      return tid[x] < tid[y];
    });
    tot = unique(data + 1, data + tot + 1) - data - 1;
    bool flg = 1;
    int lst = n + 1;
    rep(i, 1, tot) {
      int pos = tid[data[i]] + sz[data[i]] - 1;
      if (pos > lst) {
        flg = 0; break;
      } else {
        lst = pos;
      }
    }
    puts(flg ? "YES" : "NO");
  }
  return 0;
}