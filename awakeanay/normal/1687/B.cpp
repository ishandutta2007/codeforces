#include <iostream>

#define int long long

int n, m;

int get(int x) {
  std::cout << "? ";
  for(int i = 0; i < m; i++)
    std::cout << (i == x);
  std::cout << std::endl;
  std::cin >> x;
  return x;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> m;

  std::pair<int, int> help[m];
  for(int i = 0; i < m; i++) {
    help[i].first = get(i);
    help[i].second = i;
  }

  int ans = 0;
  int cur = 0;
  std::sort(help, help+m);

  std::string s(m, '0');
  for(int i = 0; i < m; i++) {
    s[help[i].second] = '1';
    std::cout << "? " << s << std::endl;
    int next;
    std::cin >> next;
    if(next == cur + help[i].first) {
      ans += help[i].first;
    }
    cur = next;
  }

  std::cout << "! " << ans << std::endl;

  return 0;
}