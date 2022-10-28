#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
   IOS;
   int t;
   cin>>t;
   while(t--)
   {
      int n;
      cin>>n;
      bool check=false;
      for(int a=0;a*3<=n;a++)
      {
         int small=a*3;
         int big=n-small;
         if(big%7==0)
         {
            check=true;
            break;
         }
      }
      if(check)
         cout<<"YES"<<endl;
      else
         cout<<"NO"<<endl;
   }
   return 0;
}