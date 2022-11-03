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

struct BiMatch{
  Int n,time;
  vector<vector<Int>> G;
  vector<Int> match,used,dead;

  BiMatch(){}
  BiMatch(Int n):n(n),time(0),G(n),
                 match(n,-1),used(n,-1),dead(n,0){}

  void add_edge(Int u,Int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  Int dfs(Int v){
    used[v]=time;
    for(Int u:G[v]){
      if(dead[u]) continue;
      Int w=match[u];
      if((w<0)||(used[w]<time&&dfs(w))){
        match[v]=u;
        match[u]=v;
        return 1;
      }
    }
    return 0;
  }

  Int build(){
    Int res=0;
    for(Int v=0;v<n;v++){
      if(dead[v]) continue;
      if(match[v]<0){
        time++;
        res+=dfs(v);
      }
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
};

//INSERT ABOVE HERE
signed solve(Int n,Int m){
  using P = pair<Int, Int>;
  BiMatch bm(n*m);
  for(Int i=0;i<n;i++){
    for(Int j=0;j<m;j++){
      for(Int a=0;a<n;a++){
        for(Int b=0;b<m;b++){
          if(abs(i-a)+abs(j-b)!=3) continue;
          if(P(i,j)<P(a,b))
            bm.add_edge(i*m+j,a*m+b);
        }
      }
    }
  }
  return bm.build()*2;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n,m;
  cin>>n>>m;
  if(!(n<=m)) swap(n,m);

  // cerr<<solve(n,m)<<endl;

  if(n==1){
    Int ans=m/6*6;
    Int res=m%6;
    drop(ans+max<Int>(0,res-3)*2);
  }

  if(m<=20) drop(solve(n,m));
  drop(n*m/2*2);
  return 0;
}