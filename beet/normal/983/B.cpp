#include<bits/stdc++.h>
using namespace std;
using Int = signed;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
Int dp[5050][5050];
Int dp2[5050][5050];

signed main(){
  Int n;
  scanf("%d",&n);
  vector<Int> a(n);
  for(Int i=0;i<n;i++) scanf("%d",&a[i]);
  memset(dp,0,sizeof(dp));
  for(Int i=0;i<n;i++) dp[i][i+1]=a[i];
  for(Int i=2;i<=n;i++)
    for(Int j=0;j+i<=n;j++)
      dp[j][j+i]=dp[j][j+i-1]^dp[j+1][j+i];
  
  memset(dp2,0,sizeof(dp2));
  for(Int i=1;i<=n;i++){
    for(Int j=0;j+i<=n;j++){
      dp2[j][j+i]=dp[j][j+i];
      chmax(dp2[j][j+i],dp2[j][j+i-1]);
      chmax(dp2[j][j+i],dp2[j+1][j+i]);
    }
  }
  
  Int q;  
  scanf("%d",&q);
  for(Int i=0;i<q;i++){
    Int l,r;
    scanf("%d %d",&l,&r);
    l--;
    printf("%d\n",dp2[l][r]);
  }
  return 0;
}