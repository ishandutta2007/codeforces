#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

using ll = long long;

int const nmax = 200000;
int v[5 + nmax], frec[5 + nmax], sol[5 + nmax];

void solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    frec[i] = 0;

  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    frec[v[i]]++;
  }
  int res = 0;
  for(int i = 1;i <= n; i++)
    res += (0 < frec[i]);
  
  for(int i = 1;i <= n; i++)
    sol[i] = 0;

  if(res < n - 1) {
    for(int i = 1;i <= n; i++)
      if(0 < frec[v[i]]) {
        frec[v[i]] = -frec[v[i]];
        sol[i] = v[i];
      } 

    std::vector<int> common, firstside, targetside;

    for(int i = 1;i <= n; i++)
      if(sol[i] == 0 && frec[i] == 0)
        common.push_back(i);
      else if(sol[i] == 0)
        firstside.push_back(i);
      else if(frec[i] == 0)
        targetside.push_back(i);

    if(common.size() == 1) {
      sol[firstside[0]] = common[0];
      sol[common[0]] = targetside[0];
      for(int i = 1;i < firstside.size(); i++)
        sol[firstside[i]] = targetside[i];
    } else {
      for(int i = 0; i < common.size(); i++)
        sol[common[i]] = common[(i + 1) % common.size()];
      for(int i = 0; i < firstside.size(); i++)
        sol[firstside[i]] = targetside[i];
    }

  } else if(res == n - 1){
    int avoid = 0;
    for(int i = 1;i <= n; i++)
      if(frec[i] == 0)
        avoid = i;
    for(int i = 1; i <= n; i++)
      if(frec[v[i]] == 1)
        sol[i] = v[i];
      else if(frec[v[i]] == 2 && i == avoid) {
        sol[i] = v[i];
      } else if(frec[v[i]] == 2) {
        sol[i] = avoid;
        frec[v[i]]--;
      }
  } else {
    for(int i = 1;i <= n; i++)
      sol[i] = v[i];
  }

  std::cout << res << '\n';
  for(int i = 1;i <= n; i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}