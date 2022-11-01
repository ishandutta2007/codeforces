#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int N = 55;

char g[N][N];
int n, p[N][N], f[N][N][N][N]; 

inline int get (int i, int j, int k, int l) {
  return p[k][l] - p[k][j - 1] - p[i - 1][l] + p[i - 1][j - 1];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
    for (int j = 1; j <= n; ++j) {
      p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (g[i][j] == '#');
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = n; j >= 1; --j) {
      for (int k = i; k <= n; ++k) {
        for (int l = j; l <= n; ++l) {
          f[i][j][k][l] = 6969;
          if (get(i, j, k, l) == 0) f[i][j][k][l] = 0;
          else if (k - i == l - j) f[i][j][k][l] = k - i + 1;
          // if (i == 1 and j == 1 and k == 1 and l == 2) cout << f[i][j][k][l] << endl;
          for (int it = i; it < k; ++it) {
            // if (i == 1 and j == 1 and k == 1 and l == 2) cout << "yo1\n";
            f[i][j][k][l] = min(f[i][j][k][l], f[i][j][it][l] + f[it + 1][j][k][l]);
          }
          for (int it = j; it < l; ++it) {
            // if (i == 1 and j == 1 and k == 1 and l == 2) cout << "yo2\n";
            // if (i == 1 and j == 1 and k == 1 and l == 2) cout << f[i][j][k][it] << " " << f[i][it + 1][k][l] << endl;
            f[i][j][k][l] = min(f[i][j][k][l], f[i][j][k][it] + f[i][it + 1][k][l]);
          }
        }
      }
    }
  }
  // cout << f[1][1][1][1] << endl;
  // cout << f[1][2][1][2] << endl;
  // cout << f[1][1][1][2] << endl;
  cout << f[1][1][n][n] << '\n';
  return 0;
}