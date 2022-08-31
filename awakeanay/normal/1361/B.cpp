#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define int long long
#define MOD 1000000007
#define MAXK 2000000

int exp(int x, int p) {
  int ret = 1;

  while(p > 0) {
    if(p & 1) {
      ret = (ret*x)%MOD;
    }

    p >>= 1;
    x = (x*x)%MOD;
  }

  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int t;
  std::cin >> t;
  std::vector<int> powers(MAXK, 0);

  while(t--) {
    int n, p;
    std::cin >> n >> p;

    int arr[n];
    for(int i = 0; i < n; i++) {
      std::cin >> arr[i];
    }

    std::sort(arr, arr+n);

    if(p == 1) {
      if(n%2)
        std::cout << 1 << std::endl;
      else
        std::cout << 0 << std::endl;
      continue;
    }

    int ans = 0;
    std::set<int> pows;

    int r = n-1;
    int cur = -1;
    while(r >= 0) {
      cur = arr[r];
      r--;

      while(r >= 0) {
        powers[arr[r]]++;
        pows.insert(arr[r]);
        
        int next = arr[r];
        while(powers[next] == p) {
          powers[next] = 0;
          pows.erase(next);
          powers[next+1]++;
          pows.insert(next+1);
          next++;
        }

        if(powers[cur]) {
          powers[cur] = 0;
          cur = -1;
          pows.erase(cur);
          r--;
          break;
        }

        r--;
      }
    }

    while(!pows.empty()) {
      int u = *pows.begin();
      pows.erase(pows.begin());

      ans = (ans + (exp(p, u)*powers[u])%MOD)%MOD;
      powers[u] = 0;
    }

    if(cur != -1) {
      ans = (exp(p, cur) + MOD - ans)%MOD;
    }
    
    std::cout << ans << std::endl;
  }

  return 0;
}