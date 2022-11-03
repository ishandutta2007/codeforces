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

Int dfs(Int a,Int b){
  if(a>b) swap(a,b);
  if(a==0) return 0;
  if(!dfs(b%a,a)) return 1;
  
  if(a&1) return ((b-a)%(a*2))>=a;

  Int k=b-a;
  if(a+1<=(b-a)/a) k=(b-a)%(a*(a+1));
  k/=a;
  if(k>=a) return 1;
  return k&1;
}

//INSERT ABOVE HERE
signed main(){
  Int t;
  cin>>t;
  for(Int i=0;i<t;i++){
    Int a,b;
    cin>>a>>b;
    cout<<(dfs(a,b)?"First":"Second")<<"\n";
  }
  cout<<flush;
  return 0;
}