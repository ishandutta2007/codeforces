/*
Author: AwakeAnay
Date: 08/02/2020
Time: 10:53:01
*/

#include <iostream>
#include <vector>

#define MAX 5005
#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> pr;
  int l = 0;

  for(int i = 2; i < MAX; i++) {
    bool prime = true;
    for(int j : pr) {
      if(i % j == 0)
        prime = false;
    }
    if(prime) {
      pr.push_back(i);
      l++;
    }
  }

  std::vector<std::vector<int> > pf(MAX, std::vector<int>(l, 0));

  for(int i = 2; i < MAX; i++) {
    int ni = i;
    for(int j = 0; j < l; j++) {
      while(ni % pr[j] == 0) {
       ni /= pr[j];
       pf[i][j]++;
      }
      pf[i][j] += pf[i-1][j];
    }
  }
  
  auto last = [&](int x) -> int {
    for(int i = l-1; i >= 0; i--) {
      if(pf[x][i])
        return i;
    }
    return -1;
  };
  
  auto del = [&](int x) {
    for(int i = l-1; i >= 0; i--) {
      if(pf[x][i]) {
        pf[x][i]--;
        break;
      }
    }
  };

  auto len = [&](int x) -> int {
    int res = 0;
    for(int j : pf[x])
      res += j;
    return res;
  };

  std::vector<int> count(MAX);
  for(int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    count[k + (k==0)]++;
  }
  
  int ans = 0;
  int m = n/2 + (n%2);
  int away = count[1];

  std::vector<int> rem;
  for(int i = 2; i < MAX; i++)
    rem.push_back(i);

  while(true) {
    std::vector<int> best(l, 0);
    for(int j : rem) {
      if(last(j) > -1)
        best[last(j)] += count[j];
    }
    
    std::vector<int> nrem;
    for(int j : rem) {
      if(last(j) > -1 && best[last(j)] >= m) {
        del(j);
        nrem.push_back(j);
      } else {
        away += count[j];
        ans += count[j]*len(j);
      }
    }

    if(nrem.size() == 0)
      break;

    rem = nrem;
    ans += away;
  }

  std::cout << ans << std::endl;

  return 0;
}