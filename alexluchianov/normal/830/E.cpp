#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;
using ld = long double;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))


int const nmax = 100000;
std::vector<int> g[1 + nmax];
int seen[1 + nmax];
ld sol[1 + nmax];

void dfs(int node, std::vector<int> &aux) {
  seen[node] = 1;
  aux.push_back(node);
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(seen[to] == 0)
      dfs(to, aux);
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    g[i].clear();
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    sol[i] = seen[i] = 0;
  for(int i = 1;i <= n; i++) {
    if(seen[i] == 0) {
      std::vector<int> aux;
      dfs(i, aux);

      int total = 0, leafs = 0;
      for(int j = 0; j < aux.size(); j++) {
        total += g[aux[j]].size();
        leafs += (g[aux[j]].size() == 1);
      }

      total /= 2;
      if(aux.size() <= total) {
        for(int j = 0; j < aux.size(); j++)
          sol[aux[j]] = 1;
        std::cout << "YES\n";
        for(int j = 1; j <= n; j++)
          std::cout << sol[j] << " ";
        std::cout << '\n';
        return ;
      } else if(3 < leafs) {

        for(int j = 0; j < aux.size(); j++)
          if(g[aux[j]].size() == 1)
            sol[aux[j]] = 1;
          else
            sol[aux[j]] = 2;
        std::cout << "YES\n";
        for(int j = 1; j <= n; j++)
          std::cout << sol[j] << " ";
        std::cout << '\n';
        return ;
      } else if(3 == leafs) {
        int root = 0;
        for(int j = 0; j < aux.size(); j++)
          if(g[aux[j]].size() == 3)
            root = aux[j];
        int _count = 3;
        for(int j = 0; j < g[root].size(); j++)
          if(1 == g[g[root][j]].size()) {
            _count--;
          } else {
            int to = g[root][j];
          }

        if(_count == 3) {
          sol[root] = 3;
          for(int j = 0; j < g[root].size(); j++) {
            int to = g[root][j];
            sol[to] = 2;
            sol[g[to][0] + g[to][1] - root] = 1;
          }
          std::cout << "YES\n";
          for(int i = 1;i <= n; i++)
            std::cout << sol[i] << " ";
          std::cout << '\n';
          return ;
        } else if(_count == 2){
          _count = 0;
          sol[root] = 4; 
          for(int j = 0; j < g[root].size(); j++) {
            int to = g[root][j];

            if(g[to].size() == 1) {
              sol[to] = 2;
            } else {
              sol[to] = 3;
              int to2 = g[to][0] + g[to][1] - root;
              if(g[to2].size() == 2) {
                int to3 = g[to2][0] + g[to2][1] - to;
                sol[to2] = 2;
                sol[to3] = 1;
              } else
                _count++;
            }
          }

          if(_count == 0) {
            std::cout << "YES\n";
            for(int i = 1;i <= n; i++)
              std::cout << sol[i] << " ";
            std::cout << '\n';
            return ;
          } else if(_count == 1) {
            bool oneforall = true;

            for(int j = 0; j < aux.size(); j++)
              sol[aux[j]] = 0;
            _count = 0;
            sol[root] = 6; 
            for(int j = 0; j < g[root].size(); j++) {
              int to = g[root][j];

              if(g[to].size() == 1) {
                sol[to] = 3;
              } else {
                int to2 = g[to][0] + g[to][1] - root;
                if(g[to2].size() == 2) {
                  int to3 = g[to2][0] + g[to2][1] - to;
                  sol[to] = 5;
                  sol[to2] = 4;
                  sol[to3] = 3;
                  if(g[to3].size() == 2) {
                    int to4 = g[to3][0] + g[to3][1] - to2;
                    sol[to4] = 2;
                    if(g[to4].size() == 2) {
                      int to5 = g[to4][0] + g[to4][1] - to3;
                      sol[to5] = 1;
                    } else
                      oneforall = false;
                  } else
                    oneforall = false;
                } else {
                  sol[to] = 4;
                  sol[to2] = 2;
                }
              }
            }

            if(oneforall == true) {
              std::cout << "YES\n";
              for(int i = 1; i <= n; i++)
                std::cout << sol[i] << " ";
              std::cout << '\n';
              return ;

            } else
              for(int j = 0; j < aux.size(); j++)
                sol[aux[j]] = 0;

          } else
            for(int j = 0; j < aux.size(); j++)
              sol[aux[j]] = 0;
        }
      }
    }
  }
  std::cout << "NO\n";
}

int a[1 + nmax];
int frec[1 + nmax];

int const lim = 15;


void backt(int pos, int target) {
  if(pos == (target + 1)) {
    int result = 0;
    for(int i = 1; i <= target; i++)
      result += a[i] * a[i];
    for(int i = 1;i < target; i++)
      result -= a[i] * a[i + 1];
    if(a[1] == 6 && result < frec[a[1]]) {
      std::cout << "SOL: " << result << '\n';
      for(int j = 1; j <= target; j++)
        std::cout << a[j] << " ";
      std::cout << '\n';

    }
    frec[a[1]] = std::min(frec[a[1]], result);
  } else {
    for(a[pos] = 1; a[pos] <= lim; a[pos]++)
      backt(pos + 1, target);
  }
}

int expsol[1 + nmax];

int main() {
  /*
     std::ios::sync_with_stdio(0);
     std::cin.tie(0);
   */
  /*
  for(int i = 1;i <= lim; i++)
    frec[i] = 10000000;
  backt(1, 2);
  for(int i = 1;i <= lim; i++)
    expsol[i] += frec[i];
  for(int i = 1;i <= lim; i++)
    frec[i] = 10000000;
  backt(1, 3);
  for(int i = 1;i <= lim; i++)
    expsol[i] += frec[i];
  for(int i = 1;i <= lim; i++)
    frec[i] = 10000000;
  backt(1, 6);
  for(int i = 1;i <= lim; i++)
    expsol[i] += frec[i];
  for(int i = 1;i <= lim; i++)
    std::cout << expsol[i] - i * i * 2 << " ";
  std::cout << '\n';

  return 0;
  */

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}