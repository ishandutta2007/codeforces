#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int mxa = -1;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      mxa = std::max(mxa, x);
    }

    int m;
    std::cin >> m;
    int mxb = -1;
    for(int i = 0; i < m; i++) {
      int x;
      std::cin >> x;
      mxb = std::max(mxb, x);
    }

    if(mxa == mxb) {
      std::cout << "Alice\nBob\n";
    }
    else if(mxa > mxb) {
      std::cout << "Alice\nAlice\n";
    }
    else
      std::cout << "Bob\nBob\n";
  }

  return 0;
}