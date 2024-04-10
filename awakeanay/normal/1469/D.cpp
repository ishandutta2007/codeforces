#include <iostream>
#include <vector>

#define int long long
std::vector<std::pair<int, int> > output;

void solve(int n) {
  if(n <= 2) {
    return;
  }

  int i;
  for(i = n-1; (i-1)*(i-1) >= n; i--) {
    output.push_back({i, n});
  }

  for(int j = 0; j < 2; j++)
    output.push_back({n, i});

  solve(i);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;
    output.clear();
    solve(n);
    std::cout << output.size() << std::endl;
    for(auto i : output) {
      std::cout << i.first << " " << i.second << std::endl;
    }
  }

  return 0;
}