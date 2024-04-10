#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int a = 0, b = 0;
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == '0')
        a++;
      else
        b++;
    }

    if(std::min(a, b)%2)
      std::cout << "DA";
    else
      std::cout << "NET";

    std::cout << std::endl;
  }

  return 0;
}