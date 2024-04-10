/*
Author: AwakeAnay
Date: 15/02/2020
Time: 11:51:49
*/

#include <iostream>
#include <vector>
#include <set>
#include <ctime>

#define int long long
#define MAX 1000005

std::vector<int> pr;
std::vector<std::vector<int> > pf;

int tau(int x, int y) {
  if(x == -1)
    return 1;

  int res = 0; int ny = y;
  for(int i = 0; i < (pf[2][x]+1) && ny; i++) {
    res += tau(x-1, ny);
    ny /= pr[x];
  }

  return res;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  
  int t;
  std::cin >> t;

  std::vector<int> isp(MAX, -1);
  for(int j = 2; j < MAX; j++) {
    if(isp[j] != -1)
      continue;

    for(int k = 1; k*j < MAX; k++) {
      isp[k*j] = j;
    }
  }

  while(t--) {
    std::vector<int> val(3, 1);

    std::set<int> pset;
    pset.insert(2);

    pr = std::vector<int>();

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        int x;
        std::cin >> x;
        val[i] *= x;

        while(x > 1) {
          pset.insert(isp[x]);
          x /= isp[x];
        }
      }
    }

    while(!pset.empty()) {
      pr.push_back(*pset.begin());
      pset.erase(pset.begin());
    }
    int l = pr.size();

    pf = std::vector<std::vector<int> >(3, std::vector<int>(l, 0));

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < l; j++) {
        int x = val[i];
        while(x%pr[j] == 0) {
          pf[i][j]++;
          x /= pr[j];
        }
      }
    }
    pf[2][0]++;
    
    std::vector<std::vector<int> > pow(l, std::vector<int>(1, 1));
    for(int i = 0; i < l; i++) {
      int cur = pr[i];
      int max = std::max(pf[0][i], std::max(pf[1][i], pf[2][i]));

      for(int j = 0; j < max; j++) {
        pow[i].push_back(cur);
        cur *= pr[i];
      }
    }

    int ans = 0;

    ans += tau(l-1, val[0]);

    std::vector<int> test;
    for(int i = 0; i < l; i++) {
      if(pf[0][i] > pf[2][i])
        test.push_back(pow[i][pf[2][i]+1]);
    }

    for(int i = 0; i < (1 << test.size()); i++) {
      int sgn = 1;
      int res = 1;

      int k = 0;
      for(int j = 1; j <= i; j <<= 1, k++) {
        if(j & i) {
          sgn *= -1;
          res *= test[k];
        }
      }

      ans += sgn*(val[1]/res);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}