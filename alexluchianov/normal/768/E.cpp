#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using ll = long long;

int const nmax = 60;
std::map<std::pair<int,std::vector<int>>, int> mp;

int mex(std::vector<int> v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  for(int i = 0; i < v.size(); i++)
    if(v[i] != i)
      return i;
  return v.size();
}

std::vector<int>  _add(int n, std::vector<int> v, int val) {
  v.push_back(val);
  std::sort(v.begin(), v.end());
  while(0 < v.size() && n < v.back())
    v.pop_back();
  return v;
}

int solve(int n, std::vector<int> v) {
  if(n == 0)
    return 0;
  if(mp.find({n, v}) == mp.end()) {
    std::vector<int> sol;
    int ptr = 0;
    for(int i = 1; i <= n; i++) {
      while(ptr < v.size() && v[ptr] < i)
        ptr++;
      if(ptr == v.size() || v[ptr] != i) {
        sol.push_back(solve(n - i, _add(n - i, v, i)));
      }
    }
    return mp[{n, v}] = mex(sol);
  } else
    return mp[{n, v}];
}

int sol[1 + nmax] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
int main() {
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;
  /*
  std::vector<int> empt;
  for(int i = 1;i <= 60; i++) {
    sol[i] = solve(i, empt);
  }
  for(int i = 1;i <= 60; i++)
    std::cout << sol[i] << ", ";
  */

  int result = 0;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    result ^= sol[val];
  }

  if(0 < result)
    std::cout << "NO";
  else
    std::cout << "YES";
  return 0;
}