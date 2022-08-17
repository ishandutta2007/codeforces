#include <iostream>

const int INF = 100005;

int q(int x) {
  int ret;
  std::cout << "? " << x << std::endl;
  std::cin >> ret;
  return ret;
}

int n;

int query(int x) {
  int l, a, r;

  a = q(x);

  if(x == n) {
    r = INF;
  }
  else {
    r = q(x+1);
  }
  
  if(a > r)
    return 1;
  else
    return 0;
}

signed main() {
  std::cin >> n;

  int l = 1, r = n;

  while(l < r) {
    int mid = (l+r)/2;
    if(query(mid)) {
      l = mid+1;
    }
    else {
      r = mid;
    }
  }

  std::cout << "! " << l << std::endl;
}