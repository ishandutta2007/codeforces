#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using ll = long long;

int const nmax = 1000000;
int const modulo = 1000000007;

int solve() {
  int n, m;
  std::cin >> n >> m;
  int result = 0;
  
  ++n;
  ++m;

  for(int i = 1;i < n; i++)
    for(int j = 0;j < m; j++)
      if(i + j < n && i + j < m && 0 < i + j) {
        result += (n - i - j) * (m - i - j) * (i * i + j * j - 2 * (i + j) + 2 * std::__gcd(i, j));
      }
  return result;
}
class Mint{
public:
  int number;
  Mint(int number_ = 0) {
    number = number_ % modulo;
  }
  Mint(ll number_) {
    number = number_ % modulo;
  }
  Mint operator + (Mint const oth) {
    return number + oth.number;
  }
  Mint operator - (Mint const oth) {
    return modulo + number - oth.number;
  }
  Mint operator * (Mint const oth) {
    return 1LL * number * oth.number;
  }
};


std::vector<std::pair<int,int>> g[1 + nmax];
int sol[1 + nmax];
int phi[1 + nmax];

Mint dp[1 + nmax];
std::bitset<1 + nmax> ciur;

void precompute() {
  for(int i = 1;i <= nmax; i++)
    phi[i] = i;
  for(int i = 2; i <= nmax; i++) {
    if(ciur[i] == 0) {
      phi[i] = i - 1;
      for(int j = i * 2; j <= nmax; j += i) {
        ciur[j] = 1;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
  for(int i = 1;i <= nmax; i++)
    for(int j = i * 2; j <= nmax; j += i)
      dp[j] = dp[j] + i * phi[j / i];
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  precompute();

  int q;
  std::cin >> q;
  
  int lim = 0;
  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    if(y < x)
      std::swap(x, y);
    g[x].push_back({y, i});
    lim = std::max(lim, x);
  }
  
  Mint coefn = 0, coefnm = 0, coefbase = 0;
  
  Mint result(0), sump(0);

  for(int i = 1;i <= lim; i++) {
    //result += (n - i - j) * (m - i - j) * (i * i + j * j - 2 * (i + j) + 2 * std::__gcd(i, j));

    //alligned squares
    coefbase = coefbase + (Mint(i) * i * i * i);
    coefn = coefn - (Mint(i) * i * i);
    coefnm = coefnm + Mint(i) * i;
    
    coefbase = coefbase + Mint(i) * i * (sump * 2 + dp[i] * 2);
    coefn = coefn - Mint(i) * sump * 2 - Mint(i) * dp[i] * 2;
    coefnm = coefnm + sump * 2 + dp[i] * 2;

    sump = sump + Mint(i) * i - i * 2;

    for(int h = 0; h < g[i].size(); h++) {
      int n = i + 1;
      int m = g[i][h].first + 1;
      int id = g[i][h].second;
      sol[id] = (coefbase + coefn * n + coefn * m + coefnm * n * m).number;
    }
  }

  for(int i = 1;i <= q; i++)
    std::cout << sol[i] << '\n';
  return 0;
}