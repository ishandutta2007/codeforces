#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 5000;
int const modulo = 1000000007;

int v[5 + nmax];
std::vector<int> app[5 + nmax], app2[5 + nmax], g[5 + nmax];

std::pair<int,int> join(std::pair<int,int> f1, std::pair<int,int> f2) {
  if(f1.first == f2.first) {
    return {f1.first, (f1.second + f2.second) % modulo};
  } else
    return std::max(f1, f2);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    std::cin >> v[i];
    app[v[i]].push_back(i);
  }
  for(int j = 1; j <= n; j++) {
    app2[j] = app[j];
    std::reverse(app2[j].begin(), app2[j].end());
  }

  for(int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    
  }
  std::pair<int,int> smin = {0, 0};
  for(int i = 0;i <= n; i++) {
    std::pair<int,int> sol = {0, 1};
    bool valid = false;
    for(int j = 1; j <= n; j++) {
      int count1 = 0, count2 = 0, count3 = 0;
      int force = 0;
      for(int h = 0; h < g[j].size(); h++) {
        int node = g[j][h] - 1;

        if(node < app[j].size()) {
          if(app[j][node] <= i && i < app2[j][node]) {
            if(app[j][node] == i) {
              valid = true;
              force = 3;
            } else
              count3++;
          } else if(app[j][node] <= i) {
            if(app[j][node] == i) {
              valid = true;
              force = 1;
            } else
              count1++;
          } else if(i < app2[j][node]) 
            count2++;
        }
      }


      if(0 < force && 0 < i) {
        if(0 < count2 + count3) {
          sol.first += 2;
          sol.second = 1LL * sol.second * (count2 + count3) % modulo;
        } else
          sol.first++;
      } else {
        if(force == 1)
          count1++;
        else if(force == 3)
          count3++;

        if(0 == count1 + count2 + count3) {

        } else if(0 < count1 + count3 && 0 < count2 + count3 && 1 < count1 + count2 + count3){
          sol.first += 2;
          sol.second = 1LL * sol.second * ((1LL * count1 * count2 + 1LL * count3 * count2 + 1LL * count1 * count3 + 1LL * count3 * (count3 - 1)) % modulo) % modulo;
        } else {
          sol.first += 1;
          sol.second = 1LL * sol.second * (count1 + count2 + 2 * count3) % modulo;
        }
      }
    }
    if(valid == true || i == 0)
      smin = join(smin, sol);
  }
  std::cout << smin.first << " " << smin.second << '\n';
  return 0;
}