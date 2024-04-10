#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


Int isprime(Int x){
  if(x<=1) return 0;
  for(Int i=2;i*i<=x;i++)
    if(x%i==0) return 0;
  return 1;
}

//INSERT ABOVE HERE
signed main(){
  Int a,b,k;
  cin>>a>>b>>k;
  if(k>=5e4||!isprime(k)){
    Int ans=a<=k&&k<=b&&isprime(k);
    cout<<ans<<endl;
    return 0;
  }

  const Int THR = 500;
  const Int MAX = (2e9 / THR) + 10;
  vector<int> e(MAX),p;
  iota(e.begin(),e.end(),0);
  e[1]=k;  
  if(k<=THR){
    for(Int i=2;i<k;i++)
      if(isprime(i)) p.emplace_back(i);
  }else{
    for(Int i=2;i<k;i++){
      if(e[i]!=i) continue;
      for(Int j=i+i;j<MAX;j+=i) e[j]=i;
    }
  }
  
  auto calc=
    [&](Int x)->Int{
      Int res=0;
      if(k<=THR){
        function<void(Int, Int, Int)> dfs=
          [&](Int r,Int i,Int b){
            if(i==(Int)p.size()){
              if(b&1) res-=x/r;
              else res+=x/r;
              return;
            }
            if(r*p[i]<=x) dfs(r*p[i],i+1,b+1);
            dfs(r,i+1,b);
          };
        dfs(k,0,0);      
      }else{
        for(Int i=1;k*i<=x;i++) res+=e[i]>=k;
      }
      return res;
    };
  
  cout<<calc(b)-calc(a-1)<<endl;
  return 0;
}