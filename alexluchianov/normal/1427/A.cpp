#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += v[i];
  std::sort(v.begin(), v.end());
  if(sum == 0) 
    std::cout << "NO\n";
  else {
    if(0 < sum)
      std::reverse(v.begin(), v.end());
    std::cout << "YES\n";
    for(int i = 0; i < v.size(); i++)
      std::cout << v[i] << " ";
    std::cout << '\n';
  }
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}