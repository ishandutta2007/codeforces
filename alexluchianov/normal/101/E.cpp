#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 20000;
int xcoef[5 + nmax], ycoef[5 + nmax], modulo;

int getcost(int x, int y) {
  if(modulo <= xcoef[x] + ycoef[y])
    return xcoef[x] + ycoef[y] - modulo;
  else
    return xcoef[x] + ycoef[y];
}

ll dp[5 + nmax], dp2[5 + nmax];

std::pair<ll, std::string> divide(int startx, int starty, int stopx, int stopy) {
  assert(startx <= stopx && starty <= stopy);
  int mid = (startx + stopx) / 2;
  if(startx == stopx) {
    ll cost = getcost(startx, starty);
    std::string sol;
    for(int i = starty + 1; i <= stopy; i++) {
      cost += getcost(startx, i);
      sol += "S";
    }
    return {cost, sol};
  } else if(starty == stopy) {
    ll cost = getcost(startx, starty);
    std::string sol;
    for(int i = startx + 1; i <= stopx; i++) {
      cost += getcost(i, starty);
      sol += "C";
    }
    return {cost, sol};
  }
  for(int i = starty - 1; i <= stopy; i++)
    dp[i] = dp2[i] = 0;

  for(int i = startx; i <= mid; i++) {
    for(int j = starty; j <= stopy; j++)
      dp[j] += getcost(i, j);
    for(int j = starty + 1; j <= stopy; j++)
      dp[j] = std::max(dp[j], dp[j - 1] + getcost(i, j));
  }

  for(int i = stopx; mid + 1 <= i; i--) {
    for(int j = starty; j <= stopy; j++)
      dp2[j] += getcost(i, j);
    for(int j = stopy - 1; starty <= j; j--)
      dp2[j] = std::max(dp2[j], dp2[j + 1] + getcost(i, j));
  }
  int smin = starty;
  for(int j = starty; j <= stopy; j++)
    if(dp[smin] + dp2[smin] < dp[j] + dp2[j])
      smin = j;
  
  std::pair<ll, std::string> sol, sol2;

  sol = divide(startx, starty, mid, smin);
  sol2 = divide(mid + 1, smin, stopx, stopy);
  sol.first += sol2.first;
  sol.second += "C" + sol2.second;
  return sol;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m >> modulo;
  for(int i = 1;i <= n; i++) {
    std::cin >> xcoef[i];
    xcoef[i] %= modulo;
  }

  for(int i = 1;i <= m; i++) {
    std::cin >> ycoef[i];
    ycoef[i] %= modulo;
  }

  std::pair<ll, std::string> sol = divide(1, 1, n, m);
  std::cout << sol.first << '\n' << sol.second << '\n';
  return 0;
}