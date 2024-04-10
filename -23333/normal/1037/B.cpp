#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rint register ll
#define rep(i,h,t) for (rint i=h;i<=t;i++) 
const ll N=3e5;
ll a[N],n,m,cnt;
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>m;
  rep(i,1,n) cin>>a[i];
  sort(a+1,a+n+1);
  rep(i,1,n) if (a[i]<=m) cnt++;
  ll k=(n+1)/2;
  ll ans=0;
  if (cnt>=k)
  {
    rep(i,k,cnt)
      ans+=m-a[i];
  } else
  {
    rep(i,cnt+1,k)
      ans+=a[i]-m;
  }
  cout<<ans<<endl;
  return 0; 
}