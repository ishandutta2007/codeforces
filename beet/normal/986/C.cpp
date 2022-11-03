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

//INSERT ABOVE HERE
bool alive[1<<22]={};
bool used[1<<23]={};

int n,m,sz;
void dfs(int v){
  if(used[v]) return;
  used[v]=1;
  if(v<sz){
    dfs(sz+((sz-1)^v));
  }else{
    if(alive[v-sz]) dfs(v-sz);
    for(int i=0;i<n;i++)
      if((v>>i)&1) dfs(v^(1<<i));
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin>>n>>m;
  auto as=read(m);

  sz=1<<n;
  for(int a:as) alive[a]=1;

  int ans=0;
  for(int a:as){
    if(used[a]) continue;
    ans++;
    dfs(a);
  }
  cout<<ans<<newl;
  return 0;
}