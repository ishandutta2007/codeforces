#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

const int MAX_N = 2e3 + 5;

typedef long double ld;

ld dp [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  ld nsq = (ld) n * (ld) n;
  
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 && j == 0) {
        continue;
      }

      ld rdij = ((ld) i * (ld) j) / nsq;
      ld rdi = (ld) i / (ld) n - rdij;
      ld rdj = (ld) j / (ld) n - rdij;
      ld stay = 1 - rdij - rdi - rdj;
      
      if (i != 0) {
        dp[i][j] += rdi * (1 + dp[i - 1][j]);
      }

      if (j != 0) {
        dp[i][j] += rdj * (1 + dp[i][j - 1]);
      }

      if (i != 0 && j != 0) {
        dp[i][j] += rdij * (1 + dp[i - 1][j - 1]);
      }
      
      dp[i][j] += stay;
      dp[i][j] /= 1 - stay;
    }
  }

  set<int> xs, ys;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    xs.insert(x);
    ys.insert(y);
  }

  cout << fixed << setprecision(12) << dp[n - (int) xs.size()][n - (int) ys.size()] << endl;
}