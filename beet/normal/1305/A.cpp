#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE

signed solve(){
  int n;
  cin>>n;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>bs[i];
  sort(as.begin(),as.end());
  sort(bs.begin(),bs.end());
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<as[i];
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<bs[i];
  }
  cout<<endl;
  return 0;
}

signed main(){
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) solve();
  return 0;
}