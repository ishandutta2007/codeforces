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
  Int n,h;
  cin>>n>>h;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];

  auto check=
    [&](Int x)->Int{
      vector<Int> b(x);
      for(Int i=0;i<x;i++) b[i]=a[i];
      sort(b.rbegin(),b.rend());
      Int res=0;
      for(Int i=0;i<x;i+=2) res+=b[i];
      return res<=h;
    };
  
  Int l=0,r=n+1;
  while(l+1<r){
    Int m=(l+r)>>1;
    if(check(m)) l=m;
    else r=m;
  }
  cout<<l<<endl;
  return 0;
}