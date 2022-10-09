#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

struct Edge{
  int to;
  int cost;
};

int const nmax = 100000;

vector<Edge> g[5 + nmax];

void dfs(int node , int parent , int &nodeperf , ll &cost) {
  nodeperf = node;
  cost = 0;

  for(int h = 0 ;h < g[node].size() ; h++){
    Edge e = g[node][h];
    if(e.to != parent){
      int nodeperf2 = 0 ;
      ll cost2 = 0;

      dfs(e.to , node , nodeperf2 , cost2);
      if(cost < e.cost + cost2){
        nodeperf = nodeperf2;
        cost = cost2 + e.cost;
      }

    }
  }
}


int main()
{
  int n;
  cin >> n;
  ll sum = 0;
  for(int i = 1 ; i < n ; i++){
    int x , y , cost;
    cin >> x >> y >> cost;
    g[x].push_back({y , cost});
    g[y].push_back({x , cost});
    sum += cost * 2;
  }

  int nodeperf = 0 ;
  ll cost = 0;
  dfs(1 , 0 , nodeperf , cost);

  cout << sum - cost;
  return 0;
}