#include <iostream>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int ans[n];
  ans[n-1] = 1;
  int val[n];
  val[n-1] = a[n-1];

  for(int i = n-2; i >= 0; i--) {
    if(val[i+1] >= a[i]) {
      ans[i] = -1;
      val[i] = val[i+1]-a[i];
    }
    else {
      ans[i] = 1;
      val[i] = a[i]-val[i+1];
    }
  }

  int mult = 1;
  for(int i = 0; i < n; i++) {
    int cur = ans[i]*mult;
    if(cur == 1)
      std::cout << "+";
    else
      std::cout << "-";
    if(ans[i] == 1)
      mult = -mult;
  }


}