#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

bool check(std::vector<int> a) {
  int n = a.size();
  bool poss = true;
  for(int i = 0; i < n; i++) {
    int l = (i-1+n)%n;
    int r = (i+1)%n;
    poss &= (a[l] < a[i] && a[r] < a[i]) || (a[l] > a[i] && a[r] > a[i]);
  }
  return poss;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int b[n];
    for(int i = 0; i < n; i++)
      std::cin >> b[i];

    std::vector<int> a(n, 0);
    std::sort(b, b+n);

    int mid = n/2-1;
    for(int i = 1; i < n; i+=2) {
      a[i] = b[mid--];
    }
    mid = n-1;
    for(int i = 0; i < n; i+=2) {
      a[i] = b[mid--];
    }

    if(check(a)) {
      std::cout << "YES" << std::endl;
      for(int j : a)
        std::cout << j << " ";
      std::cout << std::endl;
    }
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}