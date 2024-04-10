#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[5 + nmax], frec[5 + nmax], seen[5 + nmax];
int v2[5 + nmax];

bool compare(std::pair<int,int> x, std::pair<int,int> y) {
  if(x.first == y.first)
    return x.second < y.second;
  else if(frec[x.first] == frec[y.first])
    return x.first < y.first;
  else
    return frec[x.first] < frec[y.first];
}

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  int _free = n - y, null_var = 0;
  y -= x;
  for(int i = 1; i <= n; i++)
    v2[i] = 0;

  for(int i = 1;i <= n + 1; i++)
    frec[i] = seen[i] = 0;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::vector<std::pair<int,int>> aux;
  
  for(int i = 1;i <= n; i++) {
    frec[v[i]]++;
    aux.push_back({frec[v[i]], i});
  }
  
  for(int i = 1;i <= n + 1; i++)
    if(frec[i] == 0)
      null_var = i;

  std::sort(aux.begin(), aux.end());
  std::reverse(aux.begin(), aux.end());
  for(int i = 0; i < x; i++) {
    seen[aux[i].second] = 1;
    v2[aux[i].second] = v[aux[i].second];
    frec[v[aux[i].second]]--;
  }
  
  std::vector<std::pair<int,int>> sol;

  for(int i = 1;i <= n; i++)
    if(seen[i] == 0) {
      sol.push_back({v[i], i});
    }
  std::sort(sol.begin(), sol.end(), compare);
  int ptr = 0;
  std::vector<std::pair<int,int>> colors;
  for(int i = 1; i <= n + 1;i++)
    if(0 < frec[i])
      colors.push_back({frec[i], i});
  
  std::sort(colors.begin(), colors.end());

  if(0 < colors.size()) {
    for(int j = colors.size() - 1; 0 < j; j--)
      std::swap(colors[j - 1], colors[j]);
  }
  
  for(int i = 0; i < colors.size(); i++) {
    for(int j = 0; j < colors[i].first; j++)
      if(sol[ptr].first == colors[i].second || y == 0) {
        if(0 < _free) {
          _free--;
          v2[sol[ptr].second] = null_var;
          ptr++;
        } else {
          std::cout << "NO\n";
          return ;
        }
      } else {
        v2[sol[ptr].second] = colors[i].second;
        ptr++;
        y--;
      }
  }

  std::cout << "YES\n";
  for(int i = 1; i <= n; i++)
    std::cout << v2[i] << " ";
  std::cout << '\n';
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