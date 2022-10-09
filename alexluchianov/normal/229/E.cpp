#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iomanip>

using ll = long long;
using ld = long double;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
ll const inf = 1000000000000000000;

int _count[1 + nmax], taken[1 + nmax];
ll comb[1 + nmax][1 + nmax];

void computecomb() {
  for(int i = 0;i <= nmax; i++) {
    comb[i][0] = 1;
    for(int j = 1; j <= i; j++) {
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
      if(inf < comb[i][j])
        comb[i][j] = inf;
    }
  }
}

ld dp[1 + nmax];

int main() {
  computecomb();
  int n, q;
  std::cin >> n >> q;
  std::vector<std::pair<int,int>> v;
  for(int i = 1;i <= q; i++) {
    std::cin >> _count[i];
    for(int j = 1; j <= _count[i]; j++) {
      int weight;
      std::cin >> weight;
      v.push_back({weight, i});
    }
  }
  std::sort(v.begin(), v.end());
  int left, right;
  left = right = v.size() - n;
  while(0 < left && v[left - 1].first == v[left].first)
    left--;
  int add = 1;
  while(right + 1 < v.size() && v[right].first == v[right + 1].first){
    right++;
    add++;
  }

  for(int ptr = v.size() - 1; right < ptr; ptr--)
    taken[v[ptr].second]++;
  dp[0] = 1;

  for(int i = 1;i <= q; i++) {
    bool flag = 0;
    for(int j = left; j <= right; j++)
      flag |= (i == v[j].second);
    if(0 < taken[i] && 0 == flag) 
      dp[0] = dp[0] / comb[_count[i]][taken[i]];
  }
  int total = (right - left + 1);

  for(int i = left; i <= right; i++) {
    int id = v[i].second;
    ld f1 = 1.0 / comb[_count[id]][taken[id]];
    ld f2 = 1.0 / comb[_count[id]][taken[id] + 1];
    for(int j = add; 0 < j; j--)
      ///   C(t, j) / C(t, j - 1) =
      /// = t! / j! / (t - j)! / t! * (j - 1)! * (t - j + 1)! =
      /// = (t - j + 1) / j
      dp[j] = dp[j] * f1 + dp[j - 1] * f2 * j / (total - j + 1);
    dp[0] = dp[0] * f1;
  }
  std::cout << std::setprecision(9) << std::fixed << dp[add] << '\n';
}