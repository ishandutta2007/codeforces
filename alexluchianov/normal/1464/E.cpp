#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 998244353;

class Mint{
private:
  void gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
      x = 1;
      y = 0;
    } else {
      gcd(b, a % b, x, y);
      int aux = x;
      x = y;
      y = aux - a / b * y;
    }
  }
public:
  int number;

  Mint(int number_ = 0) {
    number = number_ % modulo;
  }
  Mint(ll number_ ) {
    number = number_ % modulo;
  }
  Mint operator + (Mint oth) {
    return number + oth.number;
  }
  Mint operator - (Mint oth) {
    return modulo + number - oth.number;
  }
  Mint operator * (Mint oth) {
    return 1LL * number * oth.number;
  }
  Mint operator / (Mint oth) {
    int x, y;
    gcd(oth.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }
  bool operator == (Mint oth) {
    return (number == oth.number);
  }
};

std::vector<int> g[1 + nmax];
int dp[1 + nmax];

int mex(std::vector<int> aux) {
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
  for(int i = 0; i < aux.size(); i++) {
    if(aux[i] != i)
      return i;
  }
  return aux.size();
}

void dfs(int node) {
  std::vector<int> aux;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(dp[to] == -1)
      dfs(to);
    aux.push_back(dp[to]);
  }
  dp[node] = mex(aux);
}

int const statemax = (1 << 9);
int coef[1 + nmax];

Mint mat[5 + statemax][5 + statemax];

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  for(int i = 1;i <= n; i++)
    dp[i] = -1;
  for(int i = 1;i <= n; i++)
    if(dp[i] == -1)
      dfs(i);
  for(int i = 1;i <= n; i++)
    coef[dp[i]]++;
  
  Mint invn = Mint(1) / (n + 1);
  
  mat[0][statemax] = Mint(0) - invn;
  
  for(int i = 0; i < statemax; i++) {
    mat[i][i] = Mint(0) - 1;
    
    for(int j = 0; j < statemax; j++)
      if(0 < coef[j])
        mat[i][(i ^ j)] = mat[i][(i ^ j)] + invn * coef[j];
  }

  int ptr = 0;
  for(int i = 0; i < statemax; i++) {
    if(mat[ptr][i] == 0) {
      for(int j = i; j < statemax; j++)
        if(!(mat[j][i] == 0)) {
          for(int h = 0; h <= statemax; h++)
            std::swap(mat[ptr][h], mat[j][h]);
          break;
        }
    }
    if(!(mat[ptr][i] == 0)) {
      Mint inverse = Mint(1) / mat[ptr][i];
      for(int h = 0; h <= statemax; h++)
        mat[ptr][h] = mat[ptr][h] * inverse;

      for(int j = 0; j < statemax; j++)
        if(j != ptr && !(mat[j][i] == 0)) {
          Mint target = mat[j][i];
          for(int h = 0; h <= statemax; h++)
            mat[j][h] = mat[j][h] - target * mat[ptr][h];
        }
      ptr++;
    }
  }
  std::cout << (Mint(1) - mat[0][statemax]).number;
  return 0;
}