#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX_V 100050
#define MAX_LOG_V 50
vector<int> G[MAX_V];
int root=0;
int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(int v,int p,int d){
  parent[0][v]=p;
  depth[v]=d;
  for(int i=0;i<(int)G[v].size();i++){
    if(G[v][i]!=p) dfs(G[v][i],v,d+1);
  }
}

void init(int V){
  dfs(root,-1,0);
  for(int k=0;k+1<MAX_LOG_V;k++){
    for(int v=0;v<V;v++){
      if(parent[k][v]<0) parent[k+1][v]=-1;
      else parent[k+1][v]=parent[k][parent[k][v]];
    }
  }
}

int lca(int u,int v){
  if(depth[u]>depth[v]) swap(u,v);
  for(int k=0;k<MAX_LOG_V;k++){
    if((depth[v]-depth[u])>>k&1){
      v=parent[k][v];
    }
  }
  if(u==v) return u;
  for(int k=MAX_LOG_V-1;k>=0;k--){
    if(parent[k][u]!=parent[k][v]){
      u=parent[k][u];
      v=parent[k][v];
    }
  }
  return parent[0][u];
}

int x[MAX_V],y[MAX_V];
int p[MAX_V];
signed main(){
  int n;
  scanf("%lld",&n);
  for(int i=0;i<n;i++) scanf("%lld %lld",x+i,y+i);
  root=n-1;
  for(int i=n-2;i>=0;i--){
    int j=i+1;
    while(j<n-1){
      int l=p[j];
      if((y[j]-y[i])*(x[l]-x[j])<(y[l]-y[j])*(x[j]-x[i])){
	j=l;
	continue;
      }
      break;
    }
    p[i]=j;
    G[j].push_back(i);
    G[i].push_back(j);
  }
  init(n);
  int m;
  scanf("%lld",&m);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%lld %lld",&a,&b);
    a--;b--;
    if(i) printf(" ");
    printf("%lld",lca(a,b)+1);
  }
  puts("");
  return 0;
}