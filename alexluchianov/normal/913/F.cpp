#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
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
      y = aux - a/ b * y;
    }
  }
public:
  int number;
  Mint(ll number_ = 0) {
    number = number_ % modulo;
  }
  Mint operator + (Mint const a) {
    return (number + a.number);
  }
  Mint operator - (Mint const a) {
    return (modulo + number - a.number);
  }
  Mint operator * (Mint const a) {
    return 1LL * number * a.number;
  }
  Mint operator / (Mint const a) {
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }
  friend std::ostream &operator << (std::ostream &output, Mint a) {
    output << a.number;
    return output;
  }
};

Mint connected[1 + nmax];
Mint split[1 + nmax][1 + nmax];
Mint quick[1 + nmax], quickno[1 + nmax];
Mint dp[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  int a, b;
  std::cin >> a >> b;
  Mint p = Mint(a) / b;
  split[0][0] = 1;
  
  quick[0] = quickno[0] = 1;
  quick[1] = p;
  quickno[1] = Mint(1) - p;
  for(int i = 2;i <= n; i++) {
    quick[i] = quick[i - 1] * p;
    quickno[i] = quickno[i - 1] * quickno[1];
  }
  
  for(int i = 0;i <= n; i++) {
    split[i][0] = 1;
    for(int j = 1; j <= i; j++)
      split[i][j] = split[i - 1][j - 1] * quick[i - j] + split[i - 1][j] * quickno[j];
  }
  connected[0] = connected[1] = 1;
  for(int i = 2;i <= n; i++) {
    connected[i] = 1;
    for(int j = 1;j < i; j++) 
      connected[i] = connected[i] - split[i][j] * connected[j];
  }
  
  dp[1] = 0;
  for(int i = 2;i <= n; i++) {
    for(int j = 1; j < i; j++)
      dp[i] = dp[i] +  (dp[i - j] + dp[j] + Mint(j) * (j - 1) / 2 + Mint(i - j) * j) * split[i][j] * connected[j];
    dp[i] = dp[i] + (Mint(i) * (i - 1)) / 2 * connected[i];
    dp[i] = dp[i] / (Mint(1) - connected[i]);
  }
  std::cout << dp[n];
  return 0;
}