#include<bits/stdc++.h>
using namespace std;
#define MAX_V 2050
vector<int> G[MAX_V];
int match[MAX_V],V;
bool used[MAX_V];
void add_edge(int u,int v){
  G[u].push_back(v);
  G[v].push_back(u);
}
bool dfs(int v){
  used[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    int u=G[v][i],w=match[u];
    if(w<0||(!used[w]&&dfs(w))){
      match[v]=u;
      match[u]=v;
      return true;
    }
  }
  return false;
}

int bipartite_matching(){
  int res=0;
  memset(match,-1,sizeof(match));
  for(int v=0;v<V;v++){
    if(match[v]<0){
      memset(used,0,sizeof(used));
      if(dfs(v)){
	res++;
      }
    }
  }
  return res;
}


int main(){
  int n;
  string s,t;
  cin>>n>>s>>t;
  V=n*2;

  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(s[i]<=t[j]) add_edge(i,j+n);
  cout<<n-bipartite_matching()<<endl;
  
  for(int i=0;i<MAX_V;i++) G[i].clear();
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(s[i]<t[j]) add_edge(i,j+n);
  cout<<bipartite_matching()<<endl;
  
  return 0;
}