#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int const inf = 1000000001;

ll dp[2][1 + nmax][1 + nmax];
int sz[1 + nmax];
int discount[1 + nmax], normal[1 + nmax];
vector<int> g[1 + nmax];

void dfs(int node){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to);
  }

  for(int i = 1;i <= nmax; i++)
    dp[0][node][i] = dp[1][node][i] = inf;

  dp[0][node][1] = normal[node];
  dp[1][node][1] = normal[node] - discount[node];

  sz[node] = 1;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    for(int j = sz[node]; 1 <= j; j--)
      for(int h = 0; h <= sz[to]; h++)
        dp[1][node][j + h] = MIN(dp[1][node][j + h], dp[1][node][j] + MIN(dp[0][to][h], dp[1][to][h]) );

    for(int j = sz[node]; 0 <= j; j--)
      for(int h = 0; h <= sz[to]; h++)
        dp[0][node][j + h] = MIN(dp[0][node][j + h], dp[0][node][j] + dp[0][to][h]);

    sz[node] += sz[to];
  }
}

int main()
{
  int n, b;
  cin >> n >> b;
  for(int i = 1;i <= n; i++) {
    cin >> normal[i] >> discount[i];
    if(1 < i){
      int x;
      cin >> x;
      g[x].push_back(i);
    }
  }
  dfs(1);
  int ptr = 0;
  while(ptr < n && MIN(dp[1][1][1 + ptr], dp[0][1][1 + ptr]) <= b)
    ptr++;
  cout << ptr;
  return 0;
}