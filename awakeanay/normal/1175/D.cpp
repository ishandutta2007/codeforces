#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  int n, k;
  std::cin >> n >> k;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int pre[n];
  for(int i = 0; i < n; i++) {
    pre[i] = a[n-1-i];
    if(i) pre[i] += pre[i-1];
  }

  std::sort(pre, pre+n-1);
  int ans = pre[n-1];
  for(int i = 0; i+1 < k; i++)
    ans += pre[n-2-i];

  std::cout << ans << std::endl;

  return 0;
}