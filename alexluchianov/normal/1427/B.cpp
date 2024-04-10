#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve() {
  int n, k;
  std::cin >> n >> k;
  ll result = 0;
  int last = -1, sum = 0;
  std::vector<int> dist;
  for(int i = 1;i <= n; i++) {
    char ch;
    std::cin >> ch;
    if(ch == 'W') {
      sum++;
      if(last + 1 < i){
        result++;
        if(0 < last)
          dist.push_back(i - last - 1);
      } else
        result += 2;
      last = i;
    }
  }
  if(n <= sum + k)
    std::cout << n * 2 - 1 << '\n';
  else {
    if(sum == 0 && 0 < k)
      std::cout << 2 * k - 1 << '\n';
    else {
      std::sort(dist.begin(), dist.end());
      result += 2 * k;
      for(int i = 0; i < dist.size(); i++) {
        if(dist[i] <= k) {
          k -= dist[i];
          result++;
        }
      }
      std::cout << result << '\n';
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}