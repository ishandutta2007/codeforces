#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const inf = 1000000000;

vector<int> g[1 + nmax];
int spec[1 + nmax];
int dp[1 + nmax];

void dfs(int node, int parent){
  if(spec[node] == 1)
    dp[node] = MAX(dp[node], 0);

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      dp[node] = MAX(dp[node], dp[to] + 1);
    }
  }
}

int n, k, d;
int result = 0;

void solve(int node, int parent, int acc){
  if(spec[node] == 1)
    acc = MAX(acc, 0);
  vector<int> pref(g[node].size()), suff(g[node].size());

  for(int i = 0; i < g[node].size(); i++)
    pref[i] = suff[i] = -inf;
  if(acc <= d && dp[node] <= d)
    result++;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      pref[h] = suff[h] = dp[to];
  }

  for(int h = 1; h < g[node].size(); h++)
    pref[h] = MAX(pref[h], pref[h - 1]);
  for(int h = g[node].size() - 2; 0 <= h ; h--)
    suff[h] = MAX(suff[h + 1], suff[h]);

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    int acc2 = acc + 1;
    if(0 < h)
      acc2 = MAX(acc2, pref[h - 1] + 2);
    if(h < g[node].size() - 1)
      acc2 = MAX(acc2, suff[h + 1] + 2);
    if(to != parent)
      solve(to, node, acc2);
  }
}

int main()
{
  cin >> n >> k >> d;
  for(int i = 1;i <= k; i++){
    int a;
    cin >> a;
    spec[a] = 1;
  }
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    dp[i] = -inf;

  dfs(1, 0);
  solve(1, 0, -inf);
  cout << result;
  return 0;
}