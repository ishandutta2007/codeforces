#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main()
{
   IOS;
   int y, k, n;
   cin>>y>>k>>n;
   int x= k - (y%k);
   if(x+y>n)
   {
      cout<<"-1";
      return 0;
   }
   while(x+y<=n)
   {
      cout<<x<<" ";
      x+=k;
   }
   return 0;   
}