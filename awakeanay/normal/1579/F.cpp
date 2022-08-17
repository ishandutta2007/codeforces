#include <iostream>
#include <queue>

#define int long long

const int MAXN = 1000006;

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

int a[MAXN];
int b[MAXN];
std::queue<int> bfs;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, d;
    std::cin >> n >> d;

    int k = gcd(n, d);
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    for(int i = 0; i < k; i++)
      b[i] = 1;
    for(int i = 0; i < n; i++)
      b[i%k] &= a[i];

    bool imposs = 0;
    for(int i = 0; i < k; i++)
      imposs |= b[i];

    if(imposs) {
      std::cout << -1 << std::endl;
      continue;
    }

    int max = 0;
    for(int i = 0; i < n; i++)
      b[i] = -1;

    for(int i = 0; i < n; i++) {
      if(a[i] == 0) {
        bfs.push(i);
        b[i] = 0;
      }
    }

    while(!bfs.empty()) {
      int u = bfs.front();
      bfs.pop();

      max = b[u];
      
      int v = (u+n-d)%n;
      if(b[v] == -1) {
        b[v] = b[u] + 1;
        bfs.push(v);
      }
    }

    std::cout << max << std::endl;
  }

  return 0;
}