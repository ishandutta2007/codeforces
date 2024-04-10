#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+5;

int n;
int a[N];

int32_t main()
{
   IOS;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
   }
   int ans=1;
   int index=n-1;
   int cur=a[n];
   while(index>=1)
   {
      if(cur>0)
      {
         cur--;
         cur=max(cur, a[index]);
         index--;
      }
      else if(cur==0)
      {
         cur=a[index];
         index--;
         ans++;
      }
   }
   cout<<ans;
}