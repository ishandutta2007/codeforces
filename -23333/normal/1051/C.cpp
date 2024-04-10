#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=h;i--)
struct re{
  int a,b;
}a[200];
vector<int> ve[200];
bool f[105][105][105];
int pre[105][105][105],ans[200];
int c[200];
bool cmp(re x,re y)
{
  return x.a<y.a;
}
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  rep(i,1,n) cin>>a[i].a,a[i].b=i;
  sort(a+1,a+n+1,cmp);
  a[0].a=1e9;
  int cnt=0;
  rep(i,1,n)
  {
    if (a[i].a!=a[i-1].a) c[++cnt]=1;
    else c[cnt]++;
    ve[cnt].push_back(a[i].b);
  }
  f[0][0][0]=1;
  rep(i,0,cnt-1)
    rep(j,0,cnt)
      rep(k,0,cnt)
        if (f[i][j][k])
        {
          if (c[i+1]==1)
          {
            f[i+1][j][k+1]=1,pre[i+1][j][k+1]=3;
            f[i+1][j+1][k]=1,pre[i+1][j+1][k]=2;
          }
          if (c[i+1]==2)
          {
            f[i+1][j][k]=1; pre[i+1][j][k]=1;
          }
          if (c[i+1]>2)
          {
            f[i+1][j][k+1]=1,pre[i+1][j][k+1]=5;
            f[i+1][j+1][k]=1,pre[i+1][j+1][k]=4;
            f[i+1][j][k]=1,pre[i+1][j][k]=6;
          }
       }
  int tmp=-1;
  rep(i,0,cnt)
    if (f[cnt][i][i])
    {
      tmp=i; break;
    }
  if (tmp==-1)
  {
    cout<<"NO"<<endl;
    exit(0);
  }
  int x1=tmp,x2=tmp;
  dep(i,cnt,1)
  {
    int t=pre[i][x1][x2];
    if (t==6)
    {
      int l1=(int)(ve[i].size())-1;
      rep(j,0,l1) ans[ve[i][j]]=0;
    }
    if (t==5)
    {
      int l1=(int)(ve[i].size())-1;
      rep(j,1,l1) ans[ve[i][j]]=0;
      ans[ve[i][0]]=1;
      x2--;
    }
    if (t==4)
    {
      int l1=(int)(ve[i].size())-1;
      rep(j,1,l1) ans[ve[i][j]]=1;
      ans[ve[i][0]]=0;
      x1--; 
    }
    if (t==3)
    {
      ans[ve[i][0]]=1;
      x2--;
    }
    if (t==2)
    {
      ans[ve[i][0]]=0;
      x1--;
    }
  }
  cout<<"YES"<<endl;
  rep(i,1,n) if (ans[i]) cout<<"A"; else cout<<"B";
  return 0; 
}