#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T> 
map<T, Int> factorize(T x){
  map<T, Int> res;
  for(Int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}

//INSERT ABOVE HERE
signed main(){
  Int n;
  while(cin>>n){
    vector<Int> a(n+1,0);
    {
      auto m=factorize(n);
      for(auto p:m){
	Int x=p.first;
	for(Int i=0;i<x;i++)
	  if(n-i>x) a[n-i]=1;
      }
    }
    Int ans=n;
    vector<Int> p(n+1,0);
    for(Int i=2;i<=n;i++){
      if(p[i]) continue;
      if(a[i]) chmin(ans,i);
      for(Int j=i+i;j<=n;j+=i){
	p[j]=1;
	if(!a[j]) continue;
	chmin(ans,j-i+1);
	break;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}