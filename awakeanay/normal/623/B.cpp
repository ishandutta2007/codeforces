#include <iostream>
#include <set>
#include <vector>

#define int long long

const int INF = 10000000000000000;

signed main() {
  int n, p, q;
  std::cin >> n >> p >> q;;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  if(n == 1) {
    std::cout << 0 << std::endl;
    return 0;
  }

  std::set<int> ps;
  for(int i = -1; i <= 1; i++) {
    int x = a[0];
    for(int j = 0; j < 2; j++) {
      int cp = x+i;
      for(int k = 2; k*k <= cp; k++) {
        if(cp%k == 0) {
          ps.insert(k);
          while(cp%k == 0)
            cp /= k;
        }
      }

      if(cp > 1)
        ps.insert(cp);

      x = a[n-1];
    }
  }

  std::vector<int> primes;
  for(int j : ps)
    primes.push_back(j);

  int ans = (n-1)*p;

  for(int j : primes) {
    int pref[n], suff[2][n];
    int cost[n];
    for(int i = 0; i < n; i++) {
      cost[i] = INF;
      if(a[i]%j == 0)
        cost[i] = 0;
      else if((a[i]-1)%j == 0 || (a[i]+1)%j == 0)
        cost[i] = q;

      pref[i] = cost[i];
      if(i) pref[i] += pref[i-1];
      pref[i] = std::min(INF, pref[i]);
    }

    suff[0][n-1] = cost[n-1];
    suff[1][n-1] = p;
    for(int i = n-2; i >= 0; i--) {
      suff[0][i] = std::min(INF, cost[i] + suff[0][i+1]);
      suff[1][i] = std::min(INF, p + std::min(suff[1][i+1], suff[0][i+1]));
    }

    ans = std::min(ans, std::min(suff[0][0], suff[1][0]));

    for(int i = 0; i < n; i++) {
      ans = std::min(ans, pref[i] + (i+1 < n ? std::min(suff[0][i+1], suff[1][i+1]) : 0));
    }
  }

  std::cout << ans << std::endl;

  return 0;
}