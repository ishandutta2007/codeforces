#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MAXN = 400005;
const int HALF = 200001;
const int INF = 10000000;

std::vector<int> bit(MAXN, -INF);

void update(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] = std::max(bit[x], v);
    x += x&(-x);
  }
}

int max(int x) {
  x += 1;
  int ret = -INF;
  while(x > 0) {
    ret = std::max(bit[x], ret);
    x -= x&(-x);
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::pair<int, int> help[n];
  for(int i = 0; i < n; i++) {
    std::cin >> help[i].first;
    help[i].second = -i-1;
  }

  std::sort(help, help+n);

  int best = 0;

  update(0-0+HALF, 0);
  for(int i = 0; i < n; i++) {
    help[i].second *= -1;
    int cur = max(help[i].second-help[i].first+HALF)+1;
    if(help[i].second < help[i].first)
        continue;
    best = std::max(best, cur);
    update(help[i].second-help[i].first+HALF, cur);
  }

  std::cout << best << std::endl;

  return 0;
}