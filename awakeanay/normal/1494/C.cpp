#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

int calc(std::vector<int> a, std::vector<int> b) {
  if(a.size() == 0 || b.size() == 0)
    return 0;

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int n = a.size();
  int m = b.size();
  int val[n];
  for(int i = n-1; i >= 0; i--) {
    int f = std::lower_bound(b.begin(), b.end(), a[i])-b.begin();
    val[i] = 0;
    if(i+1 < n)
      val[i] = val[i+1];

    if(f < m && b[f] == a[i])
      val[i]++;
  }

  int ans = 0;
  for(int i = 0; i < m; i++) {
    int k = std::upper_bound(a.begin(), a.end(), b[i])-a.begin();

    int cur = 0;
    if(k < n)
      cur += val[k];

    if(k == 0) {
      ans = std::max(cur, ans);
      continue;
    }

    int r = b[i], l = b[i]-k+1;
    int count1 = b.end()-std::lower_bound(b.begin(), b.end(), l);
    int count2 = b.end()-std::upper_bound(b.begin(), b.end(), r);
    cur += count1 - count2;

    ans = std::max(cur, ans);
  }

  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a[2], b[2];
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(x > 0)
        a[0].push_back(x);
      else
        a[1].push_back(-x);
    }

    for(int i = 0; i < m; i++) {
      int x;
      std::cin >> x;
      if(x > 0)
        b[0].push_back(x);
      else
        b[1].push_back(-x);
    }

    int ans = 0;
    ans += calc(a[0], b[0]);
    ans += calc(a[1], b[1]);

    std::cout << ans << std::endl;
  }

  return 0;
}