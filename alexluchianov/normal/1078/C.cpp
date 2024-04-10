#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) <  (b)) ? (a) : (b))
#define MAX(a , b) (((b) <  (a)) ? (b) : (a))

int const nmax = 300000;
int const modulo = 998244353;
vector<int> g[5 + nmax];
ll dp[5 + nmax][3];

///0 not connected
///1 connected but without pair
///2 connected with pair
ll pref[5 + nmax];
ll suff[5 + nmax];

void dfs(int node , int parent){
  for(int h = 0 ; h < g[node].size() ; h++){
    int to = g[node][h];
    if(to != parent){
      dfs(to , node);
    }
  }

  dp[node][0] = dp[node][1] = 1;

  int sumofall = 1;
  for(int h = 0 ; h < g[node].size() ; h++){
    int to = g[node][h];
    if(to != parent) {
      dp[node][0] = 1LL * dp[node][0] * (dp[to][0] + dp[to][2]) % modulo;
      dp[node][1] = 1LL * dp[node][1] * (dp[to][0] + 2 * dp[to][2]) % modulo;
      sumofall = 1LL * sumofall * (dp[to][0] + dp[to][2]) % modulo;

    }
  }
  dp[node][1] -= sumofall;
  if(dp[node][1] < 0)
    dp[node][1] += modulo;
  for(int h = 0 ; h < g[node].size() ; h++){
    int to = g[node][h];
    if(to != parent){
      pref[h] = (dp[to][0] + 2 * dp[to][2]) % modulo;
      suff[h] = (dp[to][0] + 2 * dp[to][2]) % modulo;
    } else
      pref[h] = suff[h] = 1;
  }

  for(int h = 1 ; h < g[node].size() ; h++)
    pref[h] = 1LL * pref[h - 1] * pref[h] % modulo;
  for(int h = g[node].size() - 2 ; 0 <= h ; h--)
    suff[h] = 1LL * suff[h + 1] * suff[h] % modulo;

  for(int h = 0 ;h < g[node].size() ; h++){
    int to = g[node][h];
    if(to != parent){
      if(h == 0 && g[node].size() == 1)
        dp[node][2] += (dp[to][0] + dp[to][1]) % modulo;
      else if(h == 0)
        dp[node][2] += (dp[to][0] + dp[to][1]) * suff[h + 1] % modulo;
      else if(h == g[node].size() - 1)
        dp[node][2] += (dp[to][0] + dp[to][1]) * pref[h - 1] % modulo;
      else
        dp[node][2] += (dp[to][0] + dp[to][1]) * pref[h - 1] % modulo * suff[h + 1] % modulo;

      if(modulo <= dp[node][2])
        dp[node][2] -= modulo;
    }
  }

}

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i < n ; i++){
    int x , y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1 , 0);
  cout << (dp[1][0] + dp[1][2]) % modulo;

  return 0;
}