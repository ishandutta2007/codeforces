#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string s;
  cin>>s;
  int k=count(s.begin(),s.end(),'0')-count(s.begin(),s.end(),'1');
  if(k<=0) drop(-1);

  vector<vector<int>> ans(k);
  queue<int> oq,zq;
  for(int i=0;i<k;i++) oq.emplace(i);

  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='0'){
      if(oq.empty()) drop(-1);
      int d=oq.front();oq.pop();
      ans[d].emplace_back(i);
      zq.emplace(d);
    }
    if(s[i]=='1'){
      if(zq.empty()) drop(-1);
      int d=zq.front();zq.pop();
      ans[d].emplace_back(i);
      oq.emplace(d);
    }
  }

  if(!oq.empty()) drop(-1);
  cout<<k<<newl;
  for(int i=0;i<k;i++){
    cout<<ans[i].size();
    for(int v:ans[i]) cout<<' '<<v+1;
    cout<<newl;
  }
  return 0;
}