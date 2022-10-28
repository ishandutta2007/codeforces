#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n;
int a[N];
multiset<int> s;

int32_t main()
{
   IOS;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
   }
   int ans=1;
   s.insert(a[1]);
   int L=1, R=1;
   while(R<n)
   {
      R++;
      s.insert(a[R]);
      while(*(--s.end())-*(s.begin())>1)
      {
         s.erase(s.find(a[L]));
         L++;
      }
      ans=max(ans, R-L+1);
   }
   cout<<ans;
   return 0;   
}