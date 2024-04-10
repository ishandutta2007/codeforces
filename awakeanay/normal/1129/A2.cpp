#include <iostream>

#define int long long

const int MAXN = 5005;

int take[MAXN];
int min[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < n; i++)
    min[i] = n;

  for(int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    a--; b--;

    take[a]++;
    min[a] = std::min(min[a], (a < b ? b-a : n-a+b));
    /*
    for(int j = a+1; j <= b; j++) {
      take[j][b]++;
      min[j][b] = std::min(min[j][b], n-1-b+a);
    }
    for(int j = b+1; j < n; j++) {
      take[j][a]++;
      min[j][a] = std::min(min[j][a], n-1-a+b);
    }
    */
  }

  for(int i = 0; i < n; i++) {
    int ans = 0;
    for(int j = 0; j < n; j++) {
      int cur = (i+j)%n;
//      std::cout << i << " " << j <<  " " << take[i][cur] << " " << min[i][cur] << std::endl;
      if(take[cur])
        ans = std::max(ans, (take[cur]-1)*(n) + j + min[cur]);
    }

    std::cout << ans << " ";
  }
  std::cout << std::endl;

  return 0;
}