// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N=300005;
bool vis[N];int s=0;
int dep[N],fa[N],w[N],fd[N];
vector<int>adj[N],a1[N],a2[N];
int ru[N],rv[N];
int n,m,q;

void dfs1(int u){
  vis[u]=true;for(auto i:adj[u]){
    int v=u^ru[i]^rv[i];
    if(!vis[v]){
      dep[v]=dep[u]+1;
      fa[v]=u,fd[v]=i;
      dfs1(v);
    }
  }
}
void dfs2(int u,int h){
  for(auto i:adj[u]){
    int v=u^ru[i]^rv[i];
    if(fa[v]!=u)continue;
    if(w[fd[v]]){
      if(h){
        h=0;
        dfs2(v,1);
      }else{
        s++;
        h=1;
        dfs2(v,1);
      }
    }else{
      dfs2(v,0);
    }
  }
}
int main() {
  n = read(), m = read();
  rep(i,1,m){
    ru[i]=read(),rv[i]=read();
    adj[ru[i]].pb(i);
    adj[rv[i]].pb(i);
  }
  dfs1(1);
  q=read();
  rep(i,1,q){
    int u=read(),v=read();
    while(u!=v){
      if(dep[u]>dep[v]){
        a1[i].pb(u);
        w[fd[u]]^=1;
        u=fa[u];
      }else{
        a2[i].pb(v);
        w[fd[v]]^=1;
        v=fa[v];
      }
    }
    a1[i].pb(u);
  }
  bool tag=true;
  rep(i,1,m)if(w[i])tag=false;
  if(tag){
    puts("YES");
    rep(i,1,q){
      printf("%d\n",SZ(a1[i])+SZ(a2[i]));
      for(auto v:a1[i])printf("%d ",v);
      reverse(a2[i].begin(),a2[i].end());
      for(auto v:a2[i])printf("%d ",v);
      puts("");
    }
  }else{
    puts("NO");
    dfs2(1,0);
    print(s,'\n');
  }
  return 0;
}