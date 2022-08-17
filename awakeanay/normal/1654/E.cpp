#include <iostream>
#include <algorithm>
#include <set>

#define int long long

const int BLK = 405;
const int MAXN = 100005;

signed poss[(BLK+1)*MAXN];

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int ans = 0;
  for(int i = 0; i <= BLK; i++) {
    for(int j = 0; j < n; j++) {
      poss[a[j] + j*i]++;
      ans = std::max(ans, (int) poss[a[j] + j*i]);
    }
    for(int j = 0; j < n; j++) {
      poss[a[j] + j*i] = 0;
    }
  }

  std::reverse(a, a+n);
  for(int i = 0; i <= BLK; i++) {
    for(int j = 0; j < n; j++) {
      poss[a[j] + j*i]++;
      ans = std::max(ans, (int) poss[a[j] + j*i]);
    }
    for(int j = 0; j < n; j++) {
      poss[a[j] + j*i] = 0;
    }
  }


  std::set<std::pair<signed, signed> > st[n];
  for(int i = n-1; i >= 0; i--) {
    int lim = std::min(n, i+BLK);
    std::set<int> solved;
    for(int j = i+1; j < lim; j++) {
      int d = j-i;
      int v = abso(a[j]-a[i]);
      if(v%d != 0)
        continue;

      int w = v/d;
      if(a[j] < a[i])
        w *= -1;
      if(solved.count(w))
        continue;
      solved.insert(w);

      auto it = st[j].lower_bound({w, -1});
      int cur = (it == st[j].end() || (*it).first != w) ? 1 : (*it).second;

      //std::cout << i << " " << j << " " << cur+1 << std::endl;

      st[i].insert({w, cur+1});
      ans = std::max(ans, cur+1);
    }
  }

  std::cout << n-ans << std::endl;

  return 0;
}