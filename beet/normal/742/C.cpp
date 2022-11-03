#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> c(n);
  for(Int i=0;i<n;i++) cin>>c[i],c[i]--;

  vector<Int> d(n,0);
  for(Int i=0;i<n;i++) d[c[i]]++;
  for(Int i=0;i<n;i++){
    if(d[i]!=1){
      cout<<-1<<endl;
      return 0;
    }
  }

  Int ans=1;
  auto lcm=[](Int a,Int b){return a/__gcd(a,b)*b;};
  for(Int i=0;i<n;i++){
    Int j=c[i],t=1;
    while(j!=i) j=c[j],t++;
    ans=lcm(ans,(t&1)?t:t/2);
  }
  
  cout<<ans<<endl;
  return 0;
}