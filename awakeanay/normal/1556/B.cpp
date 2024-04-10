#include <iostream>

#define int long long

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

const int INF = 100000000000000;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int best = INF;
    for(int m = 0; m < 2; m++) {
      int cur = 0;
      int id1 = 0, id2 = 1;
      for(int i = 0; i < n; i++) {
        if((a[i]%2)^m) {
          cur += abso(i-id1);
          id1 += 2;
        }
        else {
          cur += abso(i-id2);
          id2 += 2;
        }
      }

      if(abso(id1-id2) == 1)
        best = std::min(best, cur);
    }

    std::cout << (best == INF ? -1 : best/2) << std::endl;
  }

  return 0;
}