#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, d;
int a[N];

int32_t main()
{
   IOS;
   cin>>n>>d;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
   }
   int ans=0, l=1;
   for(int r=1;r<=n;r++)
   {
      while(a[r]-a[l]>d)
         l++;
      int len=r-l;
      ans+=len*(len-1)/2;
   }
   cout<<ans;
   return 0;   
}