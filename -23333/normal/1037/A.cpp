#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,h,t) for (ll i=h;i<=t;i++)
int f[1000000];
int main()
{
  ios::sync_with_stdio(false);
  ll n;
  cin>>n;
  if (n==1)
  {
    cout<<1<<endl;
    exit(0);
  }
  f[1]=1;
  ll ans=0;
  rep(i,1,n)
  {
    f[i]=ans+1;
    ans+=f[i];
    if (ans>=n)
    { 
      cout<<i<<endl;
      exit(0);
    }
  }
  return 0;
}