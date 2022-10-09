#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 200000;
int const lgmax = 20;
vector<int> g[1 + nmax];
int level[1 + nmax], euler[1 + nmax], eulerp = 0;
int far[1 + lgmax][1 + nmax];

void dfs(int node, int parent){
  level[node] = level[parent] + 1;
  euler[node] = ++eulerp;
  far[0][node] = parent;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
}

void computefar(int n){
  for(int h = 1;h < lgmax; h++)
    for(int i = 1;i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
}

int getlca(int x, int y){
  if(level[x] < level[y])
    swap(x, y);
  for(int h = lgmax - 1;0 <= h; h--)
    if(level[y] + (1 << h) <= level[x])
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax - 1;0 <= h; h--)
    if(far[h][x] != far[h][y]){
      x = far[h][x];
      y = far[h][y];
    }
  return far[0][x];
}

bool compare(int x, int y){
  return euler[x] < euler[y];
}

vector<int> realg[1 + nmax];
int barbar[1 + nmax];
int dp[1 + nmax][2];

void solvegraph(int node){
  dp[node][0] = dp[node][1] = 0;
  int result = 0;
  for(int h = 0; h < realg[node].size(); h++){
    int to = realg[node][h];
    solvegraph(to);
    dp[node][1] = min(dp[node][1] + dp[to][0], dp[node][0] + dp[to][1]);
    dp[node][0] = dp[node][0] + dp[to][0];
    if(nmax < dp[node][0])
      dp[node][0] = nmax;
    if(nmax < dp[node][1])
      dp[node][1] = nmax;

    result += min(dp[to][0], dp[to][1]);
  }

  if(barbar[node] == 0)
    dp[node][0] = min(dp[node][0], result + 1);
  else {
    dp[node][1] = dp[node][0];
    dp[node][0] = nmax;
  }

}

int solve(int n){
  int m;
  cin >> m;
  vector<int> special;
  for(int i = 1;i <= m; i++) {
    int a;
    cin >> a;
    special.push_back(a);
  }
  sort(special.begin(), special.end(), compare);

  vector<int> special2;
  for(int i = 0; i < special.size(); i++) {
    special2.push_back(special[i]);
    if(0 < far[0][special[i]])
      special2.push_back(far[0][special[i]]);
  }

  for(int i = 1; i < special.size(); i++)
    special2.push_back(getlca(special[i - 1], special[i]));

  sort(special2.begin(), special2.end(), compare);
  special2.erase(unique(special2.begin(), special2.end()), special2.end());
  swap(special, special2);
  stack<int> st;
  st.push(special[0]);

  for(int i = 0; i < special.size(); i++) {
    realg[special[i]].clear();
    barbar[special[i]] = 0;
  }

  for(int i = 0; i < special2.size(); i++)
    barbar[special2[i]] = 1;

  for(int i = 1; i < special.size(); i++){
    int node = special[i];

    while(0 < st.size() && getlca(st.top(), node) != st.top())
      st.pop();
    realg[st.top()].push_back(node);
    st.push(node);
  }
  solvegraph(special[0]);

  int result = min(dp[special[0]][0], dp[special[0]][1]);
  if(nmax <= result)
    return -1;
  else
    return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  computefar(n);
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    cout << solve(n) << '\n';
  return 0;
}