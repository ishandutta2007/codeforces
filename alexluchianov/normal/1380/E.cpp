#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
std::vector<int> subjects[1 + nmax];
int v[1 + nmax], rep[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    subjects[v[i]].push_back(i);
    rep[v[i]] = i;
  }
  int result = 0;
  for(int i = 1;i < n; i++)
    result += (v[i] != v[i + 1]);
  std::cout << result << '\n';
  
  for(int i = 1; i < k; i++) {
    int x, y;
    std::cin >> x >> y;
    x = v[rep[x]];
    y = v[rep[y]];
    if(subjects[y].size() < subjects[x].size())
      std::swap(x, y);
    
    for(int i = 0; i < subjects[x].size(); i++) {
      int pos = subjects[x][i];
      if(1 < pos)
        result -= (v[pos - 1] != v[pos]);
      if(pos < n)
        result -= (v[pos] != v[pos + 1]);
      v[pos] = y;
      if(1 < pos)
        result += (v[pos - 1] != v[pos]);
      if(pos < n)
        result += (v[pos] != v[pos + 1]);
      subjects[y].push_back(subjects[x][i]);
    }
    subjects[x].clear();
    std::cout << result << '\n';
  }
}