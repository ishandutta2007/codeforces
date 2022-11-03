#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

template<typename V>
V compress(V vs){
  sort(vs.begin(),vs.end());
  vs.erase(unique(vs.begin(),vs.end()),vs.end());
  return vs;
}
template<typename T>
map<T, Int> dict(const vector<T> &vs){
  map<T, Int> res;
  for(Int i=0;i<(Int)vs.size();i++)
    res[vs[i]]=i;
  return res;
}
map<char, Int> dict(const string &s){
  return dict(vector<char>(s.begin(),s.end()));
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n;
  cin>>n;
  auto ls=read(n);
  auto cs=read(n);

  const Int INF = 1e18;
  Int ans=INF;

  for(Int s=0;s<n;s++){
    Int l=ls[s];
    vector<Int> vs;
    for(Int i=1;i*i<=l;i++){
      if(l%i) continue;
      vs.emplace_back(i);
      if(i*i!=l) vs.emplace_back(l/i);
    }
    sort(vs.begin(),vs.end());
    auto idx=[&](Int v){
      return lower_bound(vs.begin(),vs.end(),v)-vs.begin();
    };

    Int m=vs.size();
    vector<Int> dp(m,INF);
    dp[idx(l)]=cs[s];

    for(Int i=s+1;i<n;i++)
      for(Int j=0;j<m;j++)
        chmin(dp[idx(gcd(vs[j],ls[i]))],dp[j]+cs[i]);

    chmin(ans,dp[idx(1)]);
  }

  if(ans==INF) ans=-1;
  cout<<ans<<newl;
  return 0;
}