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


struct TopologicalSort{
  vector<vector<int>> G;
  vector<int> indeg;
  TopologicalSort(int n):G(n),indeg(n,0){}

  void add_edge(int s,int t){
    G[s].emplace_back(t);
    indeg[t]++;
  }

  vector<int> build(){
    int n=G.size();

    queue<int> que;
    vector<int> used(n,0);
    auto push=[&](int v){
      if(used[v]) return;
      que.emplace(v);
      used[v]=1;
    };

    for(int i=0;i<n;i++)
      if(indeg[i]==0) push(i);

    vector<int> ps;
    while(!que.empty()){
      int v=que.front();que.pop();
      ps.emplace_back(v);
      for(int u:G[v]){
        indeg[u]--;
        if(indeg[u]==0) push(u);
      }
    }

    if(n!=(int)ps.size()) return {};
    return ps;
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  auto conv=[&](char c){return c-'a';};
  TopologicalSort ts(26);

  int n;
  cin>>n;
  auto ss=read<string>(n);

  // return if y is prefix of x
  auto prefix=[&](string x,string y){
    assert(x!=y);
    if(x.size()<=y.size()) return false;
    return x.substr(0,y.size())==y;
  };

  for(int i=0;i+1<n;i++){
    if(prefix(ss[i+0],ss[i+1])) drop("Impossible");
    if(prefix(ss[i+1],ss[i+0])) continue;
    int m=min(ss[i+0].size(),ss[i+1].size());
    for(int j=0;j<m;j++){
      if(ss[i+0][j]==ss[i+1][j]) continue;
      ts.add_edge(conv(ss[i+0][j]),conv(ss[i+1][j]));
      break;
    }
  }

  auto ps=ts.build();
  if(ps.empty()) drop("Impossible");

  for(int p:ps) cout<<char('a'+p);
  cout<<newl;
  return 0;
}