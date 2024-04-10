#include <iostream>
#include <vector>

#define int long long

const int INF = 1000000009;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  int a[n*k];

  std::vector<int> poss[n];
  for(int i = 0; i < n*k; i++) {
    int x;
    std::cin >> x;
    x--;
    a[i] = x;
    poss[x].push_back(i+1);
  }

  std::pair<int, int> ans[n];

  std::vector<int> solved(n, 0);
  int done = 0;
  while(done < n) {
    std::vector<int> count(n, -1);
    for(int i = 0; i < n*k; i++) {
      if(solved[a[i]])
        continue;

      if(count[a[i]] != -1) {
        solved[a[i]] = 1;
        done++;
        ans[a[i]] = {count[a[i]], i};
        count.assign(n, -1);
        continue;
      }

      count[a[i]] = i;
    }
  }

  for(std::pair<int, int> j : ans)
    std::cout << j.first+1 << " " << j.second+1 << std::endl;

  return 0;
}