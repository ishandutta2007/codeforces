#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=2e5;
int a[N],b[N];
int main()
{
  ios::sync_with_stdio(false);
  int n,m,k;
  cin>>n>>m>>k;
  rep(i,1,n)
  { 
    cin>>a[i];
  }
  int ans=a[n]-a[1]+1;
  rep(i,1,n-1)
    b[i]=a[i+1]-a[i]-1;
  n--;
  sort(b+1,b+n+1);
  reverse(b+1,b+n+1);
  rep(j,1,k-1) ans-=b[j];
  cout<<ans<<endl;
  return 0; 
}