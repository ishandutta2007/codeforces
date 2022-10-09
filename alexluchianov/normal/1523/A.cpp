#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 1000;
int v[5 + nmax], v2[5 + nmax];

void solve() {
  int n, m;
  std::cin >> n >> m;
  m = std::min(n, m);
  for(int i = 1; i <= n; i++) {
    char ch;
    std::cin >> ch;
    v[i] = ch - '0';
  }
  v[0] = v[n + 1] = 0;
  for(int i = 1;i <= m; i++) {
    for(int j = 1;j <= n; j++)
      v2[j] = 0;
    for(int j = 1;j <= n; j++) 
      if(v[j] == 1)
        v2[j] = 1;
      else
        v2[j] = v[j - 1] ^ v[j + 1];
    for(int j = 1;j <= n; j++)
      v[j] = v2[j];
  }
  for(int i = 1;i <= n; i++)
    std::cout << v[i];
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}