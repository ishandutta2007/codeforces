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
signed main(){
  Int n,m,k;
  cin>>n>>m>>k;

  vector<Int> b(n);
  for(Int i=0;i<n;i++) cin>>b[i];

  Int ans=n;
  vector<Int> vs;
  for(Int i=0;i+1<n;i++)
    vs.emplace_back(b[i+1]-b[i]-1);
  
  sort(vs.begin(),vs.end());
  for(Int i=0;i<n-k;i++) ans+=vs[i];

  cout<<ans<<endl;
  return 0;
}