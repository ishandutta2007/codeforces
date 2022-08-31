#include <iostream>
#include <iomanip>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, s;
  std::cin >> n >> s;

  int a[n-1], b[n-1];
  std::vector<int> deg(n, 0);
  int ans = 0;
  for(int i = 1; i < n; i++) {
    std::cin >> a[i-1] >> b[i-1];
    a[i-1]--;
    b[i-1]--;
    deg[a[i-1]]++;
    deg[b[i-1]]++;

    ans = std::max(ans, deg[a[i-1]]);
    ans = std::max(ans, deg[b[i-1]]);
  }

  ans = 0;
  for(int i = 0; i < n; i++)
    ans += deg[i] == 1;

  long double sld = s;
  long double ansl = ans;
  std::cout << std::fixed << std::setprecision(15);

  std::cout << (2.0000000000000000000000*sld)/ansl << std::endl;

  return 0;
}