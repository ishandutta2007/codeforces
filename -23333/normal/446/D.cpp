#include <bits/stdc++.h>
#define rint register int
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=h;i--)
using namespace std;
const int N=6e5;
const int N2=600;
int head[N2],v[N2],du[N2],l,n,m,k,M[N2][N2];
double o2[N2];
double f[N2][N2],jl[N2][N2];
double ee=1.00000000000000000;
struct re{
  int a,b;
}a[N*2]; 
void arr(int x,int y)
{
  a[++l].a=head[x];
  a[l].b=y;
  head[x]=l;
}
struct re1{
  double a[600][600];
  re1()
  {
    rep(i,0,n)
      rep(j,0,n) a[i][j]=0; 
  }
}o;
re1 z;
re1 js(re1 x,re1 y)
{
  memset(z.a,0,sizeof(z.a)); 
  rep(i,1,n)
    rep(j,1,n)
      if (x.a[i][j])
      rep(k,1,n)
        z.a[i][k]+=x.a[i][j]*y.a[j][k];
  return(z);
}
re1 y;
re1 o3;
re1 fsp(rint x)
{
  memset(y.a,0,sizeof(y.a));
  o3=o;
  rep(i,1,n) y.a[i][i]=1;
  while (x)
  {
    if (x&1) y=js(y,o3);
    x>>=1;
    o3=js(o3,o3);
  }
  return(y);
}
int ve[N2],cnt=0;
void Gauss()
{
  rep(i,1,n) jl[i][i]=1;
  rep(i,1,n)
  {
    rep(j,1,n)
      if (i!=j)
      {
        double t=-f[j][i]/f[i][i];
        rep(k,1,n) f[j][k]+=t*f[i][k];
        rep(k,1,n) jl[j][k]+=t*jl[i][k];
      }
  }
  rep(i,1,n)
    if (v[i])
    {
      cnt=0;
      double tmp=ee/du[i];
      rep(j,1,n)
        if (M[i][j]) ve[++cnt]=j;
      rep(k,1,n)
        if (v[k])
        {
          double ans=0;
          rep(j,1,cnt) ans+=M[i][ve[j]]*jl[k][ve[j]]*tmp;
          o.a[i][k]=ans;
        }
    }
  rep(j,1,n)
    if (v[j])
      o2[j]=jl[j][1];
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>m>>k;
  rep(i,1,n)
  { 
    cin>>v[i];
  }
  rep(i,1,m)
  {
    int x,y;
    cin>>x>>y;
    arr(x,y); arr(y,x);
    M[x][y]++; M[y][x]++;
    du[x]++; du[y]++;
  }
  rep(i,1,n)
  {
    f[i][i]=-1; 
    for (int u=head[i];u;u=a[u].a)
    {
      int vv=a[u].b;
      if (!v[vv]) f[i][vv]+=ee/du[vv];
    }
  }
  Gauss();
  double ans=0;
  if (k!=2)
  { 
    re1 ans2=fsp(k-2);
    rep(i,1,n)
      if (v[i]) ans+=o2[i]*ans2.a[i][n];
  } else
  if (k==2) ans=o2[n];
  else ans=0;
  printf("%.9f",ans);
  return 0;
}