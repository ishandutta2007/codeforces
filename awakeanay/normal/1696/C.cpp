#include <iostream>
#include <vector>

#define int long long

int m;
std::vector<std::pair<int, int> > reduce(std::vector<int> a) {
  std::vector<std::pair<int, int> > v;
  int n = a.size();
  for(int i = 0; i < n; i++) {
    int j = a[i];
    int ct = 1;
    while(j%m == 0) {
      j /= m;
      ct *= m;
    }
    if(v.size() && v.back().first == j) {
      v.back().second += ct;
    }
    else
      v.push_back({j, ct});
  }
  return v;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n >> m;

    std::vector<int> a, b;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      a.push_back(x);
    }

    int k;
    std::cin >> k;

    for(int i = 0; i < k; i++) {
      int x;
      std::cin >> x;
      b.push_back(x);
    }

    std::cout << (reduce(a) == reduce(b) ? "Yes" : "No") << "\n";

  }

  return 0;
}