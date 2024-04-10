#include <iostream>
#include <vector>
#include <stack>

using ll = long long;
int const nmax = 100000;
int v[1 + nmax];

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::stack<std::pair<int,ll>> st;

  for(int i = 1;i <= n; i++) 
    std::cin >> v[i];
  for(int i = n; 1 <= i; i--)
    st.push({i, v[i]});
  
  int q;
  std::cin >> q;
  for(int i = 1;i <= q; i++) {
    int width, height;
    ll smax = 0;
    std::cin >> width >> height;
    while(0 < st.size() && st.top().first <= width) {
      smax = std::max(smax, st.top().second);
      st.pop();
    }
    st.push({1, smax + height});
    std::cout << smax << '\n';
  }
}