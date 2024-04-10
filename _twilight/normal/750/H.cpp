#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>

typedef class Dsu {
  public:
    int *uf, *sz;
    boolean durable;
    stack<pii> opt;

    void init(int n) {
      durable = false;
      uf = new int[(n + 1)];
      sz = new int[(n + 1)];
      for (int i = 0; i <= n; i++)
        uf[i] = i, sz[i] = 1;
    }

    int _find(int x) {
      return uf[x] == x ? x : find(uf[x]);
    }
    int _find2(int x) {
      while (x ^ uf[x])
        x = uf[x];
      return x;
    }
    int find(int x) {
      return durable ? _find2(x) : _find(x);
    }
    boolean unit(int x, int y) {
      x = find(x), y = find(y); 
      if (sz[x] > sz[y])
        swap(x, y);
      if (x ^ y) {
        if (durable) {
          opt.push(pii(x, uf[x]));
        }
        uf[x] = y;
        sz[y] += sz[x];
        return true;
      }
      return false;
    }

    void revoke() {
      int x = opt.top().first, fx = opt.top().second;
      int y = find(x);
      sz[y] -= sz[x];
      uf[x] = fx;
      opt.pop();
    }
    boolean have_last() {
      return !opt.empty();
    }
    int operator [] (int x) {
      return find(x);
    }
} Dsu;

const int N = 1005;

int n, m, q;
char G[N][N];
vector<pii> mov;
set<int> nearby[N * N];

int S, T;
Dsu uf;

boolean in_range(int x, int y) {
  return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1;
}
int id(int x, int y) {
  //  assert(in_range(x, y));
  return x * (m + 2) + y;
}
boolean can_block(int x, int y) {
  if (!in_range(x, y))
    return false;  
  if (x < 1 || x > n || y < 1 || y > m)
    return false;    
  if (x == 1 && y == 1)
    return false;    
  if (x == n && y == m)
    return false;
  return true;
}

int add_around(int x, int y) {
  int p = id(x, y), rt = 0;
  for (auto d : mov) {
    int nx = d.first + x, ny = d.second + y;
    if (in_range(nx, ny) && G[nx][ny] == '#')
      rt += uf.unit(p, id(nx, ny));
  }
  return rt;
}

int main() {
  //  freopen("a.in", "r", stdin);
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (dx || dy) {
        mov.emplace_back(dx, dy);
      }
    }
  }
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", G[i] + 1);
  }
  G[0][0] = G[1][0] = G[0][1] = '.';
  G[n + 1][m + 1] = G[n][m + 1] = G[n + 1][m] = '.';
  for (int i = 2; i <= m + 1; i++) {
    G[0][i] = '#';
    G[n + 1][i - 2] = '#';
  }
  for (int i = 2; i <= n + 1; i++) {
    G[i][0] = '#';
    G[i - 2][m + 1] = '#';
  }
  uf.init((n + 2) * (m + 2));
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      if (G[i][j] != '#')
        continue;
      add_around(i, j);  
    }
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      if (G[i][j] == '#') {
        for (auto d : mov) {
          int x = i + d.first, y = j + d.second;
          if (!can_block(x, y) || G[x][y] != '.')
            continue;
          for (auto d2 : mov) {
            int nx = x + d2.first, ny = y + d2.second;
            if (in_range(nx, ny) && uf[id(nx, ny)] ^ uf[id(i, j)]) {
              nearby[uf[id(i, j)]].insert(uf[id(nx, ny)]);
            }
          }
        }
      }
    }
  }
  S = uf[id(0, 2)], T = uf[id(2, 0)];
  uf.durable = true;
  while (q--) {
    int num;
    vector<pii> P;
    scanf("%d", &num);
    for (int i = 0, x, y; i < num; i++) {
      scanf("%d%d", &x, &y);
      G[x][y] = '#';
      P.emplace_back(x, y);
    }
    vector<int> block;
    vector<int> bs {uf[S]}, bt {uf[T]};
    for (auto p : P) {
      int x = p.first, y = p.second;
      for (auto d : mov) {
        int nx = d.first + x, ny = d.second + y;
        if (in_range(nx, ny) && G[nx][ny] == '#') {
          block.push_back(uf[id(nx, ny)]);
          uf.unit(id(x, y), id(nx, ny));
        }
      }
    }
    if (uf[S] == uf[T]) {
      puts("NO");
      goto query_end;
    }
    for (auto p : P) {
      int px = p.first, py = p.second;
      for (auto d : mov) {
        int x = px + d.first, y = py + d.second;
        if (!can_block(x, y) || G[x][y] != '.')
          continue;
        boolean ns = false, nt = false;
        for (auto d2 : mov) {
          int nx = x + d2.first, ny = y + d2.second;
          if (!ns && uf[id(nx, ny)] == uf[S])
            ns = true;
          if (!nt && uf[id(nx, ny)] == uf[T])
            nt = true;
        }
        if (ns && nt) {
          puts("NO");
          goto query_end;
        }
      }
    }
    sort(block.begin(), block.end());
    block.erase(unique(block.begin(), block.end()), block.end());
    for (auto bid : block) {
      int fx = uf[bid];
      if (fx == uf[S]) {
        bs.push_back(bid);
      } else if (fx == uf[T]) {
        bt.push_back(bid);
      }
    }
    for (auto x : bs) {
      for (auto y : bt) {
        if (nearby[x].count(y)) {
          puts("NO");
          goto query_end;
        }
      }
    }
    puts("YES");
query_end:
    for (auto p : P)
      G[p.first][p.second] = '.';
    while (uf.have_last())
      uf.revoke();
    fflush(stdout);
  }
  return 0;
}