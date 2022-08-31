#include <iostream>
#include <vector>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int> > ans(n, std::vector<int>(n, 0));

  for(int i = 0; i < n; i++)
    std::cin >> ans[i][i];

  for(int i = 0; i < n; i++) {
    int lim = ans[i][i];
    lim--;
    int cx = i, cy = i;
    while(lim) {
      if(cy > 0 && ans[cx][cy-1] == 0)
        cy--;
      else
        cx++;
      lim--;
      ans[cx][cy] = ans[i][i];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++)
      std::cout << ans[i][j] << " ";
    std::cout << std::endl;
  }

  return 0;
}