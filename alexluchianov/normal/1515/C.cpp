#include <iostream>
#include <vector>
#include <set>

void solve() {
  int n, m, x;
  std::cin >> n >> m >> x;
  std::set<std::pair<int,int>> myset;
  std::cout << "YES\n";
  for(int i = 1; i <= m; i++)
    myset.insert({0, i});
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    std::set<std::pair<int,int>>::iterator it = myset.begin();
    std::cout << it->second << " ";
    myset.insert({it->first + val, it->second});
    myset.erase(it);
  }
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}