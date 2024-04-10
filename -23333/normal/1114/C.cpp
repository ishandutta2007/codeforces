#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define ll long long
ll cnt;
ll b[10000],c[10000];
int main()
{
  
  ios::sync_with_stdio(false);
  ll n,m; 
  cin>>n>>m;
  ll k=sqrt(m);
  rep(i,2,k)
  {
    if (m%i==0)
    {
      b[++cnt]=i;
      while (m%i==0)
      {
        m/=i; c[cnt]++;
      }
    }
  }
  if (m!=1) b[++cnt]=m,c[cnt]++;
  ll ans=1e18;
  rep(i,1,cnt)
  {
    ll k=b[i];
    ll num=0;
    while (1)
    {
      num+=n/k;
      if (n/b[i]>=k) k=k*b[i]; 
      else break;
    }
    ans=min(num/c[i],ans);
  }
  cout<<ans<<endl;
  return 0;
}