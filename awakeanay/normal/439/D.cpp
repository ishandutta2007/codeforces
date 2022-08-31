#include <iostream>
#include <algorithm>
#include <set>

#define int long long
#define INF 100000000000000000

signed main() {
  int n, m;
  std::cin >> n >> m;

  int a[n];
  std::set<int> s;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    s.insert(a[i]);
  }

  int b[m];
  for(int i = 0; i < m; i++) {
    std::cin >> b[i];
    s.insert(b[i]);
  }

  std::sort(a, a+n);
  std::sort(b, b+m);

  int prea[n];
  int preb[m];

  for(int i = 0; i < n; i++) {
    prea[i] = a[i];
    if(i) prea[i] += prea[i-1];
  }

  for(int i = 0; i < m; i++) {
    preb[i] = b[i];
    if(i) preb[i] += preb[i-1];
  }

  int ans = INF;
  while(!s.empty()) {
    int u = *s.begin();
    s.erase(s.begin());

    int bchan = 0;
    auto it = std::lower_bound(b, b+m, u);
    if(it != b+m) {
      int ind = it-b;
      bchan = preb[m-1];
      if(ind) bchan -= preb[ind-1];
      bchan -= (m-ind)*u;
    }

    int achan = 0;
    it = std::lower_bound(a, a+n, u);
    if(it != a) {
      int ind = it-a;
      achan = prea[ind-1];
      achan = u*ind - achan;
    }

    ans = std::min(ans, achan + bchan);
  }
  std::cout << ans << std::endl;

  return 0;
}