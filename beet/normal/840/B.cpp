#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


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


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  vector<int> ds(n);
  for(int i=0;i<n;i++) cin>>ds[i];

  using P = pair<int, int>;
  vector<vector<P>> G(n);
  set<P> seen;
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    if(!(u<v)) swap(u,v);
    if(seen.count(P(u,v))) continue;
    seen.emplace(u,v);
    G[u].emplace_back(v,i);
    G[v].emplace_back(u,i);
  }

  int rt=-1;
  for(int i=0;i<n;i++){
    if(ds[i]<0){
      if(~rt) ds[i]=0;
      else rt=i;
    }
  }
  if(!(~rt)) rt=0;

  vector<int> used(m,0);

  int pos=0;
  vector<int> ord(n,-1);
  MFP([&](auto dfs,int v,int p)->int{
    ord[v]=pos++;
    int res=ds[v]<0?0:ds[v];

    for(auto [u, k]:G[v]){
      if(u==p) continue;
      if(~ord[u]) continue;
      int tmp=dfs(u,v);
      if(tmp){
        used[k]^=1;
        res^=1;
      }
    }

    if(v==rt and ~ds[v] and res) drop(-1);
    return res;
  })(rt,-1);

  cout<<accumulate(used.begin(),used.end(),0)<<newl;
  int fst=0;
  for(int i=0;i<m;i++){
    if(!used[i]) continue;
    if(exchange(fst,1)) cout<<' ';
    cout<<i+1;
  }
  cout<<newl;
  return 0;
}