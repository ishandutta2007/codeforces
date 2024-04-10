#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>

using ll = long long;

int const nmax = 300000;

int mult[5 + nmax];

int a[5 + nmax], b[5 + nmax];
int dp[5 + nmax], lastpos[5 + nmax], lastjump[5 + nmax];

int jump(int gala) {
  if(mult[gala] != gala) 
    mult[gala] = jump(mult[gala]);
  return mult[gala];
}

void unite(int gala, int galb){
  gala = jump(gala);
  galb = jump(galb);
  if(galb < gala)
    std::swap(gala, galb);
  mult[galb] = gala;
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> a[i];
  for(int i = 1; i <= n; i++)
    std::cin >> b[i];
  for(int i = 1;i <= n; i++)
    mult[i] = i;
  
  std::queue<int> q;
  for(int i = 0;i <= n; i++)
    dp[i] = -1;
  q.push(n);
  dp[n] = 0;
  
  while(0 < q.size()) {
    int node = q.front();
    q.pop();

    while(node - a[node] <= jump(node)) {
      int to = jump(node);
      if(dp[to + b[to]] == -1) {
        dp[to + b[to]] = dp[node] + 1;
        lastpos[to + b[to]] = node;
        lastjump[to + b[to]] = to;
        q.push(to + b[to]);
      }
      if(0 < jump(node))
        unite(jump(node), jump(node) - 1);
      else
        break;
    }
  }

  if(dp[0] == -1) 
    std::cout << -1 << '\n';
  else {
    std::vector<int> sol;
    int start = 0;
    while(0 < dp[start]) {
      sol.push_back(lastjump[start]);
      start = lastpos[start];
    }
    std::reverse(sol.begin(), sol.end());
    std::cout << sol.size() << '\n';
    for(int i = 0; i < sol.size(); i++)
      std::cout << sol[i] << " ";
    std::cout << '\n';
  }
  return 0;
}