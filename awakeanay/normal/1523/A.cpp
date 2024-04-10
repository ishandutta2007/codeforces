#include <iostream>

#define int long long

const int INF = 1000000007;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    int left[n], right[n];
    int best = INF;
    for(int i = 0; i < n; i++) {
      best++;
      if(s[i] == '1')
        best = 0;
      left[i] = best;
    }

    best = INF;
    for(int i = n-1; i >= 0; i--) {
      best++;
      if(s[i] == '1')
        best = 0;
      right[i] = best;
    }

    for(int i = 0; i < n; i++) {
      if(s[i] == '1' || ((left[i] <= m || right[i] <= m) && left[i] != right[i]))
        std::cout << 1;
      else
        std::cout << 0;
    }

    std::cout << std::endl;
  }

  return 0;
}