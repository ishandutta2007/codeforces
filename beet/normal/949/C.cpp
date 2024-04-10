#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


struct SCC{
  vector< vector<int> > G,R,T,C;
  vector<int> vs,used,blg;
  SCC(){}
  SCC(int n):G(n),R(n),used(n),blg(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    used[v]=1;
    for(int u:G[v])
      if(!used[u]) dfs(u);
    vs.emplace_back(v);
  }

  void rdfs(int v,int k){
    used[v]=1;
    blg[v]=k;
    C[k].emplace_back(v);
    for(int u:R[v])
      if(!used[u]) rdfs(u,k);
  }

  int build(){
    int n=G.size();
    for(int v=0;v<n;v++)
      if(!used[v]) dfs(v);

    fill(used.begin(),used.end(),0);
    int k=0;
    for(int i=n-1;i>=0;i--){
      if(!used[vs[i]]){
        T.emplace_back();
        C.emplace_back();
        rdfs(vs[i],k++);
      }
    }

    for(int v=0;v<n;v++)
      for(int u:G[v])
        if(blg[v]!=blg[u])
          T[blg[v]].push_back(blg[u]);

    for(int i=0;i<k;i++){
      sort(T[i].begin(),T[i].end());
      T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
    }
    return k;
  }

  int operator[](int k) const{return blg[k];}
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,h;
  cin>>n>>m>>h;
  vector<int> us(n);
  for(int i=0;i<n;i++) cin>>us[i];

  SCC G(n);
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    assert(us[x]!=us[y]);

    if((us[x]+1)%h==us[y]) G.add_edge(x,y);
    if((us[y]+1)%h==us[x]) G.add_edge(y,x);
  }

  int k=G.build();
  cerr<<k<<endl;
  int idx=-1;
  for(int i=0;i<k;i++){
    if(!G.T[i].empty()) continue;
    if(idx<0 or G.C[i].size()<G.C[idx].size()) idx=i;
  }

  cout<<G.C[idx].size()<<newl;
  for(int i=0;i<(int)G.C[idx].size();i++){
    if(i) cout<<' ';
    cout<<G.C[idx][i]+1;
  }
  cout<<newl;
  return 0;
}