#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second

const int N=1e5+5;

int n;
pair<int, int> a[N];

int32_t main()
{
   IOS;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i].ff>>a[i].ss;
   }
   int ans=0;
   for(int i=1;i<=n;i++)
   {
      if(a[i].ss==1)
         ans=max(ans, a[i].ff+1);
      while(a[i].ss>1)
      {
         a[i].ss=(a[i].ss+3)/4;
         a[i].ff++;
         ans=max(ans, a[i].ff);
      }
   }
   cout<<ans;
}