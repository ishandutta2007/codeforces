#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    int pref[n];
    std::vector<int> best;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      pref[i] = a[i];
      if(i)
        pref[i] = std::max(pref[i], pref[i-1]);
      if(pref[i] == a[i])
        best.push_back(i);
    }
    best.push_back(n);

    int m = best.size();
    for(int i = m-2; i >= 0; i--) {
      for(int j = best[i]; j < best[i+1]; j++)
        std::cout << a[j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}