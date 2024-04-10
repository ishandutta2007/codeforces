#include <iostream>
#include <queue>
#include <vector>

#define int long long
#define INF 2000000000000000000

signed main() {
  int n, m, t;
  std::cin >> n >> m >> t;

  int a[n][m];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      char x;
      std::cin >> x;
      a[i][j] = (x == '1');
    }

  std::queue<std::pair<int, int> > q;
  std::vector<std::vector<int> > d = std::vector<std::vector<int> >(n, std::vector<int>(m, INF));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(i && a[i-1][j] == a[i][j]) { q.push({i, j}); d[i][j] = 1; continue; }
      if(i < n-1 && a[i+1][j] == a[i][j]) { q.push({i, j}); d[i][j] = 1; continue; }
      if(j && a[i][j-1] == a[i][j]) { q.push({i, j}); d[i][j] = 1; continue; }
      if(j < m-1 && a[i][j+1] == a[i][j]) { q.push({i, j}); d[i][j] = 1; continue; }
    }
  }

  while(!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();

    if(i && d[i-1][j] == INF) { q.push({i-1, j}); d[i-1][j] = d[i][j]+1; }
    if(j && d[i][j-1] == INF) { q.push({i, j-1}); d[i][j-1] = d[i][j]+1; }
    if(i < n-1 && d[i+1][j] == INF) { q.push({i+1, j}); d[i+1][j] = d[i][j]+1; }
    if(j < m-1 && d[i][j+1] == INF) { q.push({i, j+1}); d[i][j+1] = d[i][j]+1; }
  }

  //for(int i = 0; i < n; i++) {
  //  for(int j = 0; j < n; j++) {
  //    if(d[i][j] == INF)
  //      std::cout << -1;
  //    else 
  //      std::cout << d[i][j];
  //    std::cout << " ";
  //  }
  //  std::cout << std::endl;
  //}

  while(t--) {
    int i, j, p;
    std::cin >> i >> j >> p;
    i--; j--;
    
    if(d[i][j] > p) {
      std::cout << a[i][j];
    }
    else {
      std::cout << (a[i][j]^((p-d[i][j]+1)%2));
    }
    std::cout << std::endl;
  }
}