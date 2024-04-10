#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long 
const int N=3e5;
struct re{
  int a,b;
}a[N];
int t[N];
bool cmp(re x,re y)
{
  return x.a>y.a;
}
int main()
{
  ios::sync_with_stdio(false);
  int n,m,k;
  cin>>n>>m>>k;
  rep(i,1,n) cin>>a[i].a,a[i].b=i;
  sort(a+1,a+n+1,cmp);
  ll ans=0;
  rep(i,1,m*k) t[a[i].b]=1,ans+=a[i].a;
  int cnt=0;
  cout<<ans<<endl;
  int cnt1=0;
  rep(i,1,n)
  {
    cnt+=t[i];
    if (cnt==m&&cnt1<k-1) 
    {
      cnt1++;
      cout<<i<<" ";
      cnt=0;
    }
  }
  return 0;
}