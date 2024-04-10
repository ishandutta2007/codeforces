#include <iostream>
#include <vector>

using namespace std;

int const nmax = 100000;
int const modulo = 1000000007;

vector<int> g[5 + nmax];
int dp[5 + nmax][2];
int color[5 + nmax];
int prefix[5 + nmax];
int suffix[5 + nmax];

int n;

void computedp(int node , int parent){

  for(int h = 0 ; h < g[node].size() ; h++){
    int to = g[node][h];
    if(to != parent){
      computedp(to , node);
    }
  }
  prefix[0] = 1;

  for(int i = 0 ; i < g[node].size() ; i++){
    int to = g[node][i];
    if(to != parent){
      if(i == 0)
        prefix[i] = (dp[to][0] + dp[to][1]) % modulo;
      else
        prefix[i] = 1LL * prefix[i - 1] * ((dp[to][0] + dp[to][1]) % modulo) % modulo;
    } else if(0 < i)
      prefix[i] = prefix[i - 1];
  }
  suffix[g[node].size() - 1] = 1;

  for(int i = g[node].size() - 1 ;0 <= i ; i--){
    int to = g[node][i];
    if(to != parent){
      if(i == g[node].size() - 1)
        suffix[i] = (dp[to][0] + dp[to][1]) % modulo;
      else
        suffix[i] = 1LL * suffix[i + 1] * ((dp[to][0] + dp[to][1]) % modulo) % modulo;
    } else if(i < g[node].size() - 1)
      suffix[i] = suffix[i + 1];
  }
  if(color[node] == 1)
    dp[node][1] = suffix[0];
  else{
    dp[node][0] = suffix[0];
    for(int i = 0 ; i < g[node].size() ; i++){
      int to = g[node][i];
      if(to != parent) {
        if(i == 0 && g[node].size() == 1)
          dp[node][1] += 1LL * dp[to][1];
        else if(0 == i)
          dp[node][1] += 1LL * suffix[i + 1] * dp[to][1] % modulo;
        else if(i == g[node].size() - 1)
          dp[node][1] += 1LL * prefix[i - 1] * dp[to][1] % modulo;
        else
          dp[node][1] += 1LL * prefix[i - 1] * suffix[i + 1] % modulo * dp[to][1] % modulo;
      }
      if(modulo <= dp[node][1])
        dp[node][1] -= modulo;
    }
  }
  //cout << node << " " << dp[node][0] << " " << dp[node][1] << '\n';

}

int main()
{
  cin >> n;
  for(int i = 1 ; i < n ; i++){
    int x;
    cin >> x;
    g[x].push_back(i);
    g[i].push_back(x);
  }
  for(int i = 0 ; i < n ; i++)
    cin >> color[i];
  computedp(0 , -1);
  cout << dp[0][1];
  return 0;
}