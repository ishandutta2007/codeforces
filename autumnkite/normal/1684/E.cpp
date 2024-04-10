#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      ++mp[x];
    }
    int cnt = mp.size();
    std::priority_queue<int> Q;
    int sum = 0;
    int now = 0;
    auto it = mp.end();
    int ans = cnt;
    while (it != mp.begin()) {
      --it;
      if (it->first + 1 - (cnt - now) <= k) {
        ans = std::min(ans, now - (int)Q.size());
      }
      ++now;
      Q.push(it->second);
      sum += it->second;
      while (sum > k) {
        sum -= Q.top();
        Q.pop();
      }
    }
    ans = std::min(ans, cnt - (int)Q.size());
    std::cout << ans << "\n";
  }
}