#include <bits/stdc++.h>
using namespace std;

typedef class DSU {
  public:
    vector<int> f;

    void init(int n) {
      f.assign(n + 1, 0);
      for (int i = 0; i <= n; i++) {
        f[i] = i;
      }
    }

    int find(int x) {
      return f[x] == x ? x : (f[x] = find(f[x]));
    }
    bool unit(int x, int y) {
      x = find(x), y = find(y);
      return (x ^ y) ? (f[x] = y, true) : false;
    }

    int operator [] (int p) {
      return find(p);
    }
} DSU;

typedef class Blossom {
  public:
    int n;
    int tt;
    DSU dsu;
    queue<int> Q;
    vector<vector<int>> G;
    vector<int> mat, vis, col, pre;

    void init(int n) {
      this->n = n;
      tt = 0;
      mat.assign(n + 1, 0);
      vis.assign(n + 1, 0);
      col.assign(n + 1, 0);
      pre.assign(n + 1, 0);
      G.assign(n + 1, vector<int>());
    }

    void add_edge(int u, int v) {
      G[u].push_back(v);
      G[v].push_back(u);
    }

    int lca(int x, int y) {
      ++tt;
      x = dsu[x], y = dsu[y];
      while (true) {
        if (x) {
          if (vis[x] == tt)
            return x;
          vis[x] = tt;
          x = dsu[pre[mat[x]]];
        }
        swap(x, y);
      }
      assert(false);
      return -1;
    }
    void blossom(int x, int y, int z) {
      while (dsu[x] ^ dsu[z]) {
        pre[x] = y;
        y = mat[x];
        if (!col[y]) {
          col[y] = 1;
          Q.push(y);
        }
        if (dsu[x] == x) {
          dsu.unit(x, z);
        }
        if (dsu[y] == y) {
          dsu.unit(y, z);
        }
        x = pre[y];
      }
    }

    bool augment(int s) {
      dsu.init(n);
      fill(pre.begin(), pre.end(), 0);
      fill(col.begin(), col.end(), -1);
      Q = queue<int>();
      Q.push(s);
      col[s] = 1;
      while (!Q.empty()) {
        int p = Q.front();
        Q.pop();
        for (auto e : G[p]) {
          if (col[e] < 0) {
            col[e] = 0;
            pre[e] = p;
            if (!mat[e]) {
              int x = p, y = e, ls;
              while (y) {
                ls = mat[x];
                mat[x] = y;
                mat[y] = x;
                y = ls;
                x = pre[y];
              } 
              return true;
            } else {
              col[mat[e]] = 1;
              Q.push(mat[e]);
            }
          } else if (col[e] && dsu[e] != dsu[p]) {
            int g = lca(p, e);
            blossom(p, e, g);
            blossom(e, p, g);
          }
        }
      }
      return false; 
    }

    int max_matching() {
      int ret = 0;
      for (int i = 1; i <= n; i++) {
        if (!mat[i]) {
          ret += augment(i);
        }
      }
      return ret;
    }
} Blossom;

int n, m;
char s[155];
Blossom B;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    B.init(2 * n + m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      B.add_edge(2 * i - 1, 2 * i);
      for (int j = 1; j <= m; j++) {
        if (s[j] == '1') {
          B.add_edge(2 * i - 1, 2 * n + j);
          B.add_edge(2 * i, 2 * n + j);
        }
      }
    }
    printf("%d\n", B.max_matching() - n);
  }
  return 0;
}