#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> pos[n];

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
    pos[a[i]].push_back(i);
  }

  int best = -1;

  int b[n];
  for(int i = 0; i < n; i++) {
    b[i] = pos[a[i]].back();
    if(i)
      b[i] = std::max(b[i], b[i-1]);
  }

  int ans = n;
  for(int i = 0; i < n; i++) {
    if(b[i] == i) {
      ans--;
      continue;
    }

    int j = b[i];
    int cur = 1;
    while(b[j] > j) {
      j = b[j];
      cur++;
    }

    ans -= cur+1;
    i = j;
  }

  std::cout << ans << std::endl;

  return 0;
}