#include <iostream>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  std::set<std::pair<int, int> > st;
  st.insert({a[0], 0});

  for(int i = 1; i < n; i++) {
    int u = a[i];
    auto it = st.lower_bound({u, -1});

    int out = -1;
    if(it != st.end()) {
      out = std::max(out, (*it).second);
    }

    if(it != st.begin()) {
      it--;
      out = std::max(out, (*it).second);
    }

    std::cout << a[out] << " ";
    st.insert({a[i], i});
  }

  return 0;
}