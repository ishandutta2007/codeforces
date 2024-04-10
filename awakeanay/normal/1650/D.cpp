#include <iostream>

#define int long long

const int MAXN = 200005;

int bit[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&-x;
  }
}

int sum(int x) {
  int ret = 0;
  x += 1;
  while(x > 0) {
    ret += bit[x];
    x -= x&-x;
  }
  return ret;
}

int sum(int l, int r) {
  return sum(r)-sum(l-1);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i <= n+1; i++)
      bit[i] = 0;

    int p[n];
    int rev[n+1];
    rev[n] = n;
    for(int i = 0; i < n; i++) {
      std::cin >> p[i];
      p[i]--;
      rev[p[i]] = i;
    }

    for(int i = 0; i < n; i++) {
      int j = rev[i+1];
      int s = sum(std::min(j, rev[i]), std::max(j, rev[i]));
      if(j < rev[i])
        s = i-s;
      std::cout << (i+1-s)%(i+1) << " ";
      add(rev[i], 1);
    }

    std::cout << "\n";
  }

  return 0;
}