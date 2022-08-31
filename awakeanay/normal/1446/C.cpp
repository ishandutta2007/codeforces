#include <iostream>
#include <vector>

int ans(std::vector<int> a, int x) {
  if(a.size() <= 2)
    return 0;
  if(x < 0)
    return 0;
  std::vector<int> set, unset;
  for(int j : a) {
    if((j >> x)&1)
      set.push_back(j);
    else
      unset.push_back(j);
  }
  if(set.size() == 0)
    return ans(unset, x-1);
  if(unset.size() == 0)
    return ans(set, x-1);
  return std::min(ans(set, x-1) + unset.size()-1, ans(unset, x-1) + set.size()-1);
}

signed main() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  std::cout << ans(a, 30) << std::endl;

  return 0;
}