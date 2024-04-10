#include <iostream>
#include <vector>

#define int long long

const int MAXN = 360*21;

int par[MAXN];

int root(int u) {
  if(par[u] < 0)
    return u;
  return par[u] = root(par[u]);
}

int conv(int i, int j) {
  return i*360 + j;
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < MAXN; i++)
      par[i] = -1;

    std::vector<int> t1[20];
    std::vector<int> t2[20];
    for(int i = 0; i < 20; i++) {
      t1[i] = std::vector<int>(360, 0);
      t2[i] = std::vector<int>(360, 0);
    }

    for(int i = 0; i < n; i++) {
      char c;
      std::cin >> c;

      if(c == 'C') {
        int r, s1, s2;
        std::cin >> r >> s1 >> s2;
        r--;
        for(int i = s1; i != s2; i = (i+1)%360) {
          t1[r][i] = 1;
        }
      }
      else {
        int r1, r2, s;
        std::cin >> r1 >> r2 >> s;
        s--;
        s += 360;
        s %= 360;
        for(int i = r1; i < r2; i++) {
          t2[i][s] = 1;
        }
      }
    }

    for(int i = 0; i < 20; i++) {
      for(int j = 0; j < 360; j++) {
        if(t1[i][j] == 0) {
          merge(conv(i, j), conv(i+1, j));
        }
        if(t2[i][j] == 0) {
          merge(conv(i, j), conv(i, (j+1)%360));
        }
      }
    }

    for(int i = 0; i < 360; i++)
      merge(conv(20, i), conv(20, (i+1)%360));

    if(root(conv(0, 0)) == root(conv(20, 0)))
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}