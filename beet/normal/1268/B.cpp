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


// O(N M)
struct Bipartite{
  Int time;
  vector< vector<Int> > G;
  vector<Int> match,used,dead;

  Bipartite(Int n):
    time(0),G(n),match(n,-1),used(n,-1),dead(n,0){}

  void add_edge(Int u,Int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  Int dfs(Int v){
    used[v]=time;
    for(Int u:G[v]){
      if(dead[u]) continue;
      Int w=match[u];
      if((w<0) or (used[w]<time and dfs(w))){
        match[v]=u;
        match[u]=v;
        return 1;
      }
    }
    return 0;
  }

  Int build(){
    Int res=0;
    for(Int v=0;v<(Int)G.size();v++){
      if(dead[v] or ~match[v]) continue;
      time++;
      res+=dfs(v);
    }
    return res;
  }

  Int disable(Int v){
    assert(!dead[v]);
    Int u=match[v];
    if(~u) match[u]=-1;
    match[v]=-1;
    dead[v]=1;
    time++;
    return ~u?dfs(u)-1:0;
  }

  Int enable(Int v){
    assert(dead[v]);
    dead[v]=0;
    time++;
    return dfs(v);
  }

  Int cut_edge(Int u,Int v){
    assert(find(G[u].begin(),G[u].end(),v)!=G[u].end());
    assert(find(G[v].begin(),G[v].end(),u)!=G[v].end());
    G[u].erase(find(G[u].begin(),G[u].end(),v));
    G[v].erase(find(G[v].begin(),G[v].end(),u));
    if(match[u]==v){
      match[u]=match[v]=-1;
      return 1;
    }
    return 0;
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n;
  cin>>n;

  auto as=read(n);

  Int odd=0,even=0;
  for(Int i=0;i<n;i++){
    Int x=as[i]/2,y=as[i]-x;
    if(i&1) swap(x,y);
    odd+=x;
    even+=y;
  }
  Int ans=min(odd,even);
  cout<<ans<<endl;

  if(0){
    Bipartite G(50*50);
    auto idx=[&](Int i,Int j){return i*50+j;};
    for(Int i=0;i<n;i++){
      for(Int j=0;j<as[i];j++){
        if(j+1<as[i]) G.add_edge(idx(i,j),idx(i,j+1));
        if(i+1<n and j<as[i+1])  G.add_edge(idx(i,j),idx(i+1,j));
      }
    }
    assert(ans==G.build());
  }
  return 0;
}