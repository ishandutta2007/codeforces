#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 300000;
std::vector<int> g[1 + nmax], invg[1 + nmax];
int seen[1 + nmax];

void dfs(int node, std::vector<int> &ord) {
  seen[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(seen[to] == 0)
      dfs(to, ord);
  }
  ord.push_back(node);
}

int sol[1 + nmax], pos[1 + nmax];
int dcount[1 + nmax], dsum[1 + nmax], depend[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    invg[y].push_back(x);
  }
  std::vector<int> ord;
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      dfs(i, ord);
  std::reverse(ord.begin(), ord.end());
  for(int i = 0; i < ord.size(); i++)
    pos[ord[i]] = i;
  
  int pcount = 0, psum = 0;
  
  for(int i = 1;i <= n; i++)
    dcount[i] = dsum[i] = depend[i] = 0;

  for(int i = 0; i < ord.size(); i++) {
    int node = ord[i];
    for(int h = 0; h < invg[node].size(); h++) {
      int to = invg[node][h];
      if(dcount[to] == 0) {
        dcount[to] = 1;
        dsum[to] = node;
        depend[node]++;
        pcount--;
        psum -= to;
      } else if(dcount[to] == 1) {
        depend[dsum[to]]--;
        dcount[to] = 2;
        dsum[to] += node;
      }
    }

    if(pcount == 1) {
      if(0 < depend[psum])
        sol[node] += 2;
      else
        sol[node]++;
    } else if(1 < pcount)
      sol[node] += 2;
    ++pcount;
    psum += node;
  }

  pcount = 0;
  psum = 0;
  
  for(int i = 1;i <= n; i++)
    dcount[i] = dsum[i] = depend[i] = 0;
  

  for(int i = ord.size() - 1; 0 <= i; i--) {
    int node = ord[i];
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(dcount[to] == 0) {
        dcount[to] = 1;
        dsum[to] = node;
        depend[node]++;
        pcount--;
        psum -= to;
      } else if(dcount[to] == 1) {
        depend[dsum[to]]--;
        dcount[to] = 2;
        dsum[to] += node;
      }
    }

    if(pcount == 1) {
      if(0 < depend[psum])
        sol[node] += 2;
      else
        sol[node]++;
    } else if(1 < pcount)
      sol[node] += 2;
    ++pcount;
    psum += node;
  }

  int result = 0;
  for(int i = 1; i <= n; i++)
    result += (sol[i] <= 1);
  std::cout << result << '\n';
  return 0;
}