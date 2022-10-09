#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll const inf = 1000000000 ;

struct Envelope{
  int dr;
  int money;
  int jump;
  bool operator < (Envelope const &a) const{
    if(money != a.money)
      return money < a.money;
    else
      return jump < a.jump;
  }
};

vector<Envelope> g[5 + nmax];
Envelope best[5 + nmax];
ll dp[5 + nmax][5 + 200];

int main()
{
  int n , m , k;
  cin >> n >> m >> k;
  for(int i = 1 ; i <= k ; i++){
    int st, dr, cost, jump;
    cin >> st >> dr >> jump >> cost;
    g[st].push_back({dr ,cost , jump});
  }

  priority_queue<Envelope> pq;
  for(int i = 1 ; i <= n ;i++)
    best[i] = {i , 0 , i};

  for(int i = 1 ; i <= n ; i++){
    for(int h = 0; h < g[i].size() ; h++)
      pq.push(g[i][h]);
    while(0 < pq.size() && pq.top().dr < i)
      pq.pop();
    if(0 < pq.size())
      best[i] = pq.top();
  }
  for(int i = 2 ; i <= n + 1; i++)
    for(int j = 0 ; j <= m ; j++)
      dp[i][j] = 1LL * inf * nmax ;

  for(int i = 1 ; i <= n ; i++){
    for(int j = 0 ; j <= m ; j++){
      if(best[i].money == 0)
        dp[i + 1][j] = MIN(dp[i + 1][j], dp[i][j]);
      else {
        dp[best[i].jump + 1][j] = MIN(dp[best[i].jump + 1][j], dp[i][j] + best[i].money);
        dp[i + 1][j + 1] = MIN(dp[i + 1][j + 1] , dp[i][j]);
      }
    }
  }

  ll result = 1LL * nmax * nmax * nmax;
  for(int i = 0 ; i <= m ; i++)
    result = MIN(result , dp[n + 1][i]);
  cout << result;
  return 0;
}