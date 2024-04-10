#include <iostream>
#include <set>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int count[n];
  std::set<int> s;
  for(int i = 0; i < n; i++) {
    s.insert(a[i]);
    count[i] = s.size();
  }

  std::vector<int> freq(100005, 0);
  int ans = 0;
  for(int i = n-1; i > 0; i--) {
    if(freq[a[i]] == 0) {
      ans += count[i-1];
      freq[a[i]] = 1;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}