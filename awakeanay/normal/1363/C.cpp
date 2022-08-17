#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, x;
    std::cin >> n >> x;
    x--;

    std::vector<int> deg(n, 0);
    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      deg[u]++;
      deg[v]++;
    }

    if(deg[x] <= 1)
      std::cout << "Ayush" << std::endl;
    else if((n)%2)
      std::cout << "Ashish" << std::endl;
    else
      std::cout << "Ayush" << std::endl;
  }

  return 0;
}