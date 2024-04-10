#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::pair<std::string, int> s[n];
  for(int i = 0; i < n; i++) {
    std::cin >> s[i].first;
    for(int j = 1; j < m; j+=2)
      s[i].first[j] = 'Z'-s[i].first[j];
    s[i].second = i+1;
  }

  std::sort(s, s+n);

  for(int i = 0; i < n; i++) {
    std::cout << s[i].second << " ";
  }

  std::cout << std::endl;
  return 0;
}