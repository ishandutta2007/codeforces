#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 1000000;
int v[1 + nmax], seen[1 + nmax];

void solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++){
    std::cin >> v[i];
    v[i] = i - v[i];
  }
  int node = 1;
  std::vector<int> st, sol;
  
  for(int i = 1;i <= n; i++)
    seen[i] = 0;

  do {
    st.push_back(node);
    seen[node] = 1;
    node = v[node];
  } while(seen[node] != 1);
  
  while(0 < st.size() && node != st.back()) {
    sol.push_back(st.back());
    st.pop_back();
  }
  
  sol.push_back(node);

  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
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