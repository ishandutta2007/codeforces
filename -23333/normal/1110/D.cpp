#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define rint register int
#define IL inline
#define mep(x,y) memcpy(x,y,sizeof(y))
const int N=2e6;
const int M=1e6;
const int INF=1e9;
int a[N],b[N],n,m;
int f[N][5][5];
template <class T> IL void maxa(T &x,T y){ if(x<y) x=y;}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>m;
  rep(i,1,n) cin>>a[i],b[a[i]]++;
  rep(i,0,m)
    rep(j,0,4)
      rep(k,0,4)
        f[i][j][k]=-INF;
  f[0][0][0]=0;
  mep(a,b);
  rep(i,1,m)
  {
    rep(j,0,4)
      rep(k,0,4)
        rep(j1,0,4)
          rep(k1,0,4)
            if (j1>=k&&a[i]>=j)
            {
              int p=min(a[i]-j,min(k1,j1-k));
              maxa(f[i][j][k],f[i-1][j1][k1]+p+(a[i]-j-p)/3);
            }
  }
  int mm=0;
  rep(i,0,4)
    rep(j,0,4)
      maxa(mm,f[m][i][j]);
  cout<<mm<<endl;
  return 0; 
}