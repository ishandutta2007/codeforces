#include <iostream>
#include <vector>

signed main() {
  int n;
  std::cin >> n;

  std::vector<int> next_val(n+1, n);
  std::vector<int> next(n, n);
  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
  }

  for(int i = n-1; i >= 0; i--) {
    next[i] = next_val[a[i]];
    next_val[a[i]] = i;
  }

  int nextc[2];
  nextc[0] = nextc[1] = n;
  int ans = 0;

  for(int i = 0; i < n; i++) {
    int change = next_val[nextc[0]] > next_val[nextc[1]] ? 1 : 0;
    if(a[i] == nextc[change])
      change ^= 1;
    if(nextc[change] != a[i]) {
      ans++;
    }
    nextc[change] = a[i];
    next_val[a[i]] = next[i];
  }

  std::cout << ans << std::endl;

  return 0;
}