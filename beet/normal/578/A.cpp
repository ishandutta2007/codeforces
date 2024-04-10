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


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed main(){
  Int a,b;
  cin>>a>>b;
  if(a<b) drop(-1);

  using D = double;
  if(a==b) drop(D(a));

  D s=a+b,t=a-b;
  D ans=s/2.0;

  Int p=(a+b)/(2*b);
  chmin(ans,s/(2*p));

  Int q=(a-b)/(2*b);
  chmin(ans,t/(2*q));

  cout<<ans<<endl;
  return 0;
}