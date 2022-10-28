#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N], f[5];

int32_t main()
{
   IOS;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
      f[a[i]]++;
   }
   int min1=min(f[1], f[2]);
   int ans=min1;
   f[1]-=min1;
   ans+=f[1]/3;
   cout<<ans;
   return 0;
}