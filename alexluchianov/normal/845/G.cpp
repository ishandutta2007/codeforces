#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
vector<pair<int,int>> g[1 + nmax];
int up[1 + nmax], seen[1 + nmax];

vector<int> v;

void dfs(int node){
  seen[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h].first;
    if(seen[to] == 0) {
      up[to] = up[node] ^ g[node][h].second;
      dfs(to);
    } else
      v.push_back(up[node] ^ up[to] ^ g[node][h].second);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  dfs(1);
  int result = up[n];

  for(int bit = (1 << 30); 0 < bit; bit /= 2){
    int val = 0;
    for(int i = 0; i < v.size(); i++)
      if(0 < (v[i] & bit))
        val = v[i];
    if(0 < (result & bit))
      result ^= val;
    for(int i = 0; i < v.size(); i++)
      if(0 < (v[i] & bit))
        v[i] ^= val;
  }
  cout << result;
  return 0;
}