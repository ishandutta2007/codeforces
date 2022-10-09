#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 500;
int dp[1 + nmax][1 + nmax];

int main() {
  int n, k;
  std::cin >> n >> k;
  dp[0][0] = 1;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    for(int j = k; 0 <= j; j--)
      for(int j2 = j; 0 <= j2; j2--) {
        if(val <= j)
          dp[j][j2] |= dp[j - val][j2];
        if(val <= j2)
          dp[j][j2] |= dp[j - val][j2 - val];
        }
  }
  std::vector<int> sol;
  for(int i = 0;i <= k; i++)
    if(0 < dp[k][i])
      sol.push_back(i);
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';

  return 0;
}