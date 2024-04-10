#include <iostream>

#define int long long

#define MAXN 1000006

int bit[MAXN];

void add(int x, int val) {
  x += 1;
  while(x < MAXN) {
    bit[x] = std::max(bit[x], val);
    x += x&(-x);
  }
}

int find(int x) {
  int ret = 0;
  x += 1;
  while(x > 0) {
    ret = std::max(ret, bit[x]);
    x -= x&(-x);
  }
  return ret;
}
  
signed main() {
  int n, m;
  std::cin >> n >> m;

  int a[n], b[n], c[m], d[m];
  for(int i = 0; i < n; i++)
    std::cin >> a[i] >> b[i];
  for(int i = 0; i < m; i++)
    std::cin >> c[i] >> d[i];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(d[j] >= b[i]) {
        add(MAXN-2-d[j]+b[i], c[j]-a[i]+1);
      }
    }
  }

  int ans = 10000000;
  for(int i = 0; i < MAXN-1; i++) {
    ans = std::min(ans, i+find(MAXN-2-i));
  }

  std::cout << ans << std::endl;

  return 0;
}