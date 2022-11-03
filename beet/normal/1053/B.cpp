#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  scanf("%lld",&n);
  vector<Int> a(n);
  for(Int i=0;i<n;i++) scanf("%lld",&a[i]);

  vector<Int> b(n);
  for(Int i=0;i<n;i++) b[i]=__builtin_popcountll(a[i]);
  for(Int i=0;i<n;i++) assert(1<=b[i]&&b[i]<=60);
   
  const Int B = 200;
  Int ans=0;
  vector<Int> s(n+1,0),t(n+1,0);
  t[0]=1;
  
  Int x=0;
  for(Int i=0;i<n;i++){
    Int k=0,c=0;
    for(Int j=0;j<=min(B,i);j++){
      chmax(k,b[i-j]);
      c+=b[i-j];
      if(c%2==0&&k*2<=c) ans++;
    }
    
    x+=b[i];    
    if(i>B) ans+=(x&1)?s[i-B-1]:t[i-B-1];    
    
    s[i+1]=s[i]+(x&1);
    t[i+1]=t[i]+(~x&1);
  }
  printf("%lld\n",ans);
  return 0;
}