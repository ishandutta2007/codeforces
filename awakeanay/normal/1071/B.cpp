#include <iostream>
#include <set>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;

  std::string s[n];
  for(int i = 0; i < n; i++)
    std::cin >> s[i];

  std::vector<std::vector<int> > min(n, std::vector<int>(n, 2*n+1));
  min[0][0] = 0;

  int preA = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(min[i][j] <= k) preA = std::max(preA, i+j);
      if(i+1 < n) {
        min[i+1][j] = std::min(min[i+1][j], min[i][j] + (s[i][j] != 'a'));
      }

      if(j+1 < n) {
        min[i][j+1] = std::min(min[i][j+1], min[i][j] + (s[i][j] != 'a'));
      }
    }
  }

  if(min[n-1][n-1] < k || (s[n-1][n-1] == 'a' && min[n-1][n-1] <= k)) {
    std::cout << std::string(2*n-1, 'a') << std::endl;
    return 0;
  }

  std::string ans(preA, 'a');

  std::set<std::pair<int, int> > cur;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(i+j == preA && min[i][j] <= k && s[i][j] != 'a')
        cur.insert({i, j});

  while(ans.length() < 2*n-1) {
    char nextChar = 'z' + 1;
    for(auto it = cur.begin(); it != cur.end(); it++) {
      nextChar = std::min(nextChar, s[(*it).first][(*it).second]);
    }
    ans += nextChar;
    std::set<std::pair<int, int> > nextS;
    for(auto it = cur.begin(); it != cur.end(); it++) {
      int i = (*it).first, j = (*it).second;
      if(nextChar == s[i][j]) {
        if(i+1 < n)
          nextS.insert({i+1, j});
        if(j+1 < n)
          nextS.insert({i, j+1});
      }
    }
    cur = nextS;
  }

  std::cout << ans << std::endl;

  return 0;
}