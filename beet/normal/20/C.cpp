#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template <typename T>
vector<Int> dijkstra(Int s,vector<vector<pair<Int, T> > > & G,T INF){
  using P = pair<T, Int>;
  Int n=G.size();
  vector<T> d(n,INF);
  vector<Int> b(n,-1);
  priority_queue<P,vector<P>,greater<P> > q;
  d[s]=0;
  q.emplace(d[s],s);
  while(!q.empty()){
    P p=q.top();q.pop();
    Int v=p.second;
    if(d[v]<p.first) continue;
    for(auto& e:G[v]){
      Int u=e.first;
      T c=e.second;
      if(d[u]>d[v]+c){
        d[u]=d[v]+c;
        b[u]=v;
        q.emplace(d[u],u);
      }
    }
  }
  return b;
}

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  using P = pair<Int, Int>;
  vector<vector<P> > G(n);
  for(Int i=0;i<m;i++){
    Int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    if(a==b) continue;
    G[a].emplace_back(b,c);
    G[b].emplace_back(a,c);
  }
  const Int INF = 1e15;
  auto b=dijkstra(0,G,INF);
  if(b[n-1]<0){
    cout<<-1<<endl;
    return 0;
  }
  vector<Int> ans;
  for(Int v=n-1;v;v=b[v]) ans.emplace_back(v);
  ans.emplace_back(0);
  reverse(ans.begin(),ans.end());

  for(Int i=0;i<(Int)ans.size();i++){
    if(i) cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}