#include <iostream>
#include <algorithm>

#define int long long

const int INF = 100000000000000;

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

signed main() {
  int n;
  std::cin >> n;

  std::pair<std::pair<int, int>, int> a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i].first.first;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i].first.second;
    a[i].second = 0;
  }

  int cur = 0;
  for(int i = 0; i < n; i++) {
    cur += abso(a[i].first.second-a[i].first.first);
    if(a[i].first.second > a[i].first.first) {
      a[i].first.first ^= a[i].first.second ^= a[i].first.first ^= a[i].first.second;
      a[i].second = 1;
    }
  }

  std::sort(a, a+n);

  int min[2];
  min[0] = min[1] = INF;
  min[a[n-1].second] = a[n-1].first.second;

  int best = 0;
  for(int i = n-2; i >= 0; i--) {
    int type = a[i].second;
    if(min[!type] < a[i].first.first) {
      best = std::max(best, a[i].first.first - std::max(a[i].first.second, min[!type]));
    }
    min[type] = std::min(min[type], a[i].first.second);
  }

  std::cout << cur - 2*best << std::endl;

  return 0;
}