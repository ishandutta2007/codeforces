#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
   IOS;
   int n;
   cin>>n;
   set<int> a;
   set<int> b;
   while(n>=4)
   {
      a.insert(n);
      b.insert(n-1);
      b.insert(n-2);
      a.insert(n-3);
      n-=4;
   }
   if(n==3)
   {
      a.insert(3);
      b.insert(2);
      b.insert(1);
   }
   else if(n==2)
   {
      a.insert(1);
      b.insert(2);
   }
   else if(n==1)
   {
      a.insert(1);
   }
   int asum=0, bsum=0;
   for(auto it:a)
      asum+=it;
   for(auto it:b)
      bsum+=it;
   cout<<abs(bsum-asum)<<endl;
   cout<<a.size()<<" ";
   for(auto it:a)
      cout<<it<<" ";
   return 0;
}