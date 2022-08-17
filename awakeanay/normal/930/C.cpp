#include <iostream>
#include <vector>

#define int long long

std::vector<int> bit;

int max(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret = std::max(ret, bit[x]);
    x -= x&(-x);
  }
  return ret;
}

void upd(int x, int v) {
  x += 1;
  while(x < bit.size()) {
    bit[x] = std::max(bit[x], v);
    x += x&(-x);
  }
}

signed main() {
  int n, m;
  std::cin >> n >> m;
  
  std::vector<int> open(m+2, 0), close(m+2, 0);
  for(int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    open[x]++;
    close[y]++;
  }

  std::vector<int> count;
  int cur = 0;
  for(int i = 1; i <= m; i++) {
    cur += open[i];
    count.push_back(cur);
    cur -= close[i];
  }

  bit = std::vector<int>(n+5, 0);
  std::vector<int> lis(m, 0), lds(m, 0);
  for(int i = 0; i < m; i++) {
    lis[i] = max(count[i]) + 1;
    upd(count[i], lis[i]);
  }

  bit = std::vector<int>(n+5, 0);
  for(int i = m-1; i >= 0; i--) {
    lds[i] = max(count[i]) + 1;
    upd(count[i], lds[i]);
  }

  int ans = 0;
  for(int i = 0; i < m; i++) {
    ans = std::max(ans, lds[i]+lis[i]-1);
  }

  std::cout << ans << std::endl;

  return 0;
}