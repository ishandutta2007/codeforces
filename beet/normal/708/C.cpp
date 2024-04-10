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


template<typename T, typename Edge>
struct ReRooting{
  struct Node{
    Int to,rev;
    Edge data;
    Node(Int to,Edge data):to(to),data(data){}
    bool operator<(const Node &v)const{return to<v.to;};
  };

  using Fold = function<T(T, T)>;
  using Lift = function<T(T, Edge)>;

  vector< vector<Node> > G;
  vector< vector<T> > ld,rd;
  vector<Int> lp,rp;

  const Fold fold;
  const Lift lift;
  const T id;

  ReRooting(Int n,const Fold fold,const Lift lift,const T id):
    G(n),ld(n),rd(n),lp(n),rp(n),fold(fold),lift(lift),id(id){}

  void add_edge(Int u,Int v,Edge d,Edge e){
    G[u].emplace_back(v,d);
    G[v].emplace_back(u,e);
  }

  void add_edge(Int u,Int v,Edge d){add_edge(u,v,d,d);}

  // k: idx for edge (not vertex)
  T dfs(Int v,Int k){
    while(lp[v]!=k and lp[v]<(Int)G[v].size()){
      auto &e=G[v][lp[v]];
      ld[v][lp[v]+1]=fold(ld[v][lp[v]],lift(dfs(e.to,e.rev),e.data));
      lp[v]++;
    }
    while(rp[v]!=k and rp[v]>=0){
      auto &e=G[v][rp[v]];
      rd[v][rp[v]]=fold(rd[v][rp[v]+1],lift(dfs(e.to,e.rev),e.data));
      rp[v]--;
    }
    if(k<0) return rd[v][0];
    return fold(ld[v][k],rd[v][k+1]);
  }

  Int search(vector<Node> &vs,Int idx){
    return lower_bound(vs.begin(),vs.end(),Node(idx,vs[0].data))-vs.begin();
  }

  vector<T> build(){
    Int n=G.size();
    for(Int i=0;i<n;i++){
      sort(G[i].begin(),G[i].end());
      ld[i].assign((Int)G[i].size()+1,id);
      rd[i].assign((Int)G[i].size()+1,id);
      lp[i]=0;
      rp[i]=(Int)G[i].size()-1;
    }

    for(Int i=0;i<n;i++)
      for(Node &t:G[i])
        t.rev=search(G[t.to],i);

    vector<T> res;
    for(Int i=0;i<n;i++)
      res.emplace_back(dfs(i,-1));

    return res;
  }

  // p: idx for vertex
  T subtree(Int v,Int p){
    Int k=search(G[p],v);
    assert(k<(Int)G[p].size() and G[p][k].to==v);
    return lift(dfs(v,G[p][k].rev),G[p][k].data);
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n;
  cin>>n;

  using P = pair<Int, Int>;
  auto fold=[&](P a,P b){return P(a.first+b.first,max(a.second,b.second));};
  auto lift=[&](P a,Int b){
    return P(a.first+1,max(a.second,a.first+b<=n/2?a.first+b:0));
  };
  ReRooting<P, Int> G(n,fold,lift,P(0,0));

  for(Int i=1;i<n;i++){
    Int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v,1,1);
  }
  G.build();

  for(Int v=0;v<n;v++){
    Int valid=1;
    for(auto e:G.G[v]){
      auto res=G.subtree(e.to,v);
      if(res.first<=n/2) continue;
      assert(res.second<=n/2);
      valid&=(res.first-res.second)<=n/2;
    }
    if(v) cout<<' ';
    cout<<valid;
  }
  cout<<newl;
  return 0;
}