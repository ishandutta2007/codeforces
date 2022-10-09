#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

int const nmax = 1000000;
int init[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int,int>> v;
  std::vector<std::vector<int>> sol;
  
  int sum = 0, tours = 0;
  for(int i = 0;i < m; i++) {
    int val;
    std::cin >> val;
    v.push_back({val, i});
    sum += val;
  }

  v[0].first += (n - (sum % n)) % n;
  sum += (n - (sum % n)) % n;
  tours = sum / n;
  sol.resize(tours);
  
  for(int i = 0; i < tours; i++)
    sol[i].resize(m);

  int ptr = 0;
  
  
  for(int i = 0; i < m; i++) {
    while(n <= v[i].first) {
      v[i].first -= n;
      for(int j = 0; j < m; j++)
        sol[ptr][j] = i;
      ptr++;
    }
  }
  std::sort(v.begin(), v.end());
  
  for(int i = 0; i < m; i++) {
    if(ptr == tours) {
      init[i] = n;
      break;
    } else if(n == 0)
      break;
    if(v[i].first < n - v.back().first) {
      init[i] = v[i].first;
      n -= v[i].first;
      
      for(int j = ptr; j < tours; j++) {
        v[i + (j - ptr)].first -= init[i];
        sol[j][i] = v[i + (j - ptr)].second;
      }
    } else {
      init[i] = n - v.back().first;
      n -= init[i];
      for(int j = i + 1; j < m; j++)
        sol[ptr][j] = v.back().second;
      v.back().first = 0;

      for(int j = ptr; j < tours; j++) {
        v[i + (j - ptr)].first -= init[i];
        sol[j][i] = v[i + (j - ptr)].second;
      }
      ptr++;
      std::sort(v.begin(), v.end());
    }
  }
  

  std::cout << sol.size() << '\n';
  for(int j = 0; j < m; j++)
    std::cout << init[j] << " ";
  std::cout << '\n';
  for(int i = 0; i < sol.size(); i++) {
    for(int j = 0; j < sol[i].size(); j++)
      std::cout << 1 + sol[i][j] << " ";
    std::cout << '\n';
  }

  return 0;
}