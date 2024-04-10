#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  std::sort(a, a+n);
  std::reverse(a, a+n);
  int spec = 0;
  for(int i = 0; i < n; i++)
    spec += a[i]*i;

  for(int i = 1; i < n; i++)
    a[i] += a[i-1];


  int q;
  std::cin >> q;

  while(q--) {
    int k;
    std::cin >> k;

    if(k == 1) {
      std::cout << spec << " ";
      continue;
    }

    int cur = 1;
    int ans = 0;
    int i = 1;
    int count = k;

    while(i < n) {
      int next = std::min(n-i, count);
      ans += cur*(a[i+next-1] - a[i-1]);
      count *= k;
      cur++;
      i += next;
    }

    std::cout << ans << " ";
  }

  std::cout << std::endl;

  return 0;
}