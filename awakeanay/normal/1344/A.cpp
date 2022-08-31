#include <iostream>
#include <set>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::set<int> s;
    int a[n];
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(x < 0) {
        x *= -1;
        x %= n;
        x *= -1;
        x += n;
        x %= n;
      }
      else
        x %= n;

      s.insert((x+i)%n);
    }

    if(s.size() == n)
      std::cout << "YES";
    else
      std::cout << "NO";

    std::cout << std::endl;
  }
}