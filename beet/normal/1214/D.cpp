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


template<typename T,bool directed>
struct Fordfulkerson{
  struct edge{
    int to,cap,rev;
    edge(){}
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
  };

  vector<vector<edge> > G;
  vector<int> used;

  Fordfulkerson(){}
  Fordfulkerson(int n):G(n),used(n){}

  void add_edge(int from,int to,T cap){
    G[from].emplace_back(to,cap,G[to].size());
    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
  }

  T dfs(int v,int t,T f){
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++){
      edge &e = G[v][i];
      if(!used[e.to]&&e.cap>0){
        T d=dfs(e.to,t,min(f,e.cap));
        if(d>0){
          e.cap-=d;
          G[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }

  int flow(int s,int t,T lim){
    T fl=0;
    while(1){
      fill(used.begin(),used.end(),0);
      T f=dfs(s,t,lim);
      if(f==0) break;
      fl+=f;
      lim-=f;
    }
    return fl;
  }
};

//INSERT ABOVE HERE
signed main(){
  int n,m;
  cin>>n>>m;

  vector<string> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  const int sz = n*m;
  Fordfulkerson<int, true> G(sz*2);
  auto idx=[&](int i,int j,int k){return k*sz+i*m+j;};

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(vs[i][j]!='#') G.add_edge(idx(i,j,0),idx(i,j,1),1);
      if(i+1<n) G.add_edge(idx(i,j,1),idx(i+1,j,0),1);
      if(j+1<m) G.add_edge(idx(i,j,1),idx(i,j+1,0),1);
    }
  }

  cout<<G.flow(sz,sz-1,2)<<endl;
  return 0;
}