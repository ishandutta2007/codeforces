#include <iostream>

#define int long long

int isComp(int x) {
  bool comp = false;
  for(int i = 2; i*i <= x; i++) {
    if(x%i == 0)
      comp = true;
  }
  return comp;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int odd = -1;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(a[i]%2)
        odd = i;
      sum += a[i];
    }

    if(isComp(sum)) {
      std::cout << n << std::endl;
      for(int i = 0; i < n; i++)
        std::cout << i+1 << " ";
      std::cout << std::endl;
    }
    else {
      std::cout << n-1 << std::endl;
      for(int i = 0; i < n; i++)
        if(odd != i)
          std::cout << i+1 << " ";
      std::cout << std::endl;
    }
  }

  return 0;
}