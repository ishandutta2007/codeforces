#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

const int MAX = 1005;
const int MOD = 1000000007;

int c[MAX][MAX];

signed main() {
  for(int i = 0; i < MAX; i++) {
    c[i][i] = c[i][0] = 1;
  }

  for(int i = 0; i < MAX; i++) {
    for(int j = 1; j < i; j++) {
      c[i][j] = c[i-1][j] + c[i-1][j-1];
      c[i][j] %= MOD;
    }
  }

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::sort(a, a+n);

    int x = 0, y = 0;
    for(int i = 0; i < n; i++)
      if(a[i] == a[n-k])
        x++;
    for(int i = n-k; i < n; i++)
      if(a[i] == a[n-k])
        y++;

    std::cout << c[x][y] << std::endl;
  }

  return 0;
}