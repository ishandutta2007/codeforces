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

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> ds(n),ss(n);
  for(int i=0;i<n;i++) cin>>ds[i]>>ss[i];

  using P = pair<int, int>;
  vector<P> vp;
  vector<int> deg(ds);
  vector<int> val(ss);
  auto add_edge=[&](int u,int v){
    vp.emplace_back(u,v);
    deg[u]--;deg[v]--;
    val[u]^=v;
    val[v]^=u;
  };

  queue<int> que;
  for(int i=0;i<n;i++)
    if(deg[i]==1) que.emplace(i);

  while(!que.empty()){
    int v=que.front();que.pop();
    if(deg[v]==0) continue;

    int u=val[v];
    add_edge(u,v);
    if(deg[u]==1) que.emplace(u);
  }

  cout<<vp.size()<<newl;
  for(auto[u,v]:vp)
    cout<<u<<' '<<v<<newl;
  return 0;
}