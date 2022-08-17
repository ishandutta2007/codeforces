#include <iostream>
#include <vector>
#include <set>

#define int long long

const int MAXN = 200005;

std::vector<int> open[MAXN], close[MAXN];

std::set<std::pair<int, int> > st;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  int l[n], r[n];
  for(int i = 0; i < n; i++) {
    std::cin >> l[i] >> r[i];
    open[l[i]].push_back(i);
    close[r[i]].push_back(i);
  }

  std::vector<int> ans;

  for(int i = 0; i < MAXN; i++) {
    for(int j : open[i])
      st.insert({-r[j], j});

    while(st.size() > k) {
      ans.push_back((*st.begin()).second + 1);
      st.erase(st.begin());
    }

    for(int j : close[i])
      st.erase({-r[j], j});
  }

  std::cout << ans.size() << std::endl;
  for(int j : ans)
    std::cout << j << " ";
  std::cout << std::endl;

  return 0;
}