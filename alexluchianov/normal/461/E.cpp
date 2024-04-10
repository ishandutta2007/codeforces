#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using ll = long long;

ll makeHash(std::string s) {
  ll ret = 0;
  for(auto ch : s)
    ret = (ret << 2) + ch - 'A';
  return ret;
}

std::unordered_map<ll, int> mp;

int const sigma = 4;
int const nmax = 11;
ll const inf = 1000000000000000001;

struct Matrix{
private:
public:
  ll dp[sigma][sigma];
  Matrix() {
    for(int i = 0; i < sigma; i++)
      for(int j = 0; j < sigma; j++)
        dp[i][j] = inf;
  }
  Matrix operator * (Matrix oth) {
    Matrix result;
    for(int i = 0; i < sigma; i++)
      for(int j = 0; j < sigma; j++)
        for(int h = 0; h < sigma; h++)
          result.dp[i][j] = std::min(result.dp[i][j], dp[i][h] + oth.dp[h][j] - 1);
    return result;
  }
};

Matrix lgpow(Matrix a, ll b) {
  if(b == 1)
    return a;
  else {
    Matrix result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

Matrix init;

int getbit(ll number, int pos) {
  return (number>>(pos * 2)) % 4;
}

ll minLength(ll k) {
  Matrix orig = lgpow(init, k);
  ll result = inf;
  for(int i = 0; i < sigma; i++)
    for(int j = 0; j < sigma; j++)
      result = std::min(result, orig.dp[i][j]);
  return result;
}

int main() {
  ll n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  for(int i = 1; i <= std::min((int)s.size(), nmax); i++) {
    mp.clear();
    for(int j = i - 1; j < s.size(); j++)
      mp[makeHash(s.substr(j - i + 1, i))] = 1;

    for(int mask = 0; mask < (1 << (2 * i)); mask++) {
      
      if(init.dp[getbit(mask, 0)][getbit(mask, i - 1)] == inf) {
        if(mp[mask] == 0) 
          init.dp[getbit(mask, 0)][getbit(mask, i - 1)] = i;
      }
    }
  }

  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      if(init.dp[i][j] == 1) {
        std::cout << n << '\n';
        return 0;
      }
  ll x = 0;
  for(ll jump = (1LL << 60); 0 < jump; jump /= 2)
    if(minLength(x + jump) <= n)
      x += jump;
  std::cout << x + 1 << '\n';
  return 0;
}