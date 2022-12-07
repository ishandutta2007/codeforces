#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
vector <int> adj[maxn];
int n,dep[maxn],id[maxn],f[maxn],g[maxn],a,b,c,ans;
/*
f: 
g:  + 
*/
void upd(int u,int v,int w,int res){
  if(res > ans){
    ans = res;
    a = u;
    b = v;
    c = w;
  }
}
void dfs1(int u,int p){
  dep[u] = dep[p] + 1;
  id[u] = f[u] = g[u] = u;
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == p) continue;
    dfs1(v,u);
    upd(f[u],g[u],f[v],dep[f[u]] + dep[g[u]] + dep[f[v]] - 3 * dep[u]);
    if(dep[f[v]] > dep[f[u]]){
      g[u] = f[u];
      f[u] = f[v];
      id[u] = v;
    }else if(dep[f[v]] > dep[g[u]]){
      g[u] = f[v];
    }
  }
}
int h[maxn];
void dfs2(int u,int p){
  h[u] = u;
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == p) continue;
    dfs2(v,u);
    #define val(u) (dep[f[u]] + dep[g[u]] - dep[u])
    if(v == id[u])
      upd(g[u],f[h[v]],g[h[v]],val(h[v]) + dep[g[u]] - dep[u] * 2);
    else
      upd(f[u],f[h[v]],g[h[v]],val(h[v]) + dep[f[u]] - dep[u] * 2);
    if(val(h[v]) > val(h[u])){
      h[u] = h[v];
    }
    #undef val
  }
}
int main(){
  scanf("%d",&n);
  for(int i = 1;i < n;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(1,0);
  dfs2(1,0);
  if(a == b || a == c){
    a = 1;
    if(b == 1 || c == 1) a++;
    if(b == 2 || c == 2) a++;
  }
  if(b == c){
    b = 1;
    if(a == 1 || c == 1) b++;
    if(a == 2 || c == 2) b++;
  }
  printf("%d\n%d %d %d\n",ans,a,b,c);
  return 0;
}