#include<bits/stdc++.h>

using namespace std;

#define maxn 300005

struct Edge{
 int next,to;
}edge[maxn*2];

int fi[maxn],se,n,m,ma[maxn],dfn[maxn],low[maxn],si,ans;

inline void add_edge(int u,int v){
 edge[++se].next=fi[u],edge[se].to=v,fi[u]=se,
 edge[++se].next=fi[v],edge[se].to=u,fi[v]=se;
}

void dfs(int x,int f){
 dfn[x]=low[x]=++si;
 for(int i=fi[x];i;i=edge[i].next){
  int v=edge[i].to;
  if(v==f)continue;
  if(dfn[v])low[x]=min(low[x],dfn[v]);
  else{
   dfs(v,x);
   ans=max(ans,ma[x]+ma[v]+(low[v]>dfn[x]));
   ma[x]=max(ma[x],ma[v]+(low[v]>dfn[x]));
   low[x]=min(low[x],low[v]);
  }
 }
}

int main(){
 cin>>n>>m;
 int u,v;
 for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add_edge(u,v);
 dfs(1,0);
 cout<<ans;
}