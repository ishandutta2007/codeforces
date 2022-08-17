#include <iostream>

#define int long long

const int INF = 100000000000;

const int MP = 6;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int best = INF;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    for(int i = 0; i < MP; i++) {
      for(int j = 0; j < MP; j++) {
        int cur = 0;

        for(int k = 0; k < n; k++) {
          int c1 = INF;
          for(int p = 0; p <= i; p++) {
            for(int q = 0; q <= j; q++) {
              if(a[k]-p-2*q >= 0 && (a[k]-p-2*q)%3 == 0)
                c1 = std::min(c1, (a[k]-p-2*q)/3);
            }
          }

          cur = std::max(cur, c1);
        }

        best = std::min(best, cur + i + j);
      }
    }

    std::cout << best << std::endl;
  }

  return 0;
}