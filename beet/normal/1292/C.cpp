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


template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}


struct LevelAncestor{
  int h;
  vector<vector<int> > G,par,lad;
  vector<int> dep,nxt,len,pth,ord,hs;
  LevelAncestor(int n):
    G(n),dep(n),nxt(n,-1),len(n),pth(n),ord(n),hs(n+1,0){
    h=1;
    while((1<<h)<=n) h++;
    par.assign(h,vector<int>(n,-1));
    for(int i=2;i<=n;i++) hs[i]=hs[i>>1]+1;
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d,int f){
    if(nxt[v]<0){
      par[0][nxt[v]=v]=p;
      len[v]=dep[v]=d;
      for(int u:G[v]){
        if(u==p) continue;
        dfs(u,v,d+1,0);
        if(len[v]<len[u]) nxt[v]=u,len[v]=len[u];
      }
    }
    if(!f) return;
    pth[v]=lad.size();
    lad.emplace_back();
    for(int k=v;;k=nxt[k]){
      lad.back().emplace_back(k);
      pth[k]=pth[v];
      if(k==nxt[k]) break;
    }
    for(;;p=v,v=nxt[v]){
      for(int u:G[v])
        if(u!=p and u!=nxt[v]) dfs(u,v,d+1,1);
      if(v==nxt[v]) break;
    }
  }

  void build(int r=0){
    int n=G.size();
    dfs(r,-1,0,1);
    for(int k=0;k+1<h;k++){
      for(int v=0;v<n;v++){
        if(par[k][v]<0) par[k+1][v]=-1;
        else par[k+1][v]=par[k][par[k][v]];
      }
    }
    for(int i=0;i<(int)lad.size();i++){
      int v=lad[i][0],p=par[0][v];
      if(~p){
        int k=pth[p],l=min(ord[p]+1,(int)lad[i].size());
        lad[i].resize(l+lad[i].size());
        for(int j=0,m=lad[i].size();j+l<m;j++)
          lad[i][m-(j+1)]=lad[i][m-(j+l+1)];
        for(int j=0;j<l;j++)
          lad[i][j]=lad[k][ord[p]-l+j+1];
      }
      for(int j=0;j<(int)lad[i].size();j++)
        if(pth[lad[i][j]]==i) ord[lad[i][j]]=j;
    }
  }

  int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0;k<h;k++){
      if((dep[v]-dep[u])>>k&1){
        v=par[k][v];
      }
    }
    if(u==v) return u;
    for(int k=h-1;k>=0;k--){
      if(par[k][u]!=par[k][v]){
        u=par[k][u];
        v=par[k][v];
      }
    }
    return par[0][u];
  }

  int up(int v,int d){
    if(d==0) return v;
    v=par[hs[d]][v];
    d-=1LL<<hs[d];
    return lad[pth[v]][ord[v]-d];
  }

  // from u to v
  int next(int u,int v){
    if(dep[u]>=dep[v]) return par[0][u];
    int l=up(v,dep[v]-dep[u]-1);
    return par[0][l]==u?l:par[0][u];
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
  }
};

//INSERT ABOVE HERE
const int MAX = 3030;
int sub[MAX];
int cst[MAX][MAX];

using ll = long long;
ll dp[MAX][MAX];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  LevelAncestor G(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v);
  }
  G.build();

  // sub
  {
    MFP([&](auto dfs,int v,int p,int d)->int{
      int &res=sub[v];
      res=1;
      for(int u:G.G[v])
        if(u!=p) res+=dfs(u,v,d+1);
      return res;
    })(0,-1,0);
  }

  auto par=G.par[0];
  auto dep=G.dep;
  {
    memset(cst,-1,sizeof(cst));
    for(int u=0;u<n;u++){
      for(int v=0;v<n;v++){
        if(u==v) continue;
        if(G.next(u,v)==par[u] and G.next(v,u)==par[v]){
          cst[u][v]=sub[u]*sub[v];
          continue;
        }
        if(dep[u]<dep[v]){
          assert(par[G.next(u,v)]==u);
          cst[u][v]=sub[v]*(n-sub[G.next(u,v)]);
        }else{
          assert(par[G.next(v,u)]==v);
          cst[u][v]=sub[u]*(n-sub[G.next(v,u)]);
        }
      }
    }
  }

  ll ans=0;
  {
    memset(dp,-1,sizeof(dp));
    auto dfs=MFP([&](auto dfs,int u,int v)->ll{
      ll &res=dp[u][v];
      if(~res) return res;
      if(u==v) return res=0;
      res=0;
      chmax(res,dfs(u,G.next(v,u)));
      chmax(res,dfs(G.next(u,v),v));
      res+=cst[u][v];
      return res;
    });
    for(int u=0;u<n;u++)
      for(int v=0;v<n;v++)
        chmax(ans,dfs(u,v));
  }
  cout<<ans<<newl;
  return 0;
}