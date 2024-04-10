#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
using ll = long long;
ll dfs(ll t,ll n,ll x){
  assert(1<=x and x<=n);
  if(n==1) return 1;

  if(x<=n and x%2==(!t)) return (x+1)/2;

  if(t==0){
    if(n%2==0){
      return dfs(0,n/2,x/2)+n/2;
    }else{
      ll k=(n+1)/2;
      return dfs(1,k-1,x/2)+k;
    }
  }
  if(t==1){
    if(n%2==0){
      return dfs(1,n/2,(x+1)/2)+n/2;
    }else{
      ll k=(n-1)/2;
      return dfs(0,k+1,(x+1)/2)+k;
    }
  }
  abort();
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll n,q;
  cin>>n>>q;
  for(int i=0;i<q;i++){
    ll x;
    cin>>x;
    cout<<dfs(0,n,x)<<newl;
  }
  return 0;
}