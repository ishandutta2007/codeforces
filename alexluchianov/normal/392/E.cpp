#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 400;
ll const inf = 1000000000;

int v[5 + nmax], w[5 + nmax];
ll clear[5 + nmax][5 + nmax];
ll dp[5 + nmax][5 + nmax];
ll dp2[5 + nmax][5 + nmax];
ll pref[5 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 0;i < n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    std::cin >> w[i];

  for(int i = 1;i <= n; i++)
    for(int j = 1; j <= n; j++)
      clear[i][j] = -inf * nmax;
  for(int i = 1;i <= n; i++)
    clear[i][i - 1] = 0;

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      dp[i][j] = dp2[i][j] = -inf * nmax;
  for(int i = 1;i <= n; i++) {
    clear[i][i] = v[0];
    dp[i][i] = dp2[i][i] = 0;
  }

  for(int h = 1; h < n; h++)
    for(int i = 1;i <= n - h; i++) {
      int j = i + h;
      for(int k = i; k < j; k++) {
        clear[i][j] = std::max(clear[i][j], clear[i][k] + clear[k + 1][j]);
        if(w[k] + 1 == w[j])
          dp[i][j] = std::max(dp[i][j], dp[i][k] + clear[k + 1][j - 1]);
        else if(w[k] - 1 == w[j])
          dp2[i][j] = std::max(dp2[i][j], dp2[i][k] + clear[k + 1][j - 1]);
       }
       
       for(int k = i; k <= j; k++) {
         int coef = w[k] * 2 - w[i] - w[j];
         if(w[i] <= w[k] && w[j] <= w[k] && coef < n)
           clear[i][j] = std::max(clear[i][j], dp[i][k] + dp2[k][j] + v[coef]);
       }
    }

  for(int i = 1;i <= n; i++) {
    pref[i] = pref[i - 1];
    for(int j = 1; j <= i; j++)
      pref[i] = std::max(pref[i], pref[j - 1] + clear[j][i]);
  }
  std::cout << pref[n];
}