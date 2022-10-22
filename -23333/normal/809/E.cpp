#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
const int mo=1e9+7;
int a[N],head[N],dfn[N],cnt,p[N],pos[N],q[N],bz[20][N],dep[N];
int f[N],phi[N],pri[N],prinum,ispri[N],n,l,miu[N],inv2;
bool tt[N];
struct re{
  int a,b,c;
}e[N*2];
int fsp(int x,int y)
{
  ll ans=1;
  while (y)
  {
    if (y&1) ans=ans*x%mo;
    x=1ll*x*x%mo; y>>=1; 
  }
  return ans;
}
IL void plu(int &x,int y)
{
  x=(x+y)%mo;
}
IL void arr(int x,int y)
{
  e[++l].a=head[x];
  e[l].b=y;
  head[x]=l;
}
void dfs(int x,int y)
{
  dfn[x]=++cnt; bz[0][x]=y; dep[x]=dep[y]+1;
  for (rint u=head[x];u;u=e[u].a)
  {
    int v=e[u].b;
    if (v!=y) dfs(v,x);
  }
}
bool cmp(int x,int y)
{
  return dfn[x]<dfn[y];
}
int lca(int x,int y)
{
  if (dep[x]<dep[y]) swap(x,y);
  dep(i,19,0) if (dep[bz[i][x]]>=dep[y]) x=bz[i][x];
  if (x==y) return x;
  dep(i,19,0) if (bz[i][x]!=bz[i][y]) x=bz[i][x],y=bz[i][y];
  return bz[0][x];
}
ll pp;
struct E{
  int l,head[N],ans[N];
  re e[N*2];
  IL void arr(int x,int y)
  {
    e[++l].a=head[x];
    e[l].b=y;
    e[l].c=x;
    head[x]=l;
  }
  IL void clear()
  {
    rep(i,1,l) head[e[i].c]=0;
    l=0;
  }
  void dfs(int x)
  {
    ans[x]=phi[a[x]];
    if (!tt[x])
    {
      ans[x]=0;
    }
    ll ans2=0;
    for (rint u=head[x];u;u=e[u].a)
    {
      int v=e[u].b;
      dfs(v);
      ans[x]=(ans[x]+ans[v])%mo; 
      ans2+=1ll*ans[v]*ans[v];
    }
    ans2=(1ll*ans[x]*ans[x]-ans2)%mo;
    pp=(pp+2*dep[x]*ans2)%mo;
  }
}E;
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  rep(i,1,n) cin>>a[i],pos[a[i]]=i;
  rep(i,1,n-1)
  {
    int x,y;
    cin>>x>>y;
    arr(x,y); arr(y,x);
  }
  dfs(1,0);
  rep(i,1,19)
    rep(j,1,n)
      bz[i][j]=bz[i-1][bz[i-1][j]];
  miu[1]=1; phi[1]=1;
  rep(i,2,n)
  {
    if (!ispri[i]) {pri[++prinum]=i; miu[i]=-1; phi[i]=i-1;}
    for (int j=1;j<=prinum&&pri[j]*i<=n;j++)
    {
      ispri[i*pri[j]]=1;
      if (i%pri[j]==0)
      {
        miu[i*pri[j]]=0;
        phi[i*pri[j]]=phi[i]*pri[j];
        break;
      } else miu[i*pri[j]]=-miu[i],phi[i*pri[j]]=phi[i]*(pri[j]-1);
    }
  }
  rep(i,1,n)
  {
    int num=0;
    int ans=0;
    ll ans2=0;
    for (int j=1;j*i<=n;j++) p[++num]=pos[i*j],plu(ans,phi[i*j]);
    rep(j,1,num) ans2=(ans2+1ll*phi[i*j]*dep[p[j]])%mo;
    ans2=2ll*ans2*ans%mo; 
    sort(p+1,p+num+1,cmp);
    rep(i,1,num) tt[p[i]]=1;
    int h=1,t=1; q[h]=1;
    rep(i,1,num)
    {
      while (h<t&&dep[lca(p[i],q[t])]<=dep[q[t-1]])
      {
        E.arr(q[t-1],q[t]); t--;
      }
      int k=lca(p[i],q[t]);
      if (k!=q[t])
      {
        E.arr(k,q[t]); q[t]=k;
      }
      if (q[t]!=p[i]) q[++t]=p[i];
    }
    while (h<t)
    {
      E.arr(q[t-1],q[t]); t--;
    }
    pp=0;
    E.dfs(1);
    ans2=((ans2-pp)%mo+mo)%mo;
    f[i]=ans2;
    E.clear();
    rep(i,1,num) tt[p[i]]=0; 
  }
  ll ans2=0;
  rep(k,1,n)
  {
     int ans=0;
     for (int j=1;j*k<=n;j++)
     {
        plu(ans,miu[j]*f[j*k]);
     }
     ans2=(ans2+1ll*k*ans%mo*fsp(phi[k],mo-2))%mo;
  }
  cout<<ans2*fsp(n,mo-2)%mo*fsp(n-1,mo-2)%mo<<endl;
  return 0;
}