#include <iostream>
#include <iomanip>

using namespace std;
using ld = long double;
int const nmax = 18;
ld v[1 + nmax][1 + nmax];
ld dp[1 + (1 << nmax)];

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> v[i][j];
  dp[(1 << n) - 1] = 1;
  for(int mask = (1 << n) - 1; 0 < mask; mask--){
    if(2 <= __builtin_popcount(mask)) {
      ld prob = 1 / (__builtin_popcount(mask) * (__builtin_popcount(mask) - 1) / 2.0);

      for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
          if(0 < (mask & (1 << i)) && 0 < (mask & (1 << j))){
             dp[mask ^ (1 << i)] += dp[mask] * v[j][i] * prob;
             dp[mask ^ (1 << j)] += dp[mask] * v[i][j] * prob;
          }
    }
  }
  for(int i = 0; i < n; i++)
    cout << setprecision(6) << fixed << dp[(1 << i)] << " " ;
  return 0;
}