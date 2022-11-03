#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T>
void chmin(T &a,T b){if(a>b) a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b) a=b;}


signed main(){
  //cin.tie(0);
  //ios::sync_with_stdio(0);
  Int n;
  //cin>>n;
  scanf("%lld",&n);
  vector<string> s(n);
  char buf[100];
  for(Int i=0;i<n;i++){
    //cin>>s[i];
    scanf("%s",buf);
    s[i]=string(buf);
  }
  vector< vector<Int> > dp(26,vector<Int>(26,-1));
  for(Int i=0;i<n;i++){
    Int x=s[i].size();
    Int a=s[i].front()-'a';
    Int b=s[i].back()-'a';
    for(Int j=0;j<26;j++){
      if(dp[j][a]<0) continue;
      chmax(dp[j][b],dp[j][a]+x);
    }
    chmax(dp[a][b],x);
  }
  Int ans=0;
  for(Int i=0;i<26;i++) chmax(ans,dp[i][i]);
  //cout<<ans<<endl;
  printf("%lld\n",ans);
  return 0;
}