#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int T;
  cin>>T;
  while(T--){
    Int n,m,k;
    string s;
    cin>>n>>m>>k>>s;

    vector<Int> cnt(26,0);
    for(char c:s) cnt[c-'A']++;

    const Int INF = 1e15;
    Int ans=INF;
    for(Int x=0;x<26;x++){
      vector<Int> dp(k+1,0);
      dp[0]=1;
      for(Int i=0;i<26;i++){
        if(x==i) continue;
        for(Int j=k-cnt[i];j>=0;j--) dp[j+cnt[i]]|=dp[j];
      }
      for(Int j=0;j<=k;j++){
        if(!dp[j]) continue;
        if(j+cnt[x]<n) continue;
        Int a=max(n-j,0LL);
        Int z=k-(j+cnt[x]);
        if(m-z>cnt[x]-a) continue;
        Int b=max(m-z,0LL);
        chmin(ans,a*b);        
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}