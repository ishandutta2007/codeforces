#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;

int const sigma = 30;
int frec[1 + sigma], frec2[1 + sigma];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    for(int h = 0; h < sigma; h++)
      if((1 << h) & val)
        frec[h]++;
  }
  for(int i = 1;i <= m; i++) {
    int val;
    std::cin >> val;
    frec2[val]++;
  }
  int result = 0;
  for(int i = 0; i < sigma; i++) {
    for(int j = 1;j <= frec2[i]; j++) {
      for(int h = i; h < sigma; h++) 
        if(0 < frec[h]) {
          frec[h]--;
          result++;
          for(int h2 = i; h2 < h; h2++)
            frec[h2]++;
          break;
        }
    }
  }
  std::cout << result;
  return 0;
}