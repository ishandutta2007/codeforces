#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5e3+5;

int n, m;
int a[N];
int cache[N][N], vis[N][N];

int dp(int i, int section)
{
   if(i>n)
      return 0;
   if(vis[i][section])
      return cache[i][section];
   vis[i][section]=1;
   if(a[i]>section)
   {
      cache[i][section]=min(1 + dp(i+1,section), dp(i+1, a[i]));
   }
   else if(a[i]<section)
   {
      cache[i][section]=1+dp(i+1,section);
   }
   else
   {
      cache[i][section]=dp(i+1,section);
   }
   return cache[i][section];

}
int main()
{
   IOS;
   cin>>n>>m;
   long double temp;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i]>>temp;
   }
   cout<<dp(1, 1);
   return 0;
}