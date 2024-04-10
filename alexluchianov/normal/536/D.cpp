#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
int const nmax = 2000;
ll const inf = 1000000000000000000;
vector<pair<int,int> > g[1 + nmax];

vector<ll> distances(int start, int n){
  vector<ll> dist(1 + n);
  for(int i = 1;i <= n; i++)
    dist[i] = inf;
  dist[start] = 0;
  priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
  pq.push({0, start});

  while(0 < pq.size()){
    pair<ll,int> pqtop = pq.top();
    int node = pqtop.second;
    ll cost = pqtop.first;
    pq.pop();
    if(dist[node] == cost){
      for(int h = 0; h < g[node].size(); h++){
        int to = g[node][h].first, edge = g[node][h].second;
        if(dist[node] + edge < dist[to]){
          dist[to] = dist[node] + edge;
          pq.push({dist[to], to});
        }
      }
    }
  }
  return dist;
}

vector<int> normalize(vector<ll> v){
  int n = v.size() - 1;
  vector<ll> temp;
  map<ll,int> code;
  for(int i = 1;i <= n; i++)
    temp.push_back(v[i]);
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++)
    code[temp[i]] = 1 + i;

  vector<int> sol(n + 1);
  for(int i = 1;i <= n; i++)
    sol[i] = code[v[i]];
  return sol;
}

int cost[5 + nmax];
ll sum[5 + nmax][5 + nmax];
int cond[5 + nmax][5 + nmax], cond2[5 + nmax][5 + nmax];
ll dp[2][5 + nmax][5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  int start1, start2;
  cin >> start1 >> start2;
  for(int i = 1;i <= n; i++)
    cin >> cost[i];
  for(int i = 1;i <= m; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  vector<int> dist1 = normalize(distances(start1, n)), dist2 = normalize(distances(start2, n));
  for(int i = 1;i <= n + 1; i++)
    for(int j = 1; j <= n + 1; j++)
      cond2[i][j] = cond[i][j] = n + 1;

  for(int i = 1;i <= n; i++) {
    sum[dist1[i]][dist2[i]] += cost[i];
    cond[dist1[i]][dist2[i]] = dist1[i];
    cond2[dist1[i]][dist2[i]] = dist2[i];
  }

  for(int i = n; 1 <= i; i--)
    for(int j = n; 1 <= j; j--) {
      sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
      cond[i][j] =  min(cond[i][j] , min(cond[i][j + 1] , cond[i + 1][j]  ));
      cond2[i][j] = min(cond2[i][j], min(cond2[i][j + 1], cond2[i + 1][j] ));
    }

  for(int i = n; 1 <= i; i--)
    for(int j = n; 1 <= j; j--){
      if(n + 1 == cond[i][j])
        dp[0][i][j] = 0;
      else if(cond[i][j] == i)
        dp[0][i][j] = max(dp[0][i + 1][j], -dp[1][i + 1][j]) + sum[i][j] - sum[i + 1][j];
      else
        dp[0][i][j] = dp[0][i + 1][j];

      if(n + 1 == cond2[i][j])
        dp[1][i][j] = 0;
      else if(cond2[i][j] == j)
        dp[1][i][j] = max(-dp[0][i][j + 1], dp[1][i][j + 1]) + sum[i][j] - sum[i][j + 1];
      else
        dp[1][i][j] = dp[1][i][j + 1];
    }

  if(0 < dp[0][1][1])
    cout << "Break a heart";
  else if(0 == dp[0][1][1])
    cout << "Flowers";
  else
    cout << "Cry";

  return 0;
}