#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5e3+5;

int n;
int a[N];
vector<int> g[N];

void work(int k)
{
   for(int i=1;;i++)
   {
      if(!g[i].size())
      {
         g[i].push_back(k);
         break;
      }
      if(g[i][g[i].size()-1]>k)
      {
         g[i].push_back(k);
         break;
      }
   }
}

int32_t main()
{
   IOS;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
   }
   sort(a+1,a+n+1);
   reverse(a+1,a+n+1);
   for(int i=1;i<=n;i++)
   {
      work(a[i]);
   }
   for(int i=n;i>=1;i--)
   {
      if(g[i].size()!=0)
      {
         cout<<i;
         return 0;
      }
   }
   return 0;
}