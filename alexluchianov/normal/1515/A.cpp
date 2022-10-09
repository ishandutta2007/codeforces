#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());
  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += v[i];
  if(sum == x)
    std::cout << "NO\n";
  else {
    std::cout << "YES\n";
    sum = 0;
    int ptr = 0;
    while(ptr < n) {
      if(sum + v[ptr] == x) {
        sum += v[ptr + 1] + v[ptr];
        std::cout << v[ptr + 1] << " " << v[ptr] << " ";
        ptr += 2;
      } else {
        sum += v[ptr];
        std::cout << v[ptr] << " ";
        ptr++;
      }
    }
    std::cout << '\n';
  }
}
int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}