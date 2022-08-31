#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;

  if(k == 1) {
    std::cout << n << std::endl;
    return 0;
  }

  int lo = 1, hi = n;
  while(lo < hi) {
    int mid = (lo+hi)/2;

    std::vector<int> poss[k];
    std::vector<int> count(k, 0);

    for(int i = 0; i < n; i++) {
      if(s[i] != '?')
        count[s[i]-'a']++;

      if(i >= mid)
        if(s[i-mid] != '?')
          count[s[i-mid]-'a']--;

      int alpc = 0;
      int last = -1;
      for(int j = 0; j < k; j++) {
        if(count[j] > 0) {
          alpc++;
          last = j;
        }
      }

      if(alpc == 1)
        poss[last].push_back(i);
      else if(alpc == 0) {
        for(int j = 0; j < k; j++)
          poss[j].push_back(i);
      }
    }

    int M = (1 << k);
    int dp[M];
    dp[0] = -1;

    for(int i = 1; i < M; i++) {
      dp[i] = n;
      for(int j = 0; j < k; j++) {
        if((i >> j)&1) {
          int upl = dp[i^(1 << j)];
          auto it = std::lower_bound(poss[j].begin(), poss[j].end(), upl+mid);
          if(it != poss[j].end())
            dp[i] = std::min(dp[i], *it);
        }
      }
    }

    if(dp[M-1] == n)
      hi = mid;
    else
      lo = mid+1;
  }

  std::cout << lo-1 << std::endl;

  return 0;
}