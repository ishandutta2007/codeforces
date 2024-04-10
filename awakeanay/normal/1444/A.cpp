#include <iostream>
#include <vector>

#define int long long

std::vector<int> isP(100005, true);
std::vector<int> ps;

signed main() {
  int t;
  std::cin >> t;

  for(int i = 2; i < 100005; i++) {
    if(isP[i]) {
      ps.push_back(i);
      for(int j = 2*i; j < 100005; j+=i)
        isP[j] = false;
    }
  }

  while(t--) {
    int p, q;
    std::cin >> p >> q;

    if(p%q != 0) {
      std::cout << p << std::endl;
      continue;
    }

    int nq = q;
    int ans = 0;
    for(int i : ps) {
      if(i*i > nq)
        break;
      
      int d = i;
      if(nq%d == 0) {
        int count = 0;
        while(nq%d == 0) {
          count++;
          nq /= d;
        }

        int np = p;
        while(np%d == 0) { 
          np /= d;
        }

        for(int j = 1; j < count; j++) {
          np *= d;
        }

        ans = std::max(ans, np);
      }
    }

    while(p%nq == 0) {
      if(nq == 1) {
        p = 0;
        break;
      }
      p /= nq;
    }

    ans = std::max(ans, p);

    std::cout << ans << std::endl;
  }

  return 0;
}