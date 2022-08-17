#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);


  int q;
  std::cin >> q;

  while(q--) {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int max = 0;
    int count[n][3];
    for(int i = 0; i < n; i++) {
      count[i][0] = count[i][1] = count[i][2] = 0;
      int c;
      if(s[i] == 'R')
        c = 0;
      else if(s[i] == 'G')
        c = 1;
      else
        c = 2;
      count[i][(i-c+3)%3]++;
      if(i) {
        for(int j = 0; j < 3; j++) {
          count[i][j] += count[i-1][j];
        }
      }
      for(int j = 0; j < 3; j++) {
        if(i >= k-1) {
          max = std::max(max, count[i][j] - (i >= k ? count[i-k][j] : 0));
        }
      }
    }

    std::cout << k-max << std::endl;
  }

  return 0;
}