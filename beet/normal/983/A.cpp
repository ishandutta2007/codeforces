#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  scanf("%lld",&n);
  for(Int i=0;i<n;i++){
    Int p,q,b;
    scanf("%lld %lld %lld",&p,&q,&b);
    if(p==0){
      puts("Finite");
      continue;
    }
    Int k=__gcd(p,q);
    p/=k;
    q/=k;
    while(__gcd(q,b)!=1){
      k=__gcd(q,b);
      q/=k;
      b=k;
    }
    if(q==1) puts("Finite");
    else puts("Infinite");
  }
  return 0;
}