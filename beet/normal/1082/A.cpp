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
signed solve(){
  Int n,x,y,d;
  cin>>n>>x>>y>>d;
  x--;y--;
  if(abs(x-y)%d==0){
    cout<<abs(x-y)/d<<endl;
    return 0;
  }
  const Int INF = 1e15;
  Int res=INF;
  if(y%d==0){
    chmin(res,(x+d-1)/d+y/d);
  }
  if((n-(y+1))%d==0){
    chmin(res,(n-(x+1)+d-1)/d+(n-(y+1))/d);
  }
  if(res==INF) res=-1;
  cout<<res<<endl;
  return 0;
}

signed main(){
  Int t;
  cin>>t;
  while(t--) solve();
  return 0;
}