#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
  int n, m;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  std::cin >> m;
  std::vector<int> v2(m);
  for(int i = 0; i < m; i++)
    std::cin >> v2[i];
  int ptr = 0, ptr2 = 0;
  int result = 0;
  std::sort(v.begin(), v.end());
  std::sort(v2.begin(), v2.end());

  while(ptr < v.size() && ptr2 < v2.size()) {
    if(v[ptr] + 1 < v2[ptr2]) {
      ptr++;
    } else if(v2[ptr2] + 1 < v[ptr])
      ptr2++;
    else {
      result++;
      ptr++;
      ptr2++;
    }
  }
  std::cout << result << '\n';
  return 0;
}