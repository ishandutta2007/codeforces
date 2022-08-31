#include <iostream>
#include <vector>

#define int long long

int palin(std::vector<int> a) {
  int n = a.size();
  int ret = 1;
  for(int i = 0; i < n; i++)
    if(a[i] != a[n-1-i])
      ret = 0;
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int l = 0, r = n-1;
    while(a[l] == a[r] && l < r) {
      l++;
      r--;
    }

    if(l >= r) {
      std::cout << "YES" << std::endl;
      continue;
    }

    int ret = 0;
    std::vector<int> b;

    for(int i = l; i <= r; i++) {
      if(a[i] != a[l])
        b.push_back(a[i]);
    }
    ret |= palin(b);

    b.clear();
    for(int i = l; i <= r; i++) {
      if(a[i] != a[r])
        b.push_back(a[i]);
    }
    ret |= palin(b);

    std::cout << (ret ? "YES" : "NO") << std::endl;
  }

  return 0;
}