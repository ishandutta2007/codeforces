#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
using ll = long long;

const int MAX = 5e5 + 100;
vector<int> vs[MAX];
ll cs[MAX];
int idx[MAX];

signed solve(){
  int n,m;
  cin>>n>>m;

  for(int i=0;i<n;i++) cin>>cs[i];

  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    vs[v].emplace_back(u);
  }

  for(int i=0;i<n;i++){
    idx[i]=i;
    sort(vs[i].begin(),vs[i].end());
  }

  auto cmp=
    [&](int i,int j){
      if(vs[i].size()!=vs[j].size())
        return vs[i].size()<vs[j].size();
      for(int k=0;k<(int)vs[i].size();k++)
        if(vs[i][k]!=vs[j][k]) return vs[i][k]<vs[j][k];
      return false;
    };
  sort(idx,idx+n,cmp);

  ll ans=0,sum=0;
  for(int i=0;i<n;i++){
    if(vs[idx[i]].empty()) continue;
    sum+=cs[idx[i]];
    if(i+1<n&&vs[idx[i]]==vs[idx[i+1]]) continue;
    ans=__gcd(ans,sum);
    sum=0;
  }

  cout<<ans<<"\n";

  for(int i=0;i<n;i++) vs[i].clear();
  return 0;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int T;
  cin>>T;
  for(int t=1;t<=T;t++) solve();

  return 0;
}