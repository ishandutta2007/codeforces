#include <iostream>

#define int long long

int rnk[50005][5];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int best = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 5; j++)
        std::cin >> rnk[i][j];
    }

    for(int i = 1; i < n; i++) {
      int count = 0;
      for(int j = 0; j < 5; j++) {
        if(rnk[i][j] < rnk[best][j])
          count++;
      }
      if(count >= 3)
        best = i;
    }

    bool poss = true;
    for(int i = 0; i < n; i++) {
      if(i == best)
        continue;
      int count = 0;
      for(int j = 0; j < 5; j++) {
        if(rnk[i][j] < rnk[best][j])
          count++;
      }
      if(count >= 3)
        poss = false;
    }

    if(poss)
      std::cout << best+1 << std::endl;
    else
      std::cout << -1 << std::endl;
  }

  return 0;
}