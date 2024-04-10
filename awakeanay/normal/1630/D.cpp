#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MAXN = 1000006;
const int INF = 1'000'000'000'000'000'000;

int n, k;
int a[MAXN];
std::vector<int> b[MAXN];

int solve() {
  int best[k][2];

  for(int j = 0; j < k; j++) {
    best[j][0] = best[j][1] = -INF;
    std::sort(b[j].begin(), b[j].end());

    int cur = 0;
    for(int x : b[j])
      cur += x;

    int it = 0;
    best[j][it] = std::max(best[j][it], cur);

    for(int x : b[j]) {
      it ^= 1;
      cur -= 2*x;
      best[j][it] = std::max(best[j][it], cur);
    }
  }

  int out = -INF;
  for(int x = 0; x < 2; x++) {
    int add = best[0][x];
    for(int i = 1; i < k; i++) {
      int next = -INF;
      for(int j = 0; j < 2; j++) {
        next = std::max(next, best[i][j] + ((j^x) ? -a[i] : a[i]));
      }
      add += next;
    }

    out = std::max(out, add);
  }

  return out;
}

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int m;
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++)
      std::cin >> a[i];

    k = 0;
    for(int j = 0; j < m; j++) {
      int x;
      std::cin >> x;
      k = gcd(k, x);
    }

    for(int i = 0; i < k; i++)
      b[i].clear();

    for(int i = k; i <= n; i++) {
      b[i%k].push_back(a[i]);
    }

    std::cout << solve() << std::endl;
  }

  return 0;
}