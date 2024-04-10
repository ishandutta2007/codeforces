#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=20;
int a[N][N],f[500][500],f1[500][500],g[500][4],g1[500][4],n;
IL int js(int x,int y,int z)
{
  return ((x-1)*n+y-1)*3+z;
}
IL void cl(int x,int y,int z)
{
  f[x][y]=f[y][x]=f[x][z]=f[z][x]=f[y][z]=f[z][y]=1;
  f1[x][y]=f1[y][x]=f1[x][z]=f1[z][x]=f1[y][z]=f1[z][y]=1;
}
IL void mina(int &x,int y)
{
  if (x>y) x=y;
}
IL bool pd(int x,int y)
{
  if (x>=1&&x<=n&&y>=1&&y<=n) return 1; else return 0;
}
struct re{
  int a,b;
}pos[10000];
IL void lb(int x,int y)
{
  f[x][y]=1; f1[x][y]=0;
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  rep(i,1,n)
    rep(j,1,n)
    {
      cin>>a[i][j];
      pos[a[i][j]]=(re){i,j};
    }
  rep(i,0,499)
    rep(j,0,499)
      f[i][j]=1e9,f1[i][j]=1e9;
  rep(i,1,n)
    rep(j,1,n)
    {
      rep(k,1,n) lb(js(i,j,1),js(k,j,1));
      rep(k,1,n) lb(js(i,j,1),js(i,k,1));
      rep(k,1,n) if (pd(i+k,j+k)) lb(js(i,j,2),js(i+k,j+k,2));
      rep(k,1,n) if (pd(i-k,j-k)) lb(js(i,j,2),js(i-k,j-k,2));
      rep(k,1,n) if (pd(i-k,j+k)) lb(js(i,j,2),js(i-k,j+k,2));
      rep(k,1,n) if (pd(i+k,j-k)) lb(js(i,j,2),js(i+k,j-k,2)); 
      if (pd(i+2,j+1)) lb(js(i,j,3),js(i+2,j+1,3));
      if (pd(i+1,j+2)) lb(js(i,j,3),js(i+1,j+2,3));
      if (pd(i-1,j+2)) lb(js(i,j,3),js(i-1,j+2,3));
      if (pd(i-2,j+1)) lb(js(i,j,3),js(i-2,j+1,3));
      if (pd(i+2,j-1)) lb(js(i,j,3),js(i+2,j-1,3));
      if (pd(i+1,j-2)) lb(js(i,j,3),js(i+1,j-2,3));
      if (pd(i-1,j-2)) lb(js(i,j,3),js(i-1,j-2,3));
      if (pd(i-2,j-1)) lb(js(i,j,3),js(i-2,j-1,3));
      cl(js(i,j,1),js(i,j,2),js(i,j,3));
    }
  int m=n*n*3;
  rep(i,1,m)
    rep(j,1,m)
      rep(k,1,m)
      {
        if (f[j][i]+f[i][k]==f[j][k]&&f1[j][i]+f1[i][k]<f1[j][k])
        {
          f1[j][k]=f1[j][i]+f1[i][k];
        }
        if (f[j][i]+f[i][k]<f[j][k])
        {
          f[j][k]=f[j][i]+f[i][k];
          f1[j][k]=f1[j][i]+f1[i][k];
        }
      }
  g[1][1]=g[1][2]=g[1][3]=0;
  rep(i,2,n*n)
  {
    g[i][1]=g[i][2]=g[i][3]=g1[i][1]=g1[i][2]=g1[i][3]=1e9;
    rep(i1,1,3)
      rep(j1,1,3)
      {
        int tmp=g[i-1][i1]+f[js(pos[i-1].a,pos[i-1].b,i1)][js(pos[i].a,pos[i].b,j1)];
        int tmp2=g1[i-1][i1]+f1[js(pos[i-1].a,pos[i-1].b,i1)][js(pos[i].a,pos[i].b,j1)];
        if (tmp==g[i][j1]&&tmp2<g1[i][j1])
        {
          g1[i][j1]=tmp2;
        }
        if (tmp<g[i][j1])
        {
          g[i][j1]=tmp; g1[i][j1]=tmp2;
        }
      }
  }
  ll k1=1ll*g[n*n][1]*1e9+g1[n*n][1];
  ll k2=1ll*g[n*n][2]*1e9+g1[n*n][2];
  ll k3=1ll*g[n*n][3]*1e9+g1[n*n][3];
  if (k1<=k2&&k1<=k3)
  {
    cout<<g[n*n][1]<<" "<<g1[n*n][1]<<endl;
    return 0;
  }
  if (k2<=k1&&k2<=k3)
  {
    cout<<g[n*n][2]<<" "<<g1[n*n][2]<<endl;
    return 0; 
  }
  if (k3<=k1&&k3<=k2)
  {
    cout<<g[n*n][3]<<" "<<g1[n*n][3]<<endl;
    return 0; 
  }
  return 0;
}