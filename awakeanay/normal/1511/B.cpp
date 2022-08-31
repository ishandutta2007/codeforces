#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << 1;
    for(int i = 1; i < a; i++)
      std::cout << 0;
    std::cout << " ";

    int zer = c-1;
    int sev = b-zer;
    for(int i = 0; i < sev; i++)
      std::cout << 7;
    for(int i = 0; i < zer; i++)
      std::cout << 0;
    std::cout << std::endl;
  }

  return 0;
}