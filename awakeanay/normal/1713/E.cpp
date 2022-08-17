#include <iostream>

#define int long long

const int MAXN = 1005;

int par[MAXN];
int val[MAXN];

int root(int u) {
  if(par[u] < 0)
    return u;
  int v = par[u];
  par[u] = root(v);
  val[u] ^= val[v];
  return par[u];
}

bool merge(int u, int v, int p) {
  int x = root(u);
  int y = root(v);

  if(x == y) {
    return val[u]^val[v] == p;
  }

  if(par[x] > par[y])
    x ^= y ^= x ^= y;

  par[x] += par[y];
  par[y] = x;
  val[y] = val[u]^val[v]^p;
  return 1;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n][n];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        std::cin >> a[i][j];

    for(int i = 0; i < n; i++) {
      par[i] = -1;
      val[i] = 0;
    }

    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        if(a[i][j] < a[j][i]) {
          merge(i, j, 0);
        }
        else if(a[j][i] < a[i][j]) {
          merge(i, j, 1);
        }
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        if(root(i) == root(j) && (val[i]^val[j]))
          a[i][j] ^= a[j][i] ^= a[i][j] ^= a[j][i];
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        std::cout << a[i][j] << " ";
      }
      std::cout << "\n";
    }
  }

  return 0;
}