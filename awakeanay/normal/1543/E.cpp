#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define int long long

const int MAXN = 65538;

std::vector<int> Adj[MAXN];

int ans[3][3];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  ans[1][0] = 0;
  ans[1][1] = 0;

  ans[2][0] = 0;
  ans[2][1] = 1;
  ans[2][2] = 0;
  ans[2][3] = 1;

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int N = (1ll << n);

    for(int i = 0; i < N; i++)
      Adj[i].clear();

    int m = n*N;
    m /= 2;
    for(int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    std::vector<int> d0(N, N);
    std::vector<int> back(N, -1);
    std::queue<int> bfs;
    bfs.push(0);
    d0[0] = 0;

    int last = -1;

    while(!bfs.empty()) {
      int u = bfs.front();
      bfs.pop();
      if(d0[u] == n)
        last = u;

      for(int j : Adj[u]) {
        if(d0[j] == N) {
          d0[j] = d0[u] + 1;
          back[j] = u;
          bfs.push(j);
        }
      }
    }


    int dist[n];
    int i = n-1;
    while(i >= 0) {
      dist[i--] = last;
      last = back[last];
    }

    std::vector<std::vector<int> > d(n, std::vector<int>(N, N));

    for(int i = 0; i < n; i++) {
      d[i][dist[i]] = 0;
      bfs.push(dist[i]);
      while(!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();

        for(int j : Adj[u]) {
          if(d[i][j] == N) {
            d[i][j] = d[i][u] + 1;
            bfs.push(j);
          }
        }
      }
    }

    int p_used[N];
    int rev[N];

    for(int i = 0; i < N; i++) {
      int cur = 0;
      for(int j = 0; j < n; j++) {
        int prev = (j == 0) ? d0[i] : d[j-1][i];
        int next = d[j][i];
        if(prev < next)
          cur += (1ll << j);
      }
      rev[i] = cur;
      p_used[cur] = i;
    }

    for(int i = 0; i < N; i++)
      std::cout << p_used[i] << " ";
    std::cout << std::endl;
    
    if(n != 1 && n != 2 && n != 4 && n != 8 && n != 16)
      std::cout << -1 << std::endl;
    else {
      std::vector<int> col(N, -1);
      std::queue<int> bfs;
      col[0] = 0;
      bfs.push(0);

      while(!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();

        int a = rev[u];
        for(int j : Adj[u]) {
          if(col[j] != -1)
            continue;

          int b = rev[j]^a;
          int id = -1;
          while(b > 0) {
            id++;
            b >>= 1;
          }

          col[j] = col[u]^id;
          bfs.push(j);
        }
      }

      for(int i = 0; i < N; i++)
        std::cout << col[i] << " ";
      std::cout << std::endl;
    }
  }

  return 0;
}