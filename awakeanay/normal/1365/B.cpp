#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n], b[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    for(int i = 0; i < n; i++)
      std::cin >> b[i];

    int present[2];
    present[0] = present[1] = 0;

    bool poss = true;
    int last = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] < last)
        poss = false;
      present[b[i]] = true;
      last = a[i];
    }

    if((present[0] && present[1]) || poss)
      std::cout << "Yes";
    else
      std::cout << "No";

    std::cout << std::endl;
  }

  return 0;
}