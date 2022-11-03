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
  Int q;
  cin>>q;
  while(q--){
    Int a;
    cin>>a;
    Int k=0;
    while((1<<k)<=a) k++;    
    Int res=1;
    if((1<<k)-1==a){
      for(Int i=2;i*i<=a;i++){
        if(a%i) continue;
        chmax(res,i);
        chmax(res,a/i);
      }
    }else{
      res=(1<<k)-1;
    }    
    cout<<res<<"\n";
  }
  cout<<flush;
  return 0;
}