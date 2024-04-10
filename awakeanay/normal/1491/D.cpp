#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
  int q;
  std::cin >> q;
  
  while(q--) {
    int a, b;
    std::cin >> a >> b;

    std::vector<int> p, q;
    for(int i = 0; i < 30; i++) {
      if((a >> i)&1)
        p.push_back(i);
      if((b >> i)&1)
        q.push_back(i);
    }

    bool poss = true;
    if(p.size() < q.size())
      poss = false;

    if(poss) {
      for(int i = 0; i < q.size(); i++) {
        if(p[i] > q[i])
          poss = false;
      }
    }

    std::reverse(p.begin(), p.end());
    std::reverse(q.begin(), q.end());

    bool poss2 = false;

    for(int i = 0; i < q.size(); i++) {
      if(p[i] != q[i]) {
        if(p[i] < q[i])
          poss2 = true;
        break;
      }
    }

    poss2 |= a == b;

    if(poss && poss2)
      std::cout << "YES";
    else
      std::cout << "NO";

    std::cout << std::endl;
  }

  return 0;
}