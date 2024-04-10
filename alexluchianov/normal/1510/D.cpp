#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>


using ll = long long;
using ld = long double;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const sigma = 10;
int v[1 + nmax];
ld lit[1 + nmax];
ld dp[1 + nmax][1 + sigma];
int last[1 + nmax][1 + sigma], taken[1 + nmax][1 + sigma];


void build(int n, int k, std::vector<int> &aux) {
  if(0 < n && 0 <= k) {
    if(taken[n][k] == 1)
      aux.push_back(n);
    build(n - 1, last[n][k], aux);
  }
}

int main() {
  int n, d;
  std::cin >> n >> d;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    lit[i] = log(v[i]);
  for(int i = 0;i <= nmax; i++)
    for(int j = 0;j < sigma; j++) {
      dp[i][j] = -nmax;
      last[i][j] = -1;
    }
  for(int i = 1;i <= nmax; i++) {
    for(int j = 0; j < sigma; j++) {
      dp[i][j] = dp[i - 1][j];
      last[i][j] = j;
      taken[i][j] = 0;
    }
    if(dp[i][v[i] % 10] < lit[i]) {
      dp[i][v[i] % 10] = lit[i];
      taken[i][v[i] % 10] = 1;
      last[i][v[i] % 10] = -1;
    }
    
    for(int j = 0; j < sigma; j++) {
      int cif = (j * v[i]) % 10;
      if(dp[i][cif] < dp[i - 1][j] + lit[i]) {
        dp[i][cif] = dp[i - 1][j] + lit[i];
        last[i][cif] = j;
        taken[i][cif] = 1;
      }
    }
  }

  if(0 <= dp[n][d]) {
    std::vector<int> aux;
    build(n, d, aux);
    std::cout << aux.size() << '\n';
    for(int i = 0; i < aux.size(); i++)
      std::cout << v[aux[i]] << " ";
    std::cout << '\n';
    return 0;
  } else
    std::cout << -1;
  return 0;
}