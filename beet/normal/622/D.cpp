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
  if(n==1){
    cout<<1<<" "<<1<<endl;
    return 0;
  }
  if(n&1){
    for(Int i=1;i<=n-2;i+=2) cout<<i<<" ";
    cout<<n;
    for(Int i=n-2;i>=1;i-=2) cout<<" "<<i;
    cout<<" "<<n;
    for(Int i=2;i<=n-1;i+=2) cout<<" "<<i;
    for(Int i=n-1;i>=2;i-=2) cout<<" "<<i;
    cout<<endl;
  }else{
    for(Int i=1;i<=n-1;i+=2) cout<<i<<" ";
    for(Int i=n-1;i>=1;i-=2) cout<<i<<" ";
    cout<<n;
    for(Int i=2;i<=n-2;i+=2) cout<<" "<<i;
    cout<<" "<<n;
    for(Int i=n-2;i>=2;i-=2) cout<<" "<<i;
    cout<<endl;
  }
  return 0;
}