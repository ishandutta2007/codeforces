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


struct LowestCommonAncestor{
  int n,h;
  vector< vector<int> > G,par;
  vector<int> dep;
  LowestCommonAncestor(){}
  LowestCommonAncestor(int n):n(n),G(n),dep(n){
    h=1;
    while((1<<h)<=n) h++;
    par.assign(h,vector<int>(n,-1));
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d){
    par[0][v]=p;
    dep[v]=d;
    for(int u:G[v])
      if(u!=p) dfs(u,v,d+1);
  }

  void build(int r=0){
    dfs(r,-1,0);
    for(int k=0;k+1<h;k++)
      for(int v=0;v<n;v++)
        if(~par[k][v])
          par[k+1][v]=par[k][par[k][v]];
  }

  int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0;k<h;k++)
      if((dep[v]-dep[u])>>k&1)
        v=par[k][v];

    if(u==v) return u;

    for(int k=h-1;k>=0;k--)
      if(par[k][u]!=par[k][v])
        u=par[k][u],v=par[k][v];

    return par[0][u];
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
  }
};

template<typename T, typename ...Ts>
vector<T> fusion(vector<T> bs,Ts... ts){
  auto append=[&](auto vs){for(auto v:vs) bs.emplace_back(v);};
  initializer_list<int>{(void(append(ts)),0)...};
  return bs;
}

template<typename V>
V compress(V v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}
map<char, int> dict(const string &v){
  return dict(vector<char>(v.begin(),v.end()));
}


class EulerTourForVertex{
private:
  vector<int> ls,rs;
  int pos;

  void dfs(int v,int p){
    ls[v]=pos++;
    for(int u:G[v])
      if(u!=p) dfs(u,v);
    rs[v]=pos;
  }

public:
  vector< vector<int> > G;

  EulerTourForVertex(){}
  EulerTourForVertex(int n):ls(n),rs(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(int r=0){
    pos=0;
    dfs(r,-1);
  }

  int idx(int v){return ls[v];}

  template<typename F>
  void exec(int v,F f){
    f(ls[v],rs[v]);
  }
};


struct AuxiliaryTree : EulerTourForVertex{
  using super = EulerTourForVertex;
  LowestCommonAncestor lca;

  vector<vector<int>> T;
  AuxiliaryTree(){}
  AuxiliaryTree(int n):super(n),lca(n),T(n){}

  void build(int r=0){
    super::build(r);
    lca.G=super::G;
    lca.build(r);
  }

  void add_aux_edge(int u,int v){
    T[u].emplace_back(v);
    T[v].emplace_back(u);
  }

  using super::idx;
  void query(vector<int> &vs){
    assert(!vs.empty());
    sort(vs.begin(),vs.end(),
         [&](int a,int b){return idx(a)<idx(b);});

    map<int, vector<int>> H;

    int k=vs.size();
    stack<int> st;
    st.emplace(vs[0]);
    for(int i=0;i+1<k;i++){
      int w=lca.lca(vs[i],vs[i+1]);
      if(w!=vs[i]){
        int l=st.top();st.pop();
        while(!st.empty()&&lca.dep[w]<lca.dep[st.top()]){
          add_aux_edge(st.top(),l);
          l=st.top();st.pop();
        }
        if(st.empty()||st.top()!=w){
          st.emplace(w);
          vs.emplace_back(w);
        }
        add_aux_edge(w,l);
      }
      st.emplace(vs[i+1]);
    }

    while(st.size()>1){
      int c=st.top();st.pop();
      add_aux_edge(st.top(),c);
    }
  }

  void clear(const vector<int> &ws){
    for(int w:ws) T[w].clear();
  }
};

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;
  AuxiliaryTree G(n);
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G.add_edge(x,y);
  }
  G.build();

  struct State{
    int pos,idx,step;
    State(int pos,int idx,int step):
      pos(pos),idx(idx),step(step){}
    bool operator<(const State &o)const{
      if(step!=o.step) return step>o.step;
      return idx>o.idx;
    }
  };
  const int INF = 1e9;
  State ti(INF,INF,INF);
  vector<State> dp(n,ti);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int k,m;
    cin>>k>>m;
    vector<int> vs(k),ss(k);
    for(int j=0;j<k;j++) cin>>vs[j]>>ss[j],vs[j]--;
    vector<int> us(m);
    for(int j=0;j<m;j++) cin>>us[j],us[j]--;

    vector<int> ws=compress(fusion(vs,us));
    G.query(ws);

    priority_queue<State> pq;
    auto push=
      [&](int pos,int idx,int step){
        State tmp(pos,idx,step);
        if(!(dp[pos]<tmp)) return;
        dp[pos]=tmp;
        pq.emplace(tmp);
      };

    for(int j=0;j<k;j++) push(vs[j],j,0);

    while(!pq.empty()){
      State s=pq.top();pq.pop();
      if(dp[s.pos]<s||s<dp[s.pos]) continue;
      for(int nxt:G.T[s.pos]){
        int npos=nxt;
        int nidx=s.idx;
        int nstep=(G.lca.distance(npos,vs[nidx])+ss[nidx]-1)/ss[nidx];
        push(npos,nidx,nstep);
      }
    }

    for(int j=0;j<m;j++){
      if(j) cout<<" ";
      cout<<dp[us[j]].idx+1;
    }
    cout<<"\n";

    for(int v:ws) dp[v]=ti;
    G.clear(ws);
  }
  cout<<flush;
  return 0;
}