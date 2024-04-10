#include <iostream>
#include <algorithm>
#include <set>

#define int long long

signed main() {
  int a[6];
  for(int i = 0; i < 6; i++)
    std::cin >> a[i];

  std::sort(a, a+6);
  std::reverse(a, a+6);

  int n;
  std::cin >> n;

  int seq[n];
  int kind[n];
  std::set<std::pair<int, int> > s;
  for(int i = 0; i < n; i++) {
    std::cin >> seq[i];
    kind[i] = 0;
    s.insert({seq[i]-a[0], i});
  }

  int ans = (*s.rbegin()).first - (*s.begin()).first;
  while(true) {
    std::pair<int, int> cur = *s.begin();
    s.erase(s.begin());

    if(kind[cur.second] == 5)
      break;

    kind[cur.second]++;
    cur.first = seq[cur.second]-a[kind[cur.second]];
    s.insert(cur);

    ans = std::min(ans, (*s.rbegin()).first - (*s.begin()).first);
  }

  std::cout << ans << std::endl;

  return 0;
}