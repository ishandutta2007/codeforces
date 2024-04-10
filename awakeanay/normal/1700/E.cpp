#include <iostream>
#include <vector>

#define int long long

const int MAXN = 400005;

std::vector<int> Adj[MAXN];
int ct_zero;
int sv[MAXN];
int val[MAXN];
int n, m;

void detect(int i) {
  ct_zero -= sv[i] == 0;
  sv[i] = 0;

  for(int j : Adj[i]) {
    sv[i] += val[j] < val[i];
  }

  ct_zero += sv[i] == 0;
}

void update(int i, int v) {
  val[i] = v;
  detect(i);
  for(int j : Adj[i])
    detect(j);
}

int conv(int i, int j) {
  return i*m + j;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> m;
  ct_zero = n*m;

  for(int i = 0; i < n; i++) {
    for(int j = 1; j < m; j++) {
      int u = conv(i, j);
      int v = conv(i, j-1);
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }
  }

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int u = conv(i, j);
      int v = conv(i-1, j);
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }
  }

  int a[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      std::cin >> a[i][j];
      update(conv(i, j), a[i][j]);
    }
  }

  if(ct_zero == 1) {
    std::cout << 0 << std::endl;
    return 0;
  }

  int ans = 0;
  int root = -1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int u = conv(i, j);
      if(val[u] != 1 && sv[u] == 0)
        root = u;
    }
  }

  std::vector<int> test;
  std::vector<int> check(n*m, 0);
  test.push_back(root);
  check[root] = 1;
  for(int j : Adj[root]) {
    test.push_back(j);
    check[j] = 1;
  }
  /*
  for(int i = 0; i < n*m; i++) {
    if(check[i])
      std::cout << i << " ";
  }
  std::cout << std::endl;
  */


  for(int u : test) {
    for(int j = 0; j < n*m; j++) {
      if((!check[j]) || (u < j)) {
        int x = val[u];
        int y = val[j];
        update(u, y);
        update(j, x);
        ans += ct_zero == 1;
        update(u, x);
        update(j, y);
      }
    }
  }

  if(ans == 0) {
    std::cout << 2 << std::endl;
  }
  else {
    std::cout << 1 << " " << ans << std::endl;
  }

  return 0;
}