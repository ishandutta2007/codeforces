#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

const Int INF=1LL<<55;
struct Dinic{
  
  struct edge {
    Int to,cap,rev;
    edge(){}
    edge(Int to,Int cap,Int rev):to(to),cap(cap),rev(rev){}
  };

  Int n;
  vector<vector<edge> > G;
  vector<map<Int,Int> > M;
  vector<Int> level,iter;

  Dinic(){}
  Dinic(Int sz):n(sz),G(n),M(n),level(n),iter(n){}
  
  void add_edge(Int from,Int to,Int cap){
    M[from][to]=G[from].size();
    M[to][from]=G[to].size();
    G[from].push_back(edge(to,cap,G[to].size()));
    // undirected
    //G[to].push_back(edge(from,cap,G[from].size()-1));
    // directed
    G[to].push_back(edge(from,0,G[from].size()-1));
  }
  
  void bfs(Int s){
    fill(level.begin(),level.end(),-1);
    queue<Int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
      Int v=que.front();que.pop();
      for(Int i=0;i<(Int)G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap>0&&level[e.to]<0){
          level[e.to]=level[v]+1;
          que.push(e.to);
        }
      }
    }
  }
  
  Int dfs(Int v,Int t,Int f){
    if(v==t) return f;
    for(Int &i=iter[v];i<(Int)G[v].size();i++){
      edge &e=G[v][i];
      if(e.cap>0&&level[v]<level[e.to]){
        Int d = dfs(e.to,t,min(f,e.cap));
        if(d>0){
          e.cap-=d;
          G[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }
  
  Int flow(Int s,Int t,Int lim){
    Int fl=0;
    for(;;){
      bfs(s);
      if(level[t]<0||lim==0) return fl;
      fill(iter.begin(),iter.end(),0);
      Int f;
      while((f=dfs(s,t,lim))>0){
        fl+=f;
        lim-=f;
      }
    }
  }

  Int flow(Int s,Int t){
    return flow(s,t,INF);
  }

};

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  
  Dinic G(n+m+2);
  Int S=n+m,T=n+m+1;
  
  Int ans=0;
  for(Int i=0;i<m;i++){
    Int u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    ans+=w;
    G.add_edge(S,n+i,w);
    G.add_edge(n+i,u,INF);
    G.add_edge(n+i,v,INF);
  }
  
  for(Int i=0;i<n;i++)
    G.add_edge(i,T,a[i]);

  cout<<ans-G.flow(S,T)<<endl;
  return 0;
}