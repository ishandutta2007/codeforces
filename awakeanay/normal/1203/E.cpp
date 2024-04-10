#include <iostream>
#include <algorithm>
#include <map>

signed main() {
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int ans = 0;
  std::map<int, int> count;
  for(int i = 0; i < n; i++) {
    if(count[a[i]] == 0)
      ans++;
    count[a[i]]++;
  }

  std::sort(a, a+n);
  std::reverse(a, a+n);

  for(int i = 0; i < n; i++) {
    if(count[a[i]+1] == 0) {
      ans++;
      count[a[i]+1]++;
      count[a[i]]--;
      if(count[a[i]] == 0)
        ans--;
    }
    else if(count[a[i]] > 1 && a[i] > 1) {
      ans += (count[a[i]-1] == 0);
      count[a[i]-1]++;
      count[a[i]]--;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}