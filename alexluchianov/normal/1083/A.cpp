#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;

struct Edge{
  int to;
  int cost;
};

vector<Edge> g[5 + nmax];
int w[5 + nmax];
ll dp[5 + nmax];

ll result = 0;

void dfs(int node , int parent){
  dp[node] = w[node];
  ll smax = 0;
  result = MAX(result , w[node]);

  for(int h = 0 ; h < g[node].size() ; h++){
    Edge e = g[node][h];
    if(e.to != parent) {
      dfs(e.to , node);
      dp[e.to] -= e.cost;
      result = MAX(result , w[node] + smax + dp[e.to]);
      smax = MAX(smax , dp[e.to]);
      dp[node] = MAX(dp[node] , dp[e.to] + w[node]);
    }
  }

}

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> w[i];
  for(int i = 1 ; i < n ; i++){
    int x , y , cost;
    cin >> x >> y >> cost ;
    g[x].push_back({y , cost});
    g[y].push_back({x , cost});
  }
  dfs(1 , 0);
  cout << result;
  return 0;
}