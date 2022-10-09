#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int modulo = 1000000009;
int const nmax = 500;

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
};

std::pair<Mint, Mint> block[1 + nmax];
Mint comb[1 + nmax][1 + nmax];

void computecomb() {
  for(int i = 0;i <= nmax; i++) {
    comb[i][0] = 1;
    for(int j = 1; j <= i; j++)
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
  }
}

std::pair<Mint, Mint> _mul(std::pair<Mint, Mint> a, std::pair<Mint, Mint> b) {
  return {a.first * b.first, a.second * b.first + a.first * b.second};
}

std::pair<Mint, Mint> _add(std::pair<Mint, Mint> a, std::pair<Mint, Mint> b) {
  return {a.first + b.first, a.second + b.second};
}

Mint gauss(Mint number) {
  return number * (number + 1) / 2;
}

std::pair<Mint, Mint> dp[1 + nmax][1 + nmax][2];

int main() {
  int n, m;
  std::cin >> n >> m >> modulo;
  computecomb();
  
  block[0] = {1, 0};
  

  for(int i = 1; i <= m; i++) {
    for(int j = 0; j < i; j++) {
      block[i] = _add(block[i], _mul({comb[i - 1][j], 0} ,_mul(_mul(block[j], block[i - 1 - j]), {(i + 1), gauss(j) + gauss(i - 1 - j)})));
    }
  }
  
  dp[0][0][0] = {1, 0};
  
  for(int i = 1; i <= n; i++){
    for(int j = 0;j <= i; j++) {
      for(int h = 1; h <= j; h++)
        dp[i][j][1] = _add(dp[i][j][1], _mul(_mul(dp[i - h][j - h][0], block[h]), {comb[j][h], 0}));
      
      dp[i][j][0] = _add(dp[i - 1][j][0], dp[i - 1][j][1]);
    }
  }

  std::pair<Mint, Mint> result = _add(dp[n][m][0], dp[n][m][1]);
  std::cout << result.second.number << '\n';
  
  return 0;
}