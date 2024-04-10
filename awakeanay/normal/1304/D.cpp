/*
Author: AwakeAnay
Date: 15/02/2020
Time: 18:40:12
*/

#include <iostream>
#include <algorithm>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int a[n];
    for(int i = 0; i < n; i++)
      a[i] = n-i;
  
    int last = 0;
    for(int i = 0; i < n-1; i++) {
      if(s[i] == '>') {
        std::reverse(a+last, a+i+1);
        last = i+1;
      }
    }

    std::reverse(a+last, a+n);

    for(int i = 0; i < n; i++)
      std::cout << a[i] << " ";
    
    std::cout << std::endl;

    for(int i = 0; i < n; i++)
      a[i] = i+1;
  
    last = 0;
    for(int i = 0; i < n-1; i++) {
      if(s[i] == '<') {
        std::reverse(a+last, a+i+1);
        last = i+1;
      }
    }

    std::reverse(a+last, a+n);

    for(int i = 0; i < n; i++)
      std::cout << a[i] << " ";
    
    std::cout << std::endl;
  }

  return 0;
}