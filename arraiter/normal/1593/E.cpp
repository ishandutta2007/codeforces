#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=4e5+10;
int n,k,lev[maxn],Q[maxn];

set<int>E[maxn];

int main(){
  ios::sync_with_stdio(0);
  int T;cin>>T;while(T--){
    cin>>n>>k;
    if(n==1){
      cout<<0<<endl;
      continue;
    }
    rep(i,2,n){
      int u,v;cin>>u>>v;
      E[u].insert(v),E[v].insert(u);
    }
    int l=1,r=0;
    rep(i,1,n)if((int)E[i].size()==1)Q[++r]=i,lev[i]=1;
    int ans=n;
    while(l<=r){
      int u=Q[l++];
      if(lev[u]>k)break;
      ans--;
      for(int v:E[u]){
        if(E[v].count(u)){
          E[v].erase(u);
        }
        if((int)E[v].size()==1&&!lev[v]){
          lev[v]=lev[u]+1,Q[++r]=v;
        }
      }
      E[u].clear();
    }
    cout<<ans<<endl;
    rep(i,1,n)E[i].clear(),lev[i]=0;
  }
  return 0;
}