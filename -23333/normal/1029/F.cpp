#include <bits/stdc++.h>
#define rint register int 
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=t;i--) 
#define ll long long
using namespace std;
const int N=3e6;
struct re{
  ll a,b;
} a[N+10],b[N+10];
int cnt1,cnt2;
ll x,y,z;
int main()
{
  ios::sync_with_stdio(false);
  cin>>x>>y;
  z=x+y;
  for (rint i=1;1ll*i*i<=x;i++)
    if (!(x%i)) a[++cnt1].a=x/i,a[cnt1].b=i;
  reverse(a+1,a+cnt1+1);
  for (rint i=1;1ll*i*i<=y;i++)
    if (!(y%i)) b[++cnt2].a=y/i,b[cnt2].b=i;
  reverse(b+1,b+cnt2+1); 
  ll ans=1e18;
  for (rint i=1;1ll*i*i<=z;i++)
    if (!(z%i))
    {
      ll x=z/i,y=i;
      for (;cnt1;cnt1--) if (a[cnt1].a<=x) break;
      if (cnt1&&a[cnt1].b<=y) ans=min(ans,(x+y)*2);
      for (;cnt2;cnt2--) if (b[cnt2].a<=x) break;
      if (cnt2&&b[cnt2].b<=y) ans=min(ans,(x+y)*2);
    }
  cout<<ans<<endl;
  return 0;
}