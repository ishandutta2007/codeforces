#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<int> g[1 + nmax];

void build(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  for(int h = 0; h < g[node].size(); h++)
    build(g[node][h], node);
}

pair<int,int> dp[1 + nmax];

void dfs(int node, int parent, int k){
  int smax1 = 0, smax2 = 0, result = 0;
  for(int h = 0;h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node, k);
    result += dp[to].first;
    if(smax1 < dp[to].second){
      smax2 = smax1;
      smax1 = dp[to].second;
    } else if(smax2 < dp[to].second){
      smax2 = dp[to].second;
    }
  }
  smax1++;
  if(k <= smax1 + smax2)
    dp[node] = {result + 1, 0};
  else
    dp[node] = {result, smax1};
}

int sol[1 + nmax];

int eval(int k){
  if(sol[k] == -1) {
    dfs(1, 0, k);
    sol[k] = dp[1].first;
  }
  return sol[k];
}

int binarysearch(int from, int to, int target){
  if(from < to){
    int mid = (from + to + 1) / 2;
    if(target <= eval(mid))
      return binarysearch(mid, to, target);
    else
      return binarysearch(from, mid - 1, target);
  } else
    return from;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    sol[i] = -1;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  build(1, 0);
  int ptr = 1;
  while(ptr <= n) {
    int val = eval(ptr);
    int pos = binarysearch(1, n, val);
    while(ptr <= pos)
      sol[ptr++] = val;
  }

  for(int i = 1;i <= n; i++)
    cout << sol[i] << '\n';
  return 0;
}