#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::string t = "2020";

    int a = 0;
    for(int i = 0; i < 4; i++) {
      if(s[i] != t[i])
        break;
      a++;
    }

    int b = 0;
    for(int i = 0; i < 4; i++) {
      if(s[n-1-i] != t[3-i])
        break;
      b++;
    }


    if(a+b >= 4)
      std::cout << "YES";
    else
      std::cout << "NO";

    std::cout << std::endl;
  }
  
  return 0;
}