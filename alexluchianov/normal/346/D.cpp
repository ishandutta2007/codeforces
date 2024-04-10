#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const inf = 1000000000;
int dp[1 + nmax];

struct Node{
  int cost;
  int node;
  bool operator < (Node const &a) const{
    return a.cost < cost;
  }
};

vector<int> invg[1 + nmax];
int outedges[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    dp[i] = inf;
  priority_queue<Node> pq;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    invg[y].push_back(x);
    outedges[x]++;
  }

  int start, stop;
  cin >> start >> stop;
  dp[stop] = 0;
  pq.push({0, stop});
  while(0 < pq.size()){
    Node e = pq.top();
    pq.pop();
    if(e.cost != dp[e.node])
      continue;
    else {
      int node = e.node;
      for(int h = 0; h < invg[node].size(); h++) {
        int to = invg[node][h];
        outedges[to]--;
        if(outedges[to] == 0){
          if(dp[node] < dp[to]) {
            dp[to] = dp[node];
            pq.push({dp[to], to});
          }
        } else {
          if(dp[node] + 1 < dp[to]){
            dp[to] = dp[node] + 1;
            pq.push({dp[to], to});
          }
        }
      }
    }
  }
  if(dp[start] == inf)
    cout << -1;
  else
    cout << dp[start];
  return 0;
}