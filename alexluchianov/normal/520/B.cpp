#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 20000;

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> dp(1 + nmax, 2 * nmax);
  dp[n] = 0;
  std::queue<int> q;
  q.push(n);
  while(0 < q.size()) {
    int node = q.front();
    q.pop();

    if(node * 2 <= nmax && dp[node] + 1 < dp[node * 2]) {
      dp[node * 2] = dp[node] + 1;
      q.push(node * 2);
    }
    if(1 < node && dp[node] + 1 < dp[node - 1]) {
      dp[node - 1] = dp[node] + 1;
      q.push(node - 1);
    }
  }
  std::cout << dp[m];
}