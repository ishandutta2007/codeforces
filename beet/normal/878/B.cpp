#include<bits/stdc++.h>
using namespace std;
using Int = long long;
using P = pair<Int,Int>;
using DP = deque<P>;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  auto get=[](vector<Int> &a,DP &lp,Int k){
    Int n=a.size();
    for(Int i=0;i<n;i++){
      if(lp.empty()||lp.back().first!=a[i])
	lp.push_back(P(a[i],0));
      lp.back().second++;
      if(lp.back().second==k) lp.pop_back();
    }
  };
  auto sum=[](const DP &lp){
    Int res=0;
    for(P x:lp) res+=x.second;
    return res;
  };
  Int k;
  DP lp;
  function<Int(Int)> solve=[&](Int m){
    Int n=sum(lp);
    if((Int)lp.size()<=1) return (n*m)%k;
    if(lp.front().first!=lp.back().first)  return n*m;
    Int a=lp.front().second;
    Int b=lp.back().second;
    assert(a&&b);
    assert(a<k&&b<k);
    Int s=a+b;
    lp.pop_front();
    lp.pop_back();
    if(s%k){
      Int t=solve(1);
      if(t) return s+(s%k)*(m-1)+t*m;
      return (s*m)%k;
    }
    Int t=solve(m);
    if(t) return s+t;
    return 0LL;
  };
  Int n,m;
  cin>>n>>k>>m;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  get(a,lp,k);
  cout<<solve(m)<<endl;
  return 0;
}