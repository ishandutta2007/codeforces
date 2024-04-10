#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;

int mex(std::vector<int> v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  for(int i = 0; i < v.size(); i++)
    if(i != v[i])
      return i;
  return v.size();
}

void print(std::vector<int> v) {
  std::cout << "Vector ";
  std::cout << v.size() << '\n';
  for(int i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
  std::cout << '\n';
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  std::vector<int> sol;
  while(true) {
    int val = mex(v);
    if(val == n) {
      for(int i = 0; i < n; i++)
        if(v[i] != i) {
          v[i] = val;
          sol.push_back(i);
          break;
        }
    }
    val = mex(v);
    if(val == n)
      break;
    sol.push_back(val);
    v[val] = val;
  }
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] + 1 << " ";
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}