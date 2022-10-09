#include <iostream>
#include <vector>

using namespace std;
int const nmax = 300000;
int const colormax = 26;
#define MAX(a , b) ((a < b) ? b : a)
vector < int > g[5 + nmax];
char color[5 + nmax];
int n , m;
int dp[1 + colormax][5 + nmax];
bool valid = 1;

void explore(int node ,int c){
  if(dp[c][node] == -1){
    valid = 0;
    return;
  } else if(dp[c][node] == -2){
    dp[c][node] = -1;
    int smax = 0 ;
    for(int i = 0 ; i < g[node].size() ;i++){
      explore(g[node][i] , c);
      if(valid == 0){
        dp[c][node] = 0;
        return;
      }
      if(smax < dp[c][g[node][i]])
        smax = dp[c][g[node][i]];
    }
    if(color[node] - 'a' == c)
      smax++;
    dp[c][node] = smax;
  } else
    return;
}
int main()
{
  cin>>n>>m;
  cin>>(color + 1);
  for(int j = 0 ; j < colormax ;j++){
    for(int i = 1 ; i <= n ;i++){
      dp[j][i] = -2;
    }
  }
  for(int i = 1  ; i <= m ;i++){
    int a , b;
    cin>>a>>b;
    g[a].push_back(b);
  }
  int smax = 0;
  for(int j = 0 ; j < colormax ;j++){
    for(int i = 1 ; i <= n ;i++){
      if(dp[j][i] == -2){
        explore(i , j);
        if(smax < dp[j][i]){
          smax = dp[j][i];
        }
        if(valid == 0){
          cout<<"-1";
          return 0;
        }
      }
    }
  }
  cout<<smax;
  return 0;
}