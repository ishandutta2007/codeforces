#include <iostream>
#include <queue>
#include <set>

#define int long long

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int ct = 0;
    std::set<std::pair<int, int> > st;

    int sum = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      st.insert({x, ct++});
      sum += x;
    }

    std::multiset<int> q;
    q.insert(sum);

    while(!q.empty()) {
      int u = *q.rbegin();
      q.erase(q.find(u));

      auto it = st.lower_bound({u, -1});

      if((*it).first == u) {
        st.erase(it);
        continue;
      }

      if((*st.rbegin()).first > u)
        break;

      q.insert(u/2);
      q.insert(u-u/2);
    }

    std::cout << (st.empty() ? "YES" : "NO") << std::endl;
  }

  return 0;
}