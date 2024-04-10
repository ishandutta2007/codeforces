#include<bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int mo=998244353;
int main()
{
  int n;
  cin>>n;
  ll ans=1,ans2=0;
  dep(i,n,2)  ans=ans*i%mo,ans2=(ans2-ans)%mo;
  ans2=(ans2+ans*n%mo)%mo;
  cout<<(ans2+mo)%mo<<endl;
  return 0;
}