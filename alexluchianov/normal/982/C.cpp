#include <iostream>
#include <vector>

using namespace std;

int const nmax = 100000;

#define MAX(a , b) (((a) < (b)) ? (b) : (a))

vector <int> g[5 + nmax];

int dp[5 + nmax];
int n;
int result = 0;

int dfs(int node , int dad){
  for(int i = 0 ; i < g[node].size() ;i++)
    if(g[node][i] != dad)
      dfs(g[node][i] , node);
  for(int i = 0 ; i < g[node].size() ;i++)
    if(g[node][i] != dad)
      dp[node] += dp[g[node][i]];
  dp[node]++;
  if(dp[node] % 2 == 0)
    result++;
}

int main()
{
  cin >> n;
  if(n % 2 == 1){
    cout << "-1";
    return 0;
  }

  for(int i = 1 ; i < n ;i++){
    int x , y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1 , 0);
  cout << result - 1;
  return 0;
}