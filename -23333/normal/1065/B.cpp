#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int main()
{
  ios::sync_with_stdio(false);
  ll n,m;
  cin>>n>>m;
  if (m>=(n+1)/2)
  {
    cout<<0<<" ";
  } else
  {
    cout<<n-m*2<<" ";
  }
  rep(i,0,n)
    if (1ll*i*(i-1)/2>=m)
    {
      cout<<n-i<<" ";
      return 0;
    }
  return 0;
}