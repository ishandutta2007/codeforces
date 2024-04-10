#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int T;
  cin>>T;
  while(T--){
    Int n,m,t;
    cin>>n>>m>>t;
    vector<Int> p(n);
    for(Int i=0;i<n;i++) cin>>p[i];
    
    auto calc=
      [&](Int d){
        Int cnt=0,res=0,tmp=0;
        for(Int i=0;i<n;i++){
          if(cnt%m==0) res+=tmp,tmp=0;
          if(p[i]>d) continue;
          res+=p[i];
          tmp+=p[i];
          cnt++;    
        }
        return res;
      };
    
    Int l=0,r=t+1;
    while(l+1<r){
      Int d=(l+r)>>1;
      if(calc(d)<=t) l=d;
      else r=d;
    }

    auto check=
      [&](Int d){
        Int cnt=0,res=0,tmp=0;
        for(Int i=0;i<n;i++){
          if(p[i]>d) continue;
          if(cnt%m==0) res+=tmp,tmp=0;
          if(res+p[i]>t) break;
          res+=p[i];
          tmp+=p[i];
          cnt++;     
        }
        return cnt;
      };
    
    Int a=check(l);
    Int b=check(r);
    if(a>=b) cout<<a<<" "<<l<<endl;
    else cout<<b<<" "<<r<<endl;
  }
  
  return 0;
}