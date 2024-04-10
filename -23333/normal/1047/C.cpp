#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (rint i=h;i<=t;i++)
#define dep(i,t,h) for (rint i=t;i>=h;i--)
const int N=1e6;
const int N2=2e7;
int a[N],b[N2];
bool f[N2];
int gcd(int x,int y)
{
  if (!y) return(x); else return(gcd(y,x%y));
}
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int ans=0;
  rep(i,1,n) cin>>a[i],ans=gcd(a[i],ans);
  int maxa=0;
  rep(i,1,n) a[i]/=ans,b[a[i]]++,maxa=max(maxa,a[i]);
  int ans2=0;
  rep(i,2,maxa)
  {
    int ans=b[i];
    if (!f[i])
      for (int j=2;j*i<=maxa;j++)
        f[i*j]=1,ans+=b[j*i];
    ans2=max(ans,ans2);
  }
  if (!ans2) cout<<-1<<endl;
  else cout<<n-ans2<<endl;
  return 0;
}