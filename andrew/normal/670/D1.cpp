#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll MaxN=200001;
ll a[200001],l,r,n,m,i,j,k,sc,b[200001],c[200001],mxc,mxl,mxj,ans;
int main ()
{
  ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n >> k;
   for(i=0;i<n;i++)cin >> a[i];
   for(i=0;i<n;i++)cin >> b[i];
   l=0;r=1e9;
   ans=-1e18;
   while(l<r)
   {
       ll cc=(l+r)/2;
       for(i=0;i<n;i++)c[i]=a[i]*cc;
       ll x=k;
       for(i=0;i<n;i++)if(c[i]>b[i])x-=(c[i]-b[i]);
       if(x>=0)if(ans<cc)ans=cc;
       if(x>=0)l=cc+1; else r=cc;
   }
   cout << ans << endl;
}