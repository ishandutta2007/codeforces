#include <iostream>
#include <vector>

#define int long long

const int MAXA = 100005;
const int LOG = 20;

signed main() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> last[LOG];

  for(int i = 0; i < LOG; i++)
    last[i] = std::vector<int>(n+2, n+1);

  std::vector<int> lp(MAXA, n+1);

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  for(int i = n-1; i >= 0; i--) {
    int cur = n;
    for(int j = 2; j*j <= a[i]; j++) {
      if(a[i]%j == 0) {
        cur = std::min(cur, lp[j]);
        lp[j] = i;
        while(a[i]%j == 0)
          a[i] /= j;
      }
    }

    if(a[i] > 1) {
      cur = std::min(lp[a[i]], cur);
      lp[a[i]] = i;
    }

    last[0][i] = cur;
    last[0][i] = std::min(last[0][i], last[0][i+1]);
  }

  for(int j = 1; j < LOG; j++) {
    for(int i = 0; i < n; i++)
      last[j][i] = last[j-1][last[j-1][i]];
  }

  while(q--) {
    int l, r;
    std::cin >> l >> r;
    l--;

    int ans = 0;
    for(int j = LOG-1; j >= 0; j--) {
      if(last[j][l] < r) {
        ans += (1 << j);
        l = last[j][l];
      }
    }

    std::cout << ans+1 << std::endl;
  }

  return 0;
}