#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int w,l;
  cin>>w>>l;
  const Int INF = 1e17;
  vector<Int> a(w+1,0);
  a[0]=1;a[w]=INF;
  for(Int i=1;i<w;i++) cin>>a[i];
  vector<Int> s(w+2,0);
  for(Int i=0;i<w+1;i++) s[i+1]=s[i]+a[i];

  auto check=
    [&](Int x)->Int{
      for(Int i=0,j=0;i<w;i++){
        if(a[i]==0) continue;
        if(j<i) j=i;
        while(s[j+1]-s[i+1]<x) j++;
        if(i+l<j) return 0;
      }
      return 1;
    };
  
  Int L=0,R=1e15;
  while(L+1<R){
    Int M=(L+R)>>1;
    if(check(M)) L=M;
    else R=M;
  }
  cout<<L<<endl;
  return 0;
}