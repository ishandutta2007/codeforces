#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

set<int> cur;
int32_t main()
{
   IOS;
   int n;
   cin>>n;
   cur.insert(1);
   cur.insert(2);
   for(int i=1;i<=n;i++)
   {
      int k;
      cin>>k;
      if(cur.find(k)==cur.end())
      {
         cout<<"NO";
         return 0;
      }
      int store;
      for(auto it:cur)
      {
         if(it==k)
         {
            continue;
         }
         store=it;
      }
      cur.erase(store);
      for(int i=1;i<=3;i++)
      {
         if(i==k||i==store)
            continue;
         cur.insert(i);
      }
   }
   cout<<"YES";
}