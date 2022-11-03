#include<bits/stdc++.h>
using namespace std;
using Int = signed;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  vector<Int> b(m,0);
  for(Int i=0;i<n;i++) b[--a[i]]++;

  if(m==1){
    cout<<n/3<<endl;
    return 0;
  }

  const Int INF = 1e8;
  const int L = 6;
  using A = array<array<Int, L>, L>;
  A base;
  for(Int i=0;i<L;i++)
    for(Int j=0;j<L;j++) base[i][j]=-INF;
  
  A dp=base;
  for(Int x=b[0]%3;x<L;x+=3){
    for(Int y=b[1]%3;y<L;y+=3){
      if(x>b[0]||y>b[1]) continue;
      dp[x][y]=((b[0]-x)+(b[1]-y))/3;
    }
  }

  for(Int t=2;t<m;t++){
    A nx=base;
    for(Int i=0;i<L;i++){
      for(Int j=0;j<L;j++){
        if(dp[i][j]<0) continue;
        for(Int k=0;k<3;k++){
          if(i<k||j<k||b[t]<k) continue;
          Int z=b[t]-k;
          for(Int x=z%3;x<L;x+=3){
            if(x<=z) chmax(nx[j-k][x],dp[i][j]+k+(z-x)/3);
          }
        }
      }
    }
    dp=nx;
  }
  
  Int ans=0;
  for(Int i=0;i<L;i++)
    for(Int j=0;j<L;j++)
      chmax(ans,dp[i][j]);
  cout<<ans<<endl;
  return 0;
}