#include <iostream>
#include <vector>
#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, m;
  std::cin >> n >> m;

  std::string s[n];
  for(int i = 0; i < n; i++)
    std::cin >> s[i];

  long long ans = 0;
  std::vector<std::vector<int> > left, right, up, down;

  left = right = up = down = std::vector<std::vector<int> > (n, std::vector<int>(m, 0));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      left[i][j] = 1;
      if(j && s[i][j] == s[i][j-1]) left[i][j] += left[i][j-1];
    }

    for(int j = m-1; j >= 0; j--) {
      right[i][j] = 1;
      if(j < m-1 && s[i][j] == s[i][j+1]) right[i][j] += right[i][j+1];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      up[i][j] = std::min(std::min(left[i][j], right[i][j]), ((i && s[i-1][j] == s[i][j]) ? up[i-1][j] : 0)+1);
    }
  }

  for(int i = n-1; i >= 0; i--) {
    for(int j = 0; j < m; j++) {
      down[i][j] = std::min(std::min(left[i][j], right[i][j]), ((i+1 < n && s[i+1][j] == s[i][j]) ? down[i+1][j] : 0)+1);
      ans += std::min(down[i][j], up[i][j]);
    }
  }

  //for(int i = 0; i < n; i++) {
  //  for(int j = 0; j < m; j++) {
  //    std::cout << left[i][j] << right[i][j] << " ";
  //  }
  //  std::cout << std::endl;
  //}

  std::cout << ans << std::endl;

  return 0;
}