#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, std::pair<int, int> > > vec;
  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];


  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j)
        continue;
      if(a[i] < a[j] || (a[i] == a[j] && i < j)) {
        vec.push_back({a[j]-a[i], {i+1, j+1}});
      }
    }
  }

  std::sort(vec.begin(), vec.end());
  std::reverse(vec.begin(), vec.end());

  for(int i = 0; i < vec.size(); i++) {
    std::cout << "? " << vec[i].second.second << " " << vec[i].second.first << std::endl;
    std::string ans;
    std::cin >> ans;
    if(ans == "Yes") {
      std::cout << "! " << vec[i].second.second << " " << vec[i].second.first << std::endl;
      return 0;
    }
  }

  std::cout << "! 0 0" << std::endl;

  return 0;
}