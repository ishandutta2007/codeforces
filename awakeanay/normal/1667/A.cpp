#include <iostream>
#include <vector>

#define int long long

int solve(std::vector<int> a) {
  int n = a.size();
  int ans = 0;
  a[0] = 0;
  for(int i = 0; i < n; i++) {
    if(i > 0) {
      int cur = (a[i-1]+1)/a[i] + (((a[i-1]+1)%a[i]) != 0);
      a[i] *= cur;
      ans += cur;
    }
  }

  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> a(n, 0);
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int ans = solve(a);
  for(int j = 0; j < n; j++) {
    std::vector<int> x, y;
    for(int i = j; i < n; i++)
      x.push_back(a[i]);
    for(int i = j; i >= 0; i--)
      y.push_back(a[i]);
    ans = std::min(ans, solve(x) + solve(y));
  }

  std::cout << ans << std::endl;

  return 0;
}