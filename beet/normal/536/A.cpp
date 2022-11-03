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
  Int a,b,n;
  cin>>a>>b>>n;
  for(Int i=0;i<n;i++){
    Int l,t,m;
    cin>>l>>t>>m;
    l--;
    Int s=a+l*b;
    if(s>t){
      cout<<-1<<"\n";
      continue;
    }
    Int L=l,R=1e12+100;
    while(L+1<R){
      Int M=(L+R)>>1;
      if(a+M*b>t){
        R=M;
        continue;
      }
      Int len=M-l+1;
      double S=(double)s*len+(double)b*len*(len-1)/2;
      if(S>t*m*2){
        R=M;
        continue;
      }
      Int sum=s*len+b*len*(len-1)/2;
      if(sum<=t*m) L=M;
      else R=M;
    }
    cout<<R<<"\n";
  }
  cout<<flush;
  return 0;
}