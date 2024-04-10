#include <bits/stdc++.h>
using namespace std;
#define rint register rint
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
int n,m,k;
const int N=200;
int a[N],b[N],f[N][N],g[N][N];
bool t[N];
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>m>>k;
  rep(i,1,m) cin>>a[i];
  rep(i,1,n) cin>>b[i];
  rep(i,1,n)
    rep(j,1,m)
      cin>>f[i][j];
  rep(i,1,n)
  {
    rep(j,1,m) if (f[i][j]&&a[j]>=b[i]) g[i][j]=b[i]; 
    else if (f[i][j]) g[i][j]=a[j];
  }
  rep(i,1,n) 
  {
    rep(j,1,m)
      cout<<g[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}