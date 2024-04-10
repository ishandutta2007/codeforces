#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


template<typename T>
int isprime(T x){
  if(x<=1) return 0;
  for(T i=2;i*i<=x;i++)
    if(x%i==0) return 0;
  return 1;
}


// O(E V^2)
// O(E \min(E^{1/2}, V^{2/3})) if caps are constant
template<typename Flow,bool directed>
struct Dinic{
  struct Edge {
    int dst;
    Flow cap;
    int rev;
    Edge(int dst,Flow cap,int rev):dst(dst),cap(cap),rev(rev){}
  };

  vector< vector<Edge> > G;
  vector<int> level,iter;

  Dinic(int n):G(n),level(n),iter(n){}

  int add_edge(int src,int dst,Flow cap){
    int e=G[src].size();
    int r=(src==dst?e+1:G[dst].size());
    G[src].emplace_back(dst,cap,r);
    G[dst].emplace_back(src,directed?0:cap,e);
    return e;
  }

  void bfs(int s){
    fill(level.begin(),level.end(),-1);
    queue<int> que;
    level[s]=0;
    que.emplace(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      for(Edge &e : G[v]) {
        if(e.cap>0 and level[e.dst]<0){
          level[e.dst]=level[v]+1;
          que.emplace(e.dst);
        }
      }
    }
  }

  Flow dfs(int v,int t,Flow f){
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++){
      Edge &e=G[v][i];
      if(e.cap>0 and level[v]<level[e.dst]){
        Flow d=dfs(e.dst,t,min(f,e.cap));
        if(d==0) continue;
        e.cap-=d;
        G[e.dst][e.rev].cap+=d;
        return d;
      }
    }
    return 0;
  }

  Flow flow(int s,int t,Flow lim){
    Flow fl=0;
    while(1){
      bfs(s);
      if(level[t]<0 or lim==0) break;
      fill(iter.begin(),iter.end(),0);

      while(1){
        Flow f=dfs(s,t,lim);
        if(f==0) break;
        fl+=f;
        lim-=f;
      }
    }
    return fl;
  }

  Flow flow(int s,int t){
    return flow(s,t,numeric_limits<Flow>::max()/2);
  }

  Flow cut(int s,int t,int x,int a){
    static_assert(directed, "must be directed");
    auto &e=G[x][a];
    int y=e.dst;
    Flow cr=G[y][e.rev].cap;
    if(cr==0) return e.cap=0;
    e.cap=G[y][e.rev].cap=0;
    Flow cap=cr-flow(x,y,cr);
    if(x!=s and cap!=0) flow(x,s,cap);
    if(t!=y and cap!=0) flow(t,y,cap);
    return cap;
  }

  Flow link(int s,int t,int x,int a,Flow f){
    auto &e=G[x][a];
    e.cap+=f;
    return flow(s,t,f);
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto as=read(n);

  const int MAX = 3e4;
  vector<int> pr(MAX);
  for(int i=2;i<MAX;i++)
    pr[i]=isprime(i);

  int S=n,T=n+1;
  Dinic<int, true> G(n+2);
  using P = pair<int, int>;
  vector<vector<P>> I(n);
  for(int i=0;i<n;i++){
    if(as[i]&1){
      G.add_edge(S,i,2);
      for(int j=0;j<n;j++){
        if(pr[as[i]+as[j]]){
          int k=G.add_edge(i,j,1);
          I[i].emplace_back(j,k);
        }
      }
    }else{
      G.add_edge(i,T,2);
    }
  }

  if(G.flow(S,T)!=n) drop("Impossible");

  vector<set<int>> H(n);
  for(int i=0;i<n;i++){
    for(auto[j,k]:I[i]){
      if(G.G[i][k].cap==0){
        H[i].emplace(j);
        H[j].emplace(i);
      }
    }
  }
  vector<vector<int>> C;
  vector<int> used(n,0);
  for(int i=0;i<n;i++){
    if(used[i]) continue;
    C.emplace_back();
    int cur=i;
    while(!H[cur].empty()){
      int nxt=*H[cur].begin();
      assert(pr[as[cur]+as[nxt]]);
      H[cur].erase(nxt);
      H[nxt].erase(cur);
      cur=nxt;
      C.back().emplace_back(cur);
    }
    for(int v:C.back()) used[v]=1;
  }
  cout<<C.size()<<newl;
  for(auto vs:C){
    cout<<vs.size();
    for(int v:vs) cout<<' '<<v+1;
    cout<<newl;
  }
  return 0;
}