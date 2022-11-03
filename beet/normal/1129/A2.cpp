#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  vector<int> as(m),bs(m);
  for(int i=0;i<m;i++) cin>>as[i]>>bs[i];

  vector<int> cs(n*3);
  vector<int> ds(n*3,1e9);
  for(int i=0;i<m;i++){
    as[i]--;bs[i]--;
    if(as[i]>bs[i]) bs[i]+=n;
    for(int k=0;k<3;k++){
      cs[as[i]+n*k]++;
      chmin(ds[as[i]+n*k],bs[i]+n*k);
    }
  }

  for(int i=0;i<n;i++){
    if(i) cout<<' ';
    int res=0;
    for(int j=0;j<n;j++){
      if(cs[i+j]==0) continue;
      chmax(res,(cs[i+j]-1)*n+ds[i+j]);
    }
    cout<<res-i;
  }
  cout<<newl;
  return 0;
}