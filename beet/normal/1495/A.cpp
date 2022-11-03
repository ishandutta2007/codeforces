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


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
using D = long double;
D calc(vector<Int> xs,vector<Int> ys){
  D res=0;
  for(Int i=0;i<(Int)xs.size();i++)
    res+=sqrt(D(xs[i])*D(xs[i])+D(ys[i])*D(ys[i]));
  return res;
}

signed solve(){
  Int n;
  cin>>n;
  vector<Int> xs,ys;
  for(Int i=0;i<n+n;i++){
    Int x,y;
    cin>>x>>y;
    if(x!=0) xs.emplace_back(abs(x));
    if(y!=0) ys.emplace_back(abs(y));
  }
  sort(xs.begin(),xs.end());
  sort(ys.begin(),ys.end());
  D ans=calc(xs,ys);
  reverse(ys.begin(),ys.end());
  chmin(ans,calc(xs,ys));
  cout<<ans<<newl;
  return 0;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int t;
  cin>>t;
  while(t--) solve();

  return 0;
}