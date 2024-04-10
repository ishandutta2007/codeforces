#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>

using ll = long long;

int const nmax = 300000;
int const inf = 1000000000;
int const lgmax = 20;

int v[5 + nmax], cost[5 + nmax];
int far[1 + lgmax][5 + nmax];
ll farcost[1 + lgmax][5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q, k;
  std::cin >> n >> q >> k;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::deque<int> dq;
  for(int i = n; 1 <= i; i--) {
    while(0 < dq.size() && v[i] <= v[dq.back()])
      dq.pop_back();
    dq.push_back(i);
    while(i + k < dq.front())
      dq.pop_front();
    cost[i] = v[dq.front()];
  }

  far[0][n + 1] = n + 1;
  cost[n + 1] = 0;

  for(int i = n; 1 <= i; i--) {
    far[0][i] = i + k;
    if(n < far[0][i])
      far[0][i] = n + 1;
    while(cost[i] < cost[far[0][i]])
      far[0][i] = far[0][far[0][i]];
    farcost[0][i] = 1LL * (far[0][i] - i + k - 1) / k * cost[i];
  }

  for(int h = 1; h <= lgmax; h++)
    for(int i = 1;i <= n + 1; i++) {
      far[h][i] = far[h - 1][far[h - 1][i]];
      farcost[h][i] = farcost[h - 1][i] + farcost[h - 1][far[h - 1][i]];
    }

  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    ll result = v[x];
    for(int h = lgmax; 0 <= h; h--)
      if(far[h][x] <= y) {
        result += farcost[h][x];
        x = far[h][x];
      }
    result += 1LL * (y - x) / k * cost[x];
    std::cout << result << '\n';
  }
  return 0;
}