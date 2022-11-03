#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct TopologicalSort{
  int n;
  vector<set<int> > G;
  vector<bool> used;
  vector<int> indeg,p;
  
  TopologicalSort(){}
  TopologicalSort(int sz):n(sz),G(n),used(n),indeg(n),p(0){}

  void add_edge(int s,int t){
    G[s].insert(t);
  }
  
  void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s]=1;
    while(!q.empty()){
      int v=q.front();q.pop();
      p.push_back(v);
      for(int u:G[v]){
        indeg[u]--;
        if(indeg[u]==0&&!used[u]){
          used[u]=1;
          q.push(u);
        }
      }
    }
  }
  
  vector<int>  build(){
    fill(used.begin(),used.end(),0);
    fill(indeg.begin(),indeg.end(),0);
    
    for(int i=0;i<n;i++)
      for(int v:G[i]) indeg[v]++;
    
    for(int i=0;i<n;i++)
      if(indeg[i]==0&&!used[i]) bfs(i);
    
    return p;
  }
};


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
const int MAX = 5050;
const signed INF = 1e9+100;
signed dp[MAX][MAX];
signed main(){
  int n,m,t;
  cin>>n>>m>>t;
  using P = pair<int, int>;
  vector<vector<P> > G(n);
  vector<vector<P> > rG(n);
  TopologicalSort ts(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    G[a].emplace_back(b,c);
    rG[b].emplace_back(a,c);
    ts.add_edge(a,b);
  }
  
  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++)
      dp[i][j]=INF;
  
  auto ord=ts.build();
  for(int v:ord){
    if(v==0) dp[v][1]=0;
    for(int i=0;i<=n;i++){
      if(dp[v][i]>t) continue;
      for(auto e:G[v]){
        int u=e.first,c=e.second;
        chmin(dp[u][i+1],dp[v][i]+c);
      }      
    }
  }

  int pos=n-1,res=0;
  for(int i=0;i<MAX;i++)
    if(dp[n-1][i]<=t) res=i;
  //cout<<pos<<" "<<res<<endl;
  
  vector<int> ans;
  ans.emplace_back(pos);
  while(pos!=0){
    for(P e:rG[pos]){
      int nxt=e.first,cost=e.second;
      if(dp[nxt][res-1]+cost!=dp[pos][res]) continue;
      pos=nxt;
      res=res-1;
      break;
    }
    ans.emplace_back(pos);
  }  
  reverse(ans.begin(),ans.end());
  
  cout<<ans.size()<<endl;
  for(int i=0;i<(int)ans.size();i++){
    if(i) cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}