#include <iostream>
#include <vector>

using namespace std;
int const nmax = 100;
struct Edge{
  int to;
  char c;
};
vector<Edge> g[5 + nmax];
char dp[3][5 + nmax][5 + nmax][30];
char explore(int start,int nodea ,int nodeb , char last){
  if(dp[start][nodea][nodeb][last - 'a'] != 0){
    return dp[start][nodea][nodeb][last - 'a'];
  } else{
    if(start == 1){
      bool ok = 0;
      for(int i = 0 ; i < g[nodea].size() ;i++){
        Edge &e = g[nodea][i];
        if(last <= e.c){
          if(explore(2 , e.to , nodeb , e.c) == 'A'){
            ok = 1;
          }
        }
      }
      if(ok == 1)
        dp[start][nodea][nodeb][last - 'a'] = 'A';
      else
        dp[start][nodea][nodeb][last - 'a'] = 'B';
    } else{
      bool ok = 0;
      for(int i = 0 ; i < g[nodeb].size() ;i++){
        Edge &e = g[nodeb][i];
        if(last <= e.c){
          if(explore(1 , nodea , e.to , e.c) == 'B'){
            ok = 1;
          }
        }
      }
      if(ok == 1)
        dp[start][nodea][nodeb][last - 'a'] = 'B';
      else
        dp[start][nodea][nodeb][last - 'a'] = 'A';
    }
  }
  return dp[start][nodea][nodeb][last - 'a'];
}
int main()
{
  int n , m;
  cin>>n>>m;
  for(int i = 1 ; i <= m ;i++){
    int a , b;
    char c;
    cin>>a>>b>>c;
    g[a].push_back({b , c});
  }
  for(int i = 1 ; i <= n ;i++){
    for(int j = 1 ; j <= n ;j++){
      cout<<explore(1 , i , j , 'a');
    }
    cout<<'\n';
  }
  return 0;
}