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
  Int b,k;
  cin>>b>>k;
  Int res=0;
  for(Int i=0;i<k;i++){
    Int a;
    cin>>a;
    res=res*b+a;
    res%=2;
  }
  res%=2;
  cout<<(res?"odd":"even")<<endl;
  return 0;
}