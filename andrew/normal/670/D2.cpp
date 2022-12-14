#include <bits/stdc++.h>
#define ll unsigned long long
#define endl "\n"
using namespace std;
ll a[100001],l,r,sc,cc,b[100001],mxc,mxl,mxj,ans;
long long x,k;
int i,j,n,m;
int main ()
{
  ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n >> k;
   for(i=0;i<n;i++)cin >> a[i];
   for(i=0;i<n;i++)cin >> b[i];
   l=0;r=1e10;
   ans=0;
   while(l<=r)
   {
        cc=(l+r)/2;
        x=k;
       //ut << a[0]*cc << endl;
       for(i=0;i<n;i++)if((a[i]*cc)>b[i]){ if((a[i]*cc)-b[i]>x){x=-1;break;} x-=((a[i]*cc)-b[i]);}
       if(x>=0)if(ans<cc)ans=cc;
      // cout << l  << " " << r << " " << cc << " " << x << endl;
       if(x>=0)l=cc+1; else r=cc-1;
   }
   cout << ans << endl;
}