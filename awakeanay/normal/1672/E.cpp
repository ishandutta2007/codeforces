#include <iostream>
#include <vector>

#define int long long

const int INF = 5000'006;

int query(int x) {
  std::cout << "? " << x << std::endl;
  int ret;
  std::cin >> ret;
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int lo = 1, hi = INF;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    int ret = query(mid);
    if(ret == 1)
      hi = mid;
    else
      lo = mid+1;
  }

  int best = lo;
  std::vector<int> test;
  int ct = 0;
  for(int i = best-1; i >= 1 && ct < n+2; i--) {
    test.push_back(i);
    ct++;
  }

  for(int i = 1; i <= n+2; i++) {
    for(int j : test) {
      if(j%i == 0) {
        int ret = query(j/i);
        if(ret != 0)
          best = std::min(best, ret*(j/i));
        break;
      }
    }
  }

  std::cout << "! " << best << std::endl;

  return 0;
}