#include <iostream>
#include <vector>

#define int long long

signed main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> next(k, 0);
  for(int i = 0; i < k; i++)
    next[i] = i;

  int cur = 0;
  std::vector<int> ans(1, 0);
  while(ans.size() < n) {
    ans.push_back(next[cur]);
    next[cur] = (next[cur]+1)%k;
    cur = ans.back();
  }

  for(int j : ans)
    std::cout << ((char) ('a' + j));
  std::cout << std::endl;

  return 0;
}