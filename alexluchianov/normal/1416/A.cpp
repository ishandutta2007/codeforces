#include <iostream>
#include <algorithm>
#include <vector>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> v(2 + n);
  std::vector<int> frec(2 + n);
  std::vector<int> sol(2 + n, n + 1);
  std::vector<int> maxdif(2 + n, 0);
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    maxdif[v[i]] = std::max(maxdif[v[i]], i - frec[v[i]]);
    frec[v[i]] = i;
  }

  for(int i = 1;i <= n; i++)
    if(0 < frec[i]) {
      int result = std::max(maxdif[i], n + 1 - frec[i]);
      sol[result] = std::min(sol[result], i);
    }
  for(int i = 1; i <= n; i++)
    sol[i] = std::min(sol[i], sol[i - 1]);
  for(int i = 1;i <= n; i++)
    if(sol[i] == n + 1)
      std::cout << -1 << " ";
    else
      std::cout << sol[i] << " ";
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    solve();
  }
  return 0;
}