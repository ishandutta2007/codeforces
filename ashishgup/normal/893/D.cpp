#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, d, cur=0, ans=0, extra=0;
int a[N], b[N], suf[N];

int32_t main()
{
   IOS;
   cin>>n>>d;
   suf[n+1]=-1e15;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
      cur+=a[i];
      if(cur>d)
      {
         cout<<"-1";
         return 0;
      }
      b[i]=cur;
   }
   for(int i=n;i>=1;i--)
   {
      suf[i]=max(suf[i+1], b[i]);
   }
   for(int i=1;i<=n;i++)
   {
      if(a[i]==0)
      {
         if(b[i-1]+extra<0)
         {
            int reqd=abs(b[i-1]+extra);
            int maxdeposit=d-(suf[i-1]+extra);
            if(reqd>maxdeposit)
            {
               cout<<"-1";
               return 0;
            }
            ans++;
            extra+=maxdeposit;
         }
      }
   }
   cout<<ans;
}