#include <iostream>
#include <vector>
#include <stack>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int min = n+1;
    std::stack<int> s;
    std::vector<int> choose;

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(x < min) {
        min = x;
        s.push(x);
      }
      else
        choose.push_back(x);
    }

    while(!s.empty()) {
      std::cout << s.top() << " ";
      s.pop();
    }
    for(int j : choose)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}