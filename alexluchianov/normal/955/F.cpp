#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 300000;
vector<int> g[1 + nmax];

vector<pair<int,int>> dp[1 + nmax];
int n;

int extract(int node, int l){
  int pos = 0;
  for(int jump = 16; 0 < jump; jump /= 2)
    if(pos + jump < dp[node].size() && dp[node][pos + jump].second <= l)
      pos += jump;
  return dp[node][pos].first;
}

int eval(int node, int l){
  if(g[node].size() < l)
    return 1;
  else {
    vector<int> v;
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      v.push_back(extract(to, l));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    return v[l - 1] + 1;
  }
}

void dfs(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
  }

  if(g[node].size() == 0) {
    dp[node].push_back({1, 1});
    dp[node].push_back({0, n + 1});
  } else {
    int ptr = 1;
    while(ptr <= n){
      int sol = eval(node, ptr);
      dp[node].push_back({sol, ptr});
      for(int jump = (1 << 17); 0 < jump; jump /= 2)
        if(eval(node, ptr + jump) == sol)
          ptr += jump;
      ptr++;
    }
    dp[node].push_back({0, n + 1});
  }
}

int neweval(int node, int l){
  int result = extract(node, l);
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    result = max(result, extract(to, l));
  }
  return result;
}

void dfs2(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs2(to, node);
  }
  vector<pair<int,int>> newdp;
  int ptr = 1;
  while(ptr <= n){
    int sol = neweval(node, ptr);
    newdp.push_back({sol, ptr});
    for(int jump = (1 << 17); 0 < jump; jump /= 2)
      if(neweval(node, ptr + jump) == sol)
        ptr += jump;
    ptr++;
  }
  newdp.push_back({0, n + 1});
  dp[node] = newdp;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  dfs2(1, 0);
  ll result = 0;

  for(int i = 1;i <= n; i++)
    for(int h = 0; h < dp[i].size() - 1; h++)
      result += 1LL * dp[i][h].first * (dp[i][h + 1].second - dp[i][h].second);
  cout << result;
  return 0;
}