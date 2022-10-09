#include <iostream>
#include <bitset>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 10000;

ll const inf = 1000000000000000000;

struct Node{
  int era;
  int node;
  int val;
  bool operator < (Node const &a) const {
    return a.era < era;
  }
};

int dp[1 + nmax][1 + nmax / 10];
int d[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  priority_queue<Node> pq;
  for(int i = 1;i <= m; i++)
    cin >> d[i];
  sort(d + 1, d + m + 1);

  int green, red;
  cin >> green >> red;

  for(int i = 1; i <= m; i++)
    for(int j = 0; j <= green; j++)
      dp[i][j] = 2 * nmax;

  dp[1][0] = 1;
  pq.push({1, 1, 0});
  while(0 < pq.size()){
    int era = pq.top().era;
    int node = pq.top().node;
    int val = pq.top().val;
    pq.pop();

    if(dp[node][val] == era){
      if(node < m){
        int val2 = (val + d[node + 1] - d[node]);
        if(val2 < green){
          if(era < dp[node + 1][val2]) {
            dp[node + 1][val2] = era;
            pq.push({era, node + 1, val2});
          }
        } else if(val2 == green){
          if(era + 1 < dp[node + 1][0]) {
            dp[node + 1][0] = era + 1;
            pq.push({era + 1, node + 1, 0});
          }
        }
      }
      if(1 < node){
        int val2 = (val + d[node] - d[node - 1]);
        if(val2 < green){
          if(era < dp[node - 1][val2]) {
            dp[node - 1][val2] = era;
            pq.push({era, node - 1, val2});
          }
        } else if(val2 == green){
          if(era + 1 < dp[node - 1][0]) {
            dp[node - 1][0] = era + 1;
            pq.push({era + 1, node - 1, 0});
          }
        }
      }
    }
  }
  ll result = inf;
  for(int i = 0; i < green; i++){
    if(dp[m][i] < nmax * 2) {
      ll cost = 1LL * (dp[m][i] - 1) * green + 1LL * (dp[m][i] - 1 - (i == 0)) * red + i;
      result = min(result, cost);
    }
  }
  if(result == inf)
    cout << -1;
  else
    cout << result;
  return 0;
}