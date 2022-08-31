#include <iostream>
#include <vector>

#define int long long

const int MAXN = 1005;

int b[MAXN][MAXN];
int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int get(int x, int y) {
  int cur = 0;
  for(int i = 0; i < 4; i++) {
    int u = x + dx[i];
    int v = y + dy[i];
    if(u >= 0 && v >= 0 && u < n && v < n)
      cur ^= b[u][v];
  }
  return cur;
}

bool check() {
  bool poss = true;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      poss &= get(i, j);
  return poss;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    for(int j = 0; j < 16; j++) {
      for(int i = 0; i < n; i++)
        for(int k = 0; k < n; k++)
          b[i][k] = 0;

      for(int i = 0; i < n; i++) {
        int k = i%4;
        b[0][i] = (j >> k)&1;
      }

      for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
          b[i][j] = !get(i-1, j);
        }
      }

      if(check()) {
        /*
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
            std::cout << b[i][j] << " ";
          }
          std::cout << std::endl;
        }
        */
        break;
      }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        //std::cout << b[i][j] << " ";
        int x;
        std::cin >> x;
        if(b[i][j])
          ans ^= x;
      }
      //std::cout << std::endl;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}