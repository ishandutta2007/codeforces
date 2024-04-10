#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300;
char v[1 + nmax][1 + nmax];

class Bipartite{
  private:
    std::vector<std::vector<int>> g;
    std::vector<int> per[2];
    std::vector<int> seen;
    int n, m;
  public:
    Bipartite(int n_, int m_) {
      n = n_;
      m = m_;
      g.resize(1 + n);
      per[0].resize(1 + n);
      per[1].resize(1 + m);
      seen.resize(1 + n);
    }
    void add_edge(int x, int y) {
      g[x].push_back(y);
    }
    int pairup(int x) {
      if(seen[x] == 1)
        return 0;
      seen[x] = 1;
      for(int h = 0; h < g[x].size(); h++) {
        int to = g[x][h];
        if(per[1][to] == 0) {
          per[0][x] = to;
          per[1][to] = x;
          return 1;
        }
      }
      for(int h = 0; h < g[x].size(); h++) {
        int to = g[x][h];
        if(per[1][to] != x) {
          if(pairup(per[1][to]) == 1) {
            per[0][x] = to;
            per[1][to] = x;
            return 1;
          }
        }
      }
      return 0;
    }

    int maxmatch() {
      int result = 0, delta = 0;
      do {
        result += delta;
        delta = 0;
        for(int i = 1;i <= n; i++)
          seen[i] = 0;
        for(int i = 1;i <= n; i++)
          if(per[0][i] == 0 && pairup(i))
            delta++;
      } while(0 < delta);
      return result;
    }

    int independent() {
      return n + m - maxmatch();
    }
};

int id1[1 + nmax][1 + nmax], id2[1 + nmax][1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  int blocks = 0;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++) {
      std::cin >> v[i][j];
      blocks += (v[i][j] == '#');
    }
  
  int ptr1 = 0, ptr2 = 0;
  for(int i = 1; i < n; i++)
    for(int j = 1; j <= m; j++)
      if(v[i][j] == '#' && v[i + 1][j] == '#')
        id1[i][j] = ++ptr1;

  for(int i = 1;i <= n; i++)
    for(int j = 1;j < m; j++)
      if(v[i][j] == '#' && v[i][j + 1] == '#')
        id2[i][j] = ++ptr2;
  
  Bipartite graph(ptr1, ptr2);
  for(int i = 1; i < n; i++) {
    for(int j = 1;j <= m; j++) 
      if(0 < id1[i][j]) {
        if(0 < id2[i][j])
          graph.add_edge(id1[i][j], id2[i][j]);
        if(0 < id2[i + 1][j])
          graph.add_edge(id1[i][j], id2[i + 1][j]);
        if(0 < id2[i][j - 1])
          graph.add_edge(id1[i][j], id2[i][j - 1]);
        if(0 < id2[i + 1][j - 1])
          graph.add_edge(id1[i][j], id2[i + 1][j - 1]);
      }
  }

  std::cout << blocks - graph.independent();
  return 0;
}