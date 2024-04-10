#include <bits/stdc++.h>

using namespace std;

#define long long long

const int M = 505;
const int inf = 1000;

int a[M][M];
int d[M][M];
int n, m;

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    a[x][y] = a[y][x] = 1;
  }
}

void kill() {
  if (a[0][n - 1] == 1) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        d[i][j] = i == j ? 0 : (a[i][j] == 1 ? inf : 1);
  } else {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        d[i][j] = i == j ? 0 : (a[i][j] == 1 ? 1 : inf);
  }


  //for (int i = 0; i < n; ++i, cout << endl)
  //  for (int j = 0; j < n; ++j, cout << " ")
  //    printf("%4d", d[i][j]);

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  cout << (d[0][n - 1] == inf ? -1 : d[0][n - 1]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  read();
  kill();
  return 0;
}