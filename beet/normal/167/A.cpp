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


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed main(){
  int n;
  double a,d;
  cin>>n>>a>>d;
  double prv=0;
  for(int i=0;i<n;i++){
    double t,v;
    cin>>t>>v;
    double res=t;
    double b=v/a;
    if(a*b*b/2>=d){
      // a * x * x / 2 == d
      res+=sqrt(d*2/a); 
    }else{
      res+=b;      
      res+=(d-a*b*b/2)/v;
    }
    
    chmax(res,prv);
    cout<<res<<"\n";
    prv=res;
  }
  cout<<flush;
  return 0;
}