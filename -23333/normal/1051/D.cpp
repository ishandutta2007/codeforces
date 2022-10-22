#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=h;i--)
const int N=1010;
const int INF=1e9;
const int mo=998244353;
int f[N][2*N][4];
IL void js (rint &x,rint y)
{
  x+y>mo?x=x+y-mo:x=x+y;
}
int main()
{
  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  f[1][0][0]=f[1][0][1]=f[1][0][2]=f[1][0][3]=1;
  rep(i,1,n-1)
  {
    rep(j,0,m)
    {
      rep(k,0,3)
        if (f[i][j][k])
          rep(k1,0,3)
          {
            int cnt=0;
            int x1=(k>>1)&1,x2=k&1;
            int x3=(k1>>1)&1,x4=k1&1;
            if (x2==x4&&x1==x3) cnt=0;
            else if ((x2==x4&&x1!=x3)||(x1==x3&&x2!=x4))
            {
              if (x1==x2) cnt=0; else cnt=1;
            }
            else if (x1==x2) cnt=1;
            else cnt=2;
            js(f[i+1][j+cnt][k1],f[i][j][k]);
          }
    }
  }
  int ans=0;
  rep(k,0,3)
  {
    int cnt=0;
    int x1=(k>>1)&1,x2=k&1;
    if (x1==x2) cnt=1; else cnt=2;
    if (cnt<=m) js(ans,f[n][m-cnt][k]);
  }
  cout<<ans<<endl;
  return 0;
}