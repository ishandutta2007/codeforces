#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n = 15;
    std::vector<int> div[n+1];
    for(int i = 2; i <= n; i++) {
      for(int j = 2*i; j <= n; j+=i)
        div[j].push_back(i);
    }

    int win[n+1];
    for(int i = 1; i <= n; i++) {
      win[i] = 0;
      for(int j : div[i])
        if(!win[i-j])
          win[i] = 1;
    }

    int x;
    std::cin >> x;
    int p = x;
    int ct = 0;
    while(p%2 == 0) {
      ct++;
      p /= 2;
    }

    if(p == 1 && (ct%2)) {
      std::cout << "Bob" << std::endl;
      continue;
    }

    if(x <= n)
      std::cout << (win[x] ? "Alice" : "Bob") << std::endl;
    else
      std::cout << ((x%2) ? "Bob" : "Alice") << std::endl;
  }

  return 0;
}