#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rint register int
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=h;i--)
#define mid ((h+t)>>1)
const int mo=1e9+7;
const int N=2e6;
ll a[N],sum[N],ans;
int nxt[N],pre[N];
struct re{
  int a,b;
}ve[N];
int main()
{
  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  rep(i,1,n) cin>>a[i];
  int k=0;
  rep(i,1,n)
  {
    while (m*k-k+1<=i) k++;
    sum[i]=(sum[i-1]+k-1)%mo;
  }
  int t=0;
  rep(i,1,n)
  {
    while (t&&ve[t].a<a[i]) 
    {
      nxt[ve[t].b]=i-1;
      t--;
    }
    t++; ve[t].a=a[i]; ve[t].b=i;
  }
  while (t)
  {
    nxt[ve[t].b]=n;
    t--;
  }
  dep(i,n,1)
  {
    while (t&&ve[t].a<=a[i])
    {
      pre[ve[t].b]=i+1;
      t--;
    }
    t++; ve[t].a=a[i]; ve[t].b=i;
  }
  while (t)
  {
    pre[ve[t].b]=1;
    t--;
  }
  rep(i,1,n)
  {
    ans+=(sum[nxt[i]-pre[i]+1]-sum[nxt[i]-i+1-1]-sum[i-pre[i]+1-1])*a[i];
    ans%=mo;
  }
  cout<<(ans+mo)%mo<<endl;
  return 0; 
}