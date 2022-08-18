#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAX_N = 105;

ld dp [MAX_N][MAX_N][MAX_N];

int main () {
  int r, p, s;
  cin >> r >> s >> p;

  dp[r][p][s] = 1;
  for (int rps = r + p + s - 1; rps >= 1; rps--) {
    for (int i = 0; i <= r; i++) {
      for (int j = 0; j <= p; j++) {
        int k = rps - i - j;
        if (0 <= k && k <= s) {
          // count the probability that we get to this state

          if (j > 0 || k > 0) {
            dp[i][j][k] += dp[i + 1][j][k] * (i + 1) * j / ((i + 1) * j + (i + 1) * k + j * k);
          }
          
          if (i > 0 || k > 0) { 
            dp[i][j][k] += dp[i][j + 1][k] * (j + 1) * k / ((j + 1) * k + (j + 1) * i + k * i);
          }
         
          if (i > 0 || j > 0) {
            dp[i][j][k] += dp[i][j][k + 1] * (k + 1) * i / ((k + 1) * i + (k + 1) * j + i * j);
          }
        }
      }
    }
  }

  ld rans = 0, pans = 0, sans = 0;
  for (int i = 1; i <= r; i++) {
    rans += dp[i][0][0];
  }
  for (int i = 1; i <= p; i++) {
    pans += dp[0][i][0];
  }
  for (int i = 1; i <= s; i++) {
    sans += dp[0][0][i];
  }
  
  cout << fixed << setprecision(12)
       << rans << " " << sans << " " << pans << endl;
}