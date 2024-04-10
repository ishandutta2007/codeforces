#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 150;
int const inf = 1000000300;

struct Matrix{
  int mat[nmax][nmax];
  Matrix(){
    for(int i = 0; i < nmax; i++)
      for(int j = 0; j < nmax; j++)
        mat[i][j] = 0;
  }
  Matrix operator * (Matrix const oth) {
    std::bitset<nmax> lines[nmax], columns[nmax];
    for(int i = 0; i < nmax; i++)
      for(int j = 0; j < nmax; j++)
        lines[i][j] = mat[i][j];
    for(int i = 0; i < nmax; i++)
      for(int j = 0; j < nmax; j++)
        columns[j][i] = oth.mat[i][j];
    Matrix result;
    for(int i = 0; i < nmax; i++)
      for(int j = 0; j < nmax; j++)
        result.mat[i][j] = (0 < (lines[i] & columns[j]).count());
    return result;
  }
};

struct Edge{
  int x;
  int y;
  int time;
  bool operator < (Edge const a) {
    return time < a.time;
  }
};

int const sigma = 32;
Matrix powp[1 + sigma];

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Edge> edges;
  for(int i = 0; i < m; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    x--;
    y--;
    edges.push_back({x, y, cost});
  }
  edges.push_back({0, n - 1, inf});
  edges.push_back({n - 1, n - 1, 0});

  std::sort(edges.begin(), edges.end());
  Matrix base, step;
  base.mat[0][0] = 1;
  int last = edges[0].time;
  
  for(int i = 0; i + 1 < edges.size(); i++) {
    int steps = edges[i + 1].time - edges[i].time;
    step.mat[edges[i].x][edges[i].y] = 1;

    powp[0] = step;
    int lim = 0;
    for(int j = 1; (1 << j) <= steps; j++) {
      ++lim;
      powp[j] = powp[j - 1] * powp[j - 1];
    }

    int x = 0;
    for(int jump = lim; 0 <= jump; jump--) {
      if(x + (1 << jump) <= steps && (base * powp[jump]).mat[0][n - 1] == 0) {
        x += (1 << jump);
        base = base * powp[jump];
      }
    }
    
    if(x < steps) {
      std::cout << last + x + 1 << '\n';
      return 0;
    } else {
      last = edges[i + 1].time;
    }
  }

  std::cout << "Impossible\n";
  return 0;
}