#include<bits/stdc++.h>
using namespace std;
#define MAX_V 200050
int V;
vector<int> G[MAX_V],rG[MAX_V],vs;
bool used[MAX_V];
int cmp[MAX_V];
void add_edge(int from,int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}
void dfs(int v){
  used[v]=1;
  for(int i=0;i<(int)G[v].size();i++){
    if(!used[G[v][i]]) dfs(G[v][i]);
  }
  vs.push_back(v);
}
void rdfs(int v,int k){
  used[v]=1;
  cmp[v]=k;
  for(int i=0;i<(int)rG[v].size();i++){
    if(!used[rG[v][i]]) rdfs(rG[v][i],k);
  }
}
int scc(){
  memset(used,0,sizeof(used));
  vs.clear();
  for(int v=0;v<V;v++){
    if(!used[v]) dfs(v);
  }
  memset(used,0,sizeof(used));
  int k=0;
  for(int i=vs.size()-1;i>=0;i--){
    if(!used[vs[i]]) rdfs(vs[i],k++);
  }
  return k;
}
int main(){
  int n,m;
  cin>>n>>m;
  int o[n];
  for(int i=0;i<n;i++) cin>>o[i];
  vector<int> s[n];
  for(int i=0;i<m;i++){
    int r;
    cin>>r;
    for(int j=0;j<r;j++){
      int k;
      cin>>k;
      k--;
      s[k].push_back(i);
    }
  }
  for(int i=0;i<n;i++){
    assert((int)s[i].size()==2);
    //cout<<o[i]<<" "<<s[i][0]<<" "<<s[i][1]<<endl;
    if(o[i]){
      add_edge(s[i][0],s[i][1]);
      add_edge(s[i][1],s[i][0]);
      add_edge(s[i][0]+m,s[i][1]+m);
      add_edge(s[i][1]+m,s[i][0]+m);
    }else{
      add_edge(s[i][0],s[i][1]+m);
      add_edge(s[i][1],s[i][0]+m);
      add_edge(s[i][0]+m,s[i][1]);
      add_edge(s[i][1]+m,s[i][0]);
    }
  }
  V=m*2;
  scc();
  for(int i=0;i<m;i++){
    //cout<<cmp[i]<<" "<<cmp[i+m]<<endl;
    if(cmp[i]==cmp[i+m]){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}