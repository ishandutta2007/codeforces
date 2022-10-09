#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 3000;
int const lgmax = 11;
int v[1 + nmax];
std::vector<int> frec[1 + nmax];

int lowerthan(std::vector<int> &aux, int target) {
  int x = 0;
  for(int jump = (1 << lgmax); 0 < jump; jump /= 2)
    if(x + jump <= aux.size() && aux[x + jump - 1] <= target)
      x += jump;
  return x;
}

void solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    frec[i].clear();
  for(int i = 1; i <= n; i++) {
    std::cin >> v[i];
    frec[v[i]].push_back(i);
  }
  ll result = 0;
  for(int i = 1;i <= n; i++)
    for(int j = i + 1; j <= n; j++) 
      result += lowerthan(frec[v[j]], i - 1) * (frec[v[i]].size() - lowerthan(frec[v[i]], j));
  
  std::cout << result << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}