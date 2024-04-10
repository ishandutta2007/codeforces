#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <bitset>

using ll = long long;

int const nmax = 1000000;
std::vector<int> g[5 + nmax];
int sz[5 + nmax];

void computesz(int node, int parent) {
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      computesz(to, node);
      sz[node] += sz[to];
    }
  }
}

int find_centroid(int node, int target) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(sz[to] <= sz[node] && target <= sz[to])
      return find_centroid(to, target);
  }
  return node;
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 2;i <= n; i++) {
    int val;
    std::cin >> val;
    g[val].push_back(i);
    g[i].push_back(val);
  }
  computesz(1, 0);
  int root = find_centroid(1, (n + 1) / 2);
  
  computesz(root, 0);
  
  std::vector<int> values;
  for(int h = 0; h < g[root].size(); h++) {
    values.push_back(sz[g[root][h]]);
  }
  ll base = 0;
  for(int i = 1;i <= n; i++)
    base += sz[i] ;
  std::bitset<1 + nmax> dp;
  dp[0] = 1;
  std::sort(values.begin(), values.end());
  int count = 0;
 
  for(int i = 0; i < values.size(); i++) {
    if(values.size() == i + 1 || values[i] != values[i + 1]) {
      count++;
      int val = values[i];
      for(int j = 0; (1 << j) <= count ; j++) {
        dp |= dp<<(val<<j);
        count -= (1 << j);
      }
      dp |= (dp<<(val * count));
      count = 0;
    } else
      count++;
  }
  for(int i = n / 2; 0 <= i; i--)
    if(dp[i] == 1) {
      std::cout << base + 1LL * i * (n - i - 1) << '\n';
      return 0;
    }
  return 0;
}