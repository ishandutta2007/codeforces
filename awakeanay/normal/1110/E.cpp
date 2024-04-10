#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

std::vector<std::vector<int> > v;

int calc(int m, int i) {
  return v[m][i+1] + v[m][i-1] - v[m][i];
}

signed main() {
  int n;
  std::cin >> n;

  v = std::vector<std::vector<int> >(2, std::vector<int>(n));
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < n; j++)
      std::cin >> v[i][j];

  for(int m = 0; m < 2; m++) {
    for(int i = n-1; i > 0; i--)
      v[m][i] -= v[m][i-1];

    std::sort(v[m].begin() + 1, v[m].end());
  }
      
  if(v[0] == v[1])
    std::cout << "Yes";
  else
    std::cout << "No";

  std::cout << std::endl;

  return 0;
}