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

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> vs(n),ms(n);
  for(Int i=0;i<n;i++) cin>>vs[i]>>ms[i];
  {
    Int sum=0;
    for(Int i=0;i<n;i++) sum+=vs[i];
    if(sum<0) for(Int i=0;i<n;i++) vs[i]*=-1;
  }
  const Int MAX = 62;
  Int ans=0;
  vector<Int> used(n,0);
  for(Int k=0;k<MAX;k++){
    Int sum=0;
    for(Int i=0;i<n;i++){
      if(used[i]) continue;
      if(ms[i]<(2LL<<k)){
        sum+=vs[i];
        used[i]=1;
      }
    }
    if(sum<=0) continue;
    ans|=1LL<<k;
    for(Int i=0;i<n;i++)
      if((ms[i]>>k)&1) vs[i]*=-1;
  }
  cout<<ans<<endl;
  return 0;
}