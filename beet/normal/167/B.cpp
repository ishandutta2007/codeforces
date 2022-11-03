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


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed main(){
  int n,l,k;
  cin>>n>>l>>k;
  vector<double> p(n);
  for(int i=0;i<n;i++) cin>>p[i],p[i]/=100;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  const int MAX = 222;
  vector<vector<double> > dp(MAX,vector<double>(MAX*2,0));
  dp[0][MAX+k]=1.0;
  for(int i=0;i<n;i++){
    vector<vector<double> > nx(MAX,vector<double>(MAX*2,0));
    for(int x=0;x<MAX;x++){
      for(int y=0;y<MAX*2;y++){
        if(x+1<MAX){
          if(~a[i]){
            nx[x+1][min(MAX*2-1,y+a[i])]+=dp[x][y]*p[i];
          }else if(y){
            nx[x+1][y-1]+=dp[x][y]*p[i];          
          }
        }
        nx[x][y]+=dp[x][y]*(1-p[i]);
      }
    }    
    swap(dp,nx);
  }
  double ans=0;
  for(int i=l;i<MAX;i++)
    for(int j=MAX;j<MAX*2;j++)
      ans+=dp[i][j];
  cout<<ans<<endl;
  return 0;
}