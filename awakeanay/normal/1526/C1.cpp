#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define int long long

const int MAXN = 200005;
int N;

signed main() {
  std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  N = n;

  int a[n];

  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::set<std::pair<int, int> > taken;

  int ans = 0;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    if(sum + a[i] >= 0) {
      sum += a[i];
      ans++;
      taken.insert({a[i], i});
    }
    else {
      int ws = (*taken.begin()).first;
      if(a[i] > ws) {
        sum -= ws;
        sum += a[i];
        taken.erase(taken.begin());
        taken.insert({a[i], i});
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}