#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> v(1 + n), pref(1 + n);
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  for(int i = 1; i <= n; i++) 
    pref[i] = v[i] + pref[i - 1];
  int result = 0;
  for(int i = 1; i <= n; i++) {
    int x = 0;
    int base = 0;
    for(int jump = (1 << 20); 0 < jump; jump /= 2)
      if(i + x + jump - 1<=  n && pref[i + x + jump - 1] - pref[i - 1] <= m)
        x += jump;
    result = std::max(result, x);
  }
  std::cout << result;
}