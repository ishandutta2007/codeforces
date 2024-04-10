#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::vector<int> count(4, 0);

  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    x /= 2;
    y /= 2;

    count[(x%2)*2+y%2]++;
  }

  int ans = 0;

  for(int i = 0; i < 4; i++) {
    for(int j = i+1; j < 4; j++) {
      for(int k = j+1; k < 4; k++) {
        int a1 = i%2, a2 = i/2;
        int b1 = j%2, b2 = j/2;
        int c1 = k%2, c2 = k/2;

        int eval = ((a1^b1)|(a2^b2)) + ((a1^c1)|(a2^c2)) + ((b1^c1)|(b2^c2));
        if(eval%2 == 0)
          ans += count[i]*count[j]*count[k];
      }
    }
  }

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j)
        continue;
      int a1 = i%2, a2 = i/2;
      int b1 = j%2, b2 = j/2;
      int c1 = i%2, c2 = i/2;

      int eval = ((a1^b1)|(a2^b2)) + ((a1^c1)|(a2^c2)) + ((b1^c1)|(b2^c2));
      if(eval%2 == 0)
        ans += ((count[i]*(count[i]-1))/2)*count[j];
    }
  }

  for(int i = 0; i < 4; i++) {
    int a1 = i%2, a2 = i/2;
    int b1 = i%2, b2 = i/2;
    int c1 = i%2, c2 = i/2;

    int eval = ((a1^b1)|(a2^b2)) + ((a1^c1)|(a2^c2)) + ((b1^c1)|(b2^c2));
    if(eval%2 == 0)
      ans += (count[i]*(count[i]-1)*(count[i]-2))/6;
  }

  std::cout << ans << std::endl;

  return 0;
}