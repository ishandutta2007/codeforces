#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 400;
int const modulo = 998244353;

int d[1 + nmax][1 + nmax];
std::vector<int> g[1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int a, b;
    std::cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i = 1;i <= n; i++) {
    std::queue<int> q;
    q.push(i);
    for(int j = 1;j <= n; j++)
      d[i][j] = -1;
    d[i][i] = 0;
    while(0 < q.size()) {
      int node = q.front();
      q.pop();
      for(int h = 0; h < g[node].size(); h++) {
        int to = g[node][h];
        if(d[i][to] == -1) {
          d[i][to] = d[i][node] + 1;
          q.push(to);
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1;j <= n; j++) {
      int target = d[i][j], on_chain = 0, result = 1;
      for(int to = 1; to <= n; to++) 
        if(d[i][to] + d[j][to] == target)
          on_chain++;
        else {
          int p = 0;
          for(int h = 0; h < g[to].size(); h++) {
            int oth = g[to][h];
            if(d[i][oth] + 1 == d[i][to] && d[j][oth] + 1 == d[j][to])
              p++;
          }
          result = 1LL * result * p % modulo;
        }
      
      if(on_chain != target + 1)
        result = 0;
      std::cout << result << " ";
    }
    std::cout << '\n';
  }
  return 0;
}