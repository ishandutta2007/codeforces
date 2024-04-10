/*
Author: AwakeAnay
Date: 06/02/2020
Time: 23:14:53
*/

#include <iostream>
#include <vector>

int main() {
  int n, q;
  std::cin >> n >> q;

  int l = -1;
  int time = 0;
  std::vector<int> count(n, 0);
  std::vector<int> last(n, -1);
  std::vector<int> data(q, -1);
  int ans = 0;

  for(int i = 0; i < q; i++) {
    int t;
    std::cin >> t;
    
    if(t == 1) {
      ans++;
      int x;
      std::cin >> x; x--;
      count[x]++;
      data[i] = x;
    } else if(t == 2) {
      int x;
      std::cin >> x; x--;
      ans -= count[x];
      count[x] = 0;
      last[x] = i;
    } else {
      int x;
      std::cin >> x;
      while(time < x) {
        l++;
        if(data[l] >= 0 && last[data[l]] < l) {
          count[data[l]]--;
          ans--;
        }
        time += data[l] > -1;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}