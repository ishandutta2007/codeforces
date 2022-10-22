#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=6000;
int a[N],f[N][N],b[N];
void mina(int &x,int y)
{
  if (x>y) x=y;
}
int main()
{
  int n;
  cin>>n;
  rep(i,1,n)
  {
    cin>>a[i];
  }
  int m=0;
  rep(i,1,n)
    if (a[i]!=a[i-1]) b[++m]=a[i];
  n=m;
  memcpy(a,b,sizeof(b)); 
  rep(i,2,n)
    rep(j,1,n-i+1)
    {
      f[j][j+i-1]=min(f[j][j+i-2],f[j+1][j+i-1])+1;
      if (a[j]==a[j+i-1]) mina(f[j][j+i-1],f[j+1][j+i-2]+1);
    }
  cout<<f[1][n];
  return 0; 
}