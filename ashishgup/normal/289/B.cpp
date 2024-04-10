#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e4+5;

int n, m, d, ans=0;
int a[N];

int32_t main()
{
   IOS;
   cin>>n>>m>>d;
   n*=m;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
   }
   sort(a+1, a+n+1);
   for(int i=2;i<=n;i++)
   {
      if((a[i]-a[i-1])%d!=0)
      {
         cout<<"-1";
         return 0;
      }
   }
   int median=a[n/2 + 1];
   for(int i=1;i<=n;i++)
   {
      ans+=abs(a[i]-median);
   }
   ans/=d;
   cout<<ans;
}