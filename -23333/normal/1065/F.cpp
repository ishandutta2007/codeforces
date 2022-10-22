#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define mid ((h+t)>>1) 
const int N=1.1e6;
const int INF=1e9;
int head[N],l,n,k;
int bz[21][N],dfn[N],num[N],dy[N],cnt,p[N],ans[N];
bool t[N];
struct re{
  int a,b;
}e[N*2];
IL void arr(int x,int y)
{
  e[++l].a=head[x];
  e[l].b=y;
  head[x]=l;
}
void dfs(int x,int y)
{
  bz[0][x]=y; dfn[x]=++cnt; num[x]=1; dy[cnt]=x;
  for (rint u=head[x];u;u=e[u].a)
  {
    int v=e[u].b;
    if (v!=y)
    { 
      dfs(v,x);
      num[x]+=num[v];
    }
  }
}
IL int js(int x)
{
  int k1=k;
  dep(i,20,0)
  if (k1>(1<<i)) 
  {
    x=bz[i][x]; k1-=(1<<i);
  }
  x=bz[0][x];
  if (x) return x; else return 1;
}
struct sgt{
  int v[N*4];
  sgt() { rep(i,0,N*4-1) v[i]=INF;}
  void change(int x,int h,int t,int pos,int k)
  {
    v[x]=min(v[x],k);
    if (h==t) return;
    if (pos<=mid) change(x*2,h,mid,pos,k);
    else change(x*2+1,mid+1,t,pos,k);
  }
  int query(int x,int h,int t,int h1,int t1)
  {
    if (h1<=h&&t<=t1)
    {
      return v[x];
    }
    int ans=INF;
    if (h1<=mid) ans=query(x*2,h,mid,h1,t1);
    if (mid<t1) ans=min(ans,query(x*2+1,mid+1,t,h1,t1));
    return ans; 
  }
}S;
queue<int> q;
void bfs()
{
  q.push(1); S.change(1,1,n,1,1);
  while (!q.empty())
  {
    int x=q.front(); q.pop();
    if (!t[x])
    { 
      int tmp=S.query(1,1,n,dfn[p[x]],dfn[p[x]]+num[p[x]]-1);
      tmp=min(tmp,dfn[p[x]]);
      ans[dy[tmp]]++;
      S.change(1,1,n,dfn[x],tmp);
    }
    for (rint u=head[x];u;u=e[u].a)
    {
      int v=e[u].b;
      if (v!=bz[0][x]) q.push(v);
    }
  }
}
void dfs2(int x,int y)
{
  ans[x]+=ans[y];
  for (rint u=head[x];u;u=e[u].a)
  {
    int v=e[u].b;
    if (v!=y) dfs2(v,x);
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>k;
  rep(i,2,n)
  {
    int x;
    cin>>x; t[x]=1;
    arr(x,i);
  }
  dfs(1,0);
  rep(i,1,20)
    rep(j,1,n)
      bz[i][j]=bz[i-1][bz[i-1][j]];
  rep(i,1,n) p[i]=js(i);
  bfs();
  dfs2(1,0);
  int ansa=0; 
  rep(i,1,n) if (ans[i]>ansa) ansa=ans[i];
  cout<<ansa<<endl;
  return 0;
}