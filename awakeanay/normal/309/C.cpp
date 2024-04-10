#include <iostream>
#include <algorithm>
#include <set>

#define int long long

int avail[32];
int req[32];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    for(int j = 0; j < 32; j++) {
      if((x >> j) & 1ll)
        avail[j]++;
    }
  }


  for(int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    req[x]++;
  }

  int ans = 0;
  for(int j = 0; j < 32; j++) {
    for(int i = 0; i < req[j]; i++) {
      int first = 32;
      for(int k = j; k < 32; k++) {
        if(avail[k]) {
          first = k;
          break;
        }
      }

      if(first == j) {
        avail[j]--;
        ans++;
      }
      else if(first == 32) {
        break;
      }
      else {
        avail[first]--;
        for(int i = j; i < first; i++)
          avail[i]++;
        ans++;
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}