#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=4e5;
int a[N],n,fa[N],head[N],l,cnt,dp[N];
bool f[N];
struct re{
  int a,b;
}e[N*2];
void arr(int x,int y)
{
  e[++l].a=head[x];
  e[l].b=y;
  head[x]=l;
}
void dfs(int x)
{
  bool tt=0;
  for (rint u=head[x];u;u=e[u].a)
  {
    tt=1;
    int v=e[u].b;
    dfs(v);
  }
  if (!tt) f[x]=1,cnt++;
}
void dfs2(int x,int y)
{
  if (f[x])
  {
    dp[x]=1; return;
  }
  if (a[x]==1)
  {
    dp[x]=1e9;
    for (rint u=head[x];u;u=e[u].a)
    {
      int v=e[u].b;
      dfs2(v,0);
      dp[x]=min(dp[x],dp[v]); 
    }
  } else
  {
    dp[x]=0;
    for (rint u=head[x];u;u=e[u].a)
    {
      int v=e[u].b;
      dfs2(v,0);
      dp[x]+=dp[v];
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  // 1-max 0-min
  rep(i,1,n) cin>>a[i];
  rep(i,2,n) cin>>fa[i],arr(fa[i],i);
  dfs(1);
  dfs2(1,0);
  cout<<cnt-dp[1]+1<<endl;
  return 0;
}