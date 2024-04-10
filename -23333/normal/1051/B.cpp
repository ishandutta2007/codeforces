#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rint register ll
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=h;i--)
int main()
{
  ios::sync_with_stdio(false);
  ll n,m;
  cin>>n>>m;
  cout<<"YES"<<endl;
  for (ll i=n;i<=m;i+=2)
    cout<<i<<" "<<i+1<<endl;
  return 0;
}