#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 10000;
ll const valmax = 10004205361450474;
int const sigma = 5;
ll dp[5 + nmax][1 + sigma];

ll getdp(ll x, int mv) {
  if(mv == 0)
    return 0;
  if(x <= nmax) {
    if(0 < dp[x][mv])
      return dp[x][mv];
    else { 
      if(1 == mv)
        return x;
      else {
        ll start = x;
        for(int j = 1; j <= x; j++) {
          start = start + getdp(start, mv - 1) + 1;
        }
        start = start + getdp(start, mv - 1);
        dp[x][mv] = start - x;
        return dp[x][mv];
      }
    }
  } else {
    ll result = nmax;
    for(int i = 2; i <= mv; i++)
      result = result * (1 + nmax) + nmax;
    return result;
  }
}

int ask(std::vector<ll> v) {
  std::cout << v.size() << " ";
  for(int i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
  std::cout << std::endl;
  int val;
  std::cin >> val;
  return val;
}

void solve(ll x, int mv) {
  ll start = x;
  int lim = std::min(start, 1LL * nmax);
  std::vector<ll> aux;
  for(int j = 1; j <= lim; j++) {
    start = start + getdp(start, mv - 1) + 1;
    aux.push_back(start - 1);
  }
  start = start + getdp(start, mv - 1);
  int where = ask(aux);
  if(where < 0)
    return ;
  else {
    if(where == 0)
      solve(x, mv - 1);
    else
      solve(aux[where - 1] + 1, mv - 1);
  }
}

int main() {
  solve(1, sigma);
  return 0;
}