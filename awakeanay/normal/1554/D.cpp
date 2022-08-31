#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int ts;
  std::cin >> ts;

  while(ts--) {
    int n;
    std::cin >> n;

    if(n <= 10) {
      for(int i = 0; i < n; i++)
        std::cout << (char)('a' + i);
      std::cout << std::endl;
      continue;
    }

    int a, b, c;
    if(n%2 == 0) {
      b = 1;
      c = (n-2)/2;
      a = c+1;
    }
    else {
      b = 2;
      c = (n-3)/2;
      a = c+1;
    }

    for(int i = 0; i < a; i++)
      std::cout << 'a';
    for(int j = 0; j < b; j++)
      std::cout << ((char)('b' + j));
    for(int i = 0; i < c; i++)
      std::cout << 'a';

    std::cout << std::endl;
  }

  return 0;
}