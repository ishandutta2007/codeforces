#include<bits/stdc++.h>
using namespace std;
using Int = long long;

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
  scanf("%lld",&n);
  vector<Int> a(n),b(n);
  for(Int i=0;i<n;i++)
    scanf("%lld %lld",&a[i],&b[i]);

  set<Int> s,t;
  {
    auto x=factorize(a[0]);
    auto y=factorize(b[0]);
    for(auto p:x) t.emplace(p.first);
    for(auto p:y) t.emplace(p.first);
  }

  for(Int i=0;i<n;i++){
    for(auto x:t)
      if(a[i]%x==0||b[i]%x==0) s.emplace(x);    
    s.swap(t);
    s.clear();
  }
  
  printf("%lld\n",t.empty()?-1:*t.begin());
  return 0;
}