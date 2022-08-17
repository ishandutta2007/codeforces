#include <iostream>
#include <algorithm>

#define int long long

const int MOD = 998244353;
const int MAXN = 400010;
const int HALF = 200005;

int bit[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&-x;
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&-x;
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, s;
    std::cin >> n >> s;

    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      a[i]--;
      add(HALF-i, 1);
    }

    int p[n];
    int b[n];
    int q[n];
    for(int i = 0; i < n; i++)
      q[i] = -1;

    int ans = 1;
    for(int i = 0; i < n; i++) {
      std::cin >> p[i];
      if(p[i] != -1) {
        p[i]--;
        q[a[i]] = i;
        add(HALF-p[i], -1);
        ans &= p[i] >= a[i] - s;
      }
    }

    int taken = 0;
    for(int j = n-1; j >= 0; j--) {
      if(q[j] != -1)
        continue;
      int cur = std::max(0ll, sum(HALF-(j-s)) - taken);
      taken++;
      ans = (ans*cur)%MOD;
    }

    std::cout << ans << std::endl;

    for(int j = n-1; j >= 0; j--) {
      if(sum(HALF-j)) {
        add(HALF-j, -1);
      }
    }
  }

  return 0;
}