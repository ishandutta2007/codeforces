#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


vector<int> identity(int n){
  vector<int> ord(n);
  iota(ord.begin(),ord.end(),0);
  return ord;
}


template<typename ...Ts>
decltype(auto) zip(vector<Ts>... args){
  vector<decltype(make_tuple(args[0]...))> res;
  int n=min({args.size()...});
  res.reserve(n);
  for(int i=0;i<n;i++) res.emplace_back(args[i]...);
  return res;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int m;
  cin>>m;
  vector<int> as(m),bs(m);
  for(int i=0;i<m;i++) cin>>as[i];
  for(int i=0;i<m;i++) cin>>bs[i];

  auto bp=zip(bs,identity(m));

  sort(as.rbegin(),as.rend());
  sort(bp.begin(),bp.end());

  vector<int> ans(m);
  for(int i=0;i<m;i++)
    ans[get<1>(bp[i])]=as[i];

  for(int i=0;i<m;i++){
    if(i) cout<<' ';
    cout<<ans[i];
  }
  cout<<newl;
  return 0;
}