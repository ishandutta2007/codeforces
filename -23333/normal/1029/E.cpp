#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=h;i--)
const int N=3e5;
int n,head[N],l,af[N];
bool f[N];
struct re{
  int a,b;
}a[N*2],len[N];
void arr(int x,int y)
{
  a[++l].a=head[x];
  a[l].b=y;
  head[x]=l;
}
void dfs(int x,int fa)
{
  af[x]=fa;
  len[x].a=len[fa].a+1; len[x].b=x;
  if (len[x].a<=3) f[x]=1;
  for (rint u=head[x];u;u=a[u].a)
  {
    int v=a[u].b;
    if (v!=fa) dfs(v,x);
  }
}
bool cmp(re x,re y)
{
  return(x.a>y.a);
}
void dfs2(int x)
{
  f[x]=1;
  for (rint u=head[x];u;u=a[u].a)
  {
    int v=a[u].b;
    f[v]=1;
  }
}
int main()
{
  cin>>n;
  rep(i,1,n-1)
  {
    int x,y;
    cin>>x>>y;
    arr(x,y); arr(y,x);
  }
  dfs(1,0);
  sort(len+1,len+n+1,cmp);
  int ans=0;
  rep(i,1,n)
    if (!f[len[i].b]) ans++,dfs2(af[len[i].b]);
  cout<<ans<<endl;
  return 0;
}