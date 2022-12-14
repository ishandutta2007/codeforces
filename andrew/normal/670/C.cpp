#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll MaxN=200001;
ll a[200001],l,r,n,m,i,x,j,k,sc,b[200001],c[200001],mxc,mxl,mxj;
int DIH(ll x)
{
    ll l=1; r=n-1;
    a[n+1]=1e18;
    while(l<r)
    {
        ll c=(l+r)/2;
        if(x<=a[c])r=c; else l=c+1;
    }
    while(a[l]<x)l++;
    return l;
}
int main ()
{
  ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n;
   for(i=1;i<=n;i++)cin >> a[i];
   sort(a+1,a+n+1);
   cin >> m;
   mxc=-1e18;
   for(i=0;i<m;i++)cin >> b[i];
   for(i=0;i<m;i++)cin >> c[i];
   //cout << DIH(2) << " " << DIH(1) << endl;
   for(i=0;i<m;i++)
   {
      // ll x=a[i]+1;
      ll cc=(DIH(b[i]+1)-DIH(b[i]));
     // x=b[i]+1;
       x=(DIH(c[i]+1)-DIH(c[i]));
      //cout << cc  <<  " " << x <<  " " << i << endl;
      if(cc>mxc or (cc==mxc and x>mxl))
      {
          mxj=i;
          mxc=cc;
          mxl=x;
      }
   }
   cout << mxj+1 << endl;
 return 0;
}