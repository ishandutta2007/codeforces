#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int MAGIC = 100;
const int N = 100005;

bitset <N> vis;
int n, k, a[N], g; 

int main() {
  srand(time(0));
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int it = 0; it < MAGIC; ++it) {
    random_shuffle(a + 1, a + n + 1);
    int g = 0;
    for (int i = 1; i <= n; ++i) {
      int x = a[i];
      if (rand() & 1) x %= k;
      g = __gcd(g, x);
    }
    for (int i = 0; i < k; ++i) {
      vis[i * 1LL * g % k] = 1;
    }
  }
  printf("%d\n", (int) vis.count());
  for (int i = 0; i < k; ++i) {
    if (vis[i]) printf("%d ", i);
  }
  puts("");
  return 0;
}