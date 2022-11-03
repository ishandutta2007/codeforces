#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
const int MAX = 3030;
int dp[MAX][MAX];
signed main(){
  int n,m;
  cin>>n>>m;
  vector< vector<int> > G(n);
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }
  int s1,t1,l1;
  int s2,t2,l2;
  cin>>s1>>t1>>l1;
  cin>>s2>>t2>>l2;
  s1--;t1--;
  s2--;t2--;

  memset(dp,-1,sizeof(dp));
  for(int s=0;s<n;s++){
    queue<int> que;
    dp[s][s]=0;
    que.emplace(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      for(int u:G[v]){
        if(~dp[s][u]) continue;
        dp[s][u]=dp[s][v]+1;
        que.emplace(u);
      }
    }
  }

  if(dp[s1][t1]>l1) drop(-1);
  if(dp[s2][t2]>l2) drop(-1);

  int ans=0;
  chmax(ans,m-(dp[s1][t1]+dp[s2][t2]));
  for(int x=0;x<n;x++){
    for(int y=0;y<n;y++){
      {
        int d1=dp[s1][x]+dp[x][y]+dp[y][t1];
        int d2=dp[s2][x]+dp[x][y]+dp[y][t2];
        if(d1<=l1&&d2<=l2)
          chmax(ans,m-(dp[x][y]+dp[s1][x]+dp[y][t1]+dp[s2][x]+dp[y][t2]));
      }
      {
        int d1=dp[s1][x]+dp[x][y]+dp[y][t1];
        int d2=dp[s2][y]+dp[y][x]+dp[x][t2];
        if(d1<=l1&&d2<=l2)
          chmax(ans,m-(dp[x][y]+dp[s1][x]+dp[y][t1]+dp[s2][y]+dp[x][t2]));
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}