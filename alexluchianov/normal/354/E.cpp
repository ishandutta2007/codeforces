#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const sigma = 19;
int const kmax = 6;
int const waste = 100;

int v[1 + sigma];

int dp[5 + sigma * kmax][5 + waste];
int last[5 + sigma * kmax][5 + waste];
int cif[5 + sigma * kmax][5 + waste];

///dp[processed][waste] = 
///number = 10^0 * sol[1] + 10^0 * sol[2] ... 10^0 * sol[kmax] - v[0]+
//          10^1 * sol[kmax + 1] + 10^1 * sol[kmax * 2]

int nice[3] = {0, 4, 7};

void solve() {
  ll number = 0;
  std::cin >> number;
  ll init = number;

  for(int i = 1;i <= sigma; i++) {
    v[i] = number % 10;
    number /= 10;
  }
  for(int i = 0; i <= sigma * kmax; i++)
    for(int j = 0; j <= waste; j++)
      dp[i][j] = cif[i][j] = last[i][j] = 0;
  dp[0][0] = 1;
  
  for(int i = 0;i < sigma * kmax; i++)
    for(int j = 0; j < waste; j++)
      if(dp[i][j] == 1) {
        for(int curr = 0; curr < 3; curr++) {
          int newj = j;
          if(i % kmax == 0) {
            if(newj % 10 == 0) {
              newj = newj / 10;
            } else
              break;
          } else if(i % kmax == kmax - 1)
            newj -= v[i / kmax + 1];
          newj += nice[curr];
          if(0 <= newj && newj < waste) {
            dp[i + 1][newj] = 1;
            last[i + 1][newj] = j;
            cif[i + 1][newj] = nice[curr];
          }
        }
      }

  if(dp[sigma * kmax][0] == 1) {
    ll aux[1 + kmax] = {0};
    int val = 0;
    for(int i = sigma * kmax; 0 < i; i--) {
      aux[i % kmax] = aux[i % kmax] * 10 + cif[i][val];
      val = last[i][val];
    }
    for(int i = 0; i < kmax; i++)
      init -= aux[i];
    assert(init == 0);
    for(int i = 0; i < kmax; i++)
      std::cout << aux[i] << " ";
    std::cout << '\n';
  } else {
    std::cout << -1 << '\n';
  }
}

int main(){
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}