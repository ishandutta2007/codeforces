#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N];
int b[48]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check()
{
   bool ans=0;
   for(int i=0;i<48;i++)
   {
      bool cur=1;
      for(int j=1;j<=n;j++)
      {
         if(b[(i+j)%48]!=a[j])
         {
            cur=0;
            break;
         }
      }
      if(cur)
         ans=1;
   }
   return ans;
}

int32_t main()
{
   IOS;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
   }
   bool ans=0;
   for(int i=1;i<=48;i++)
   {
      ans|=check();
      rotate(b, b+1, b+48);
   }
   if(ans)
      cout<<"YES";
   else
      cout<<"NO";
   return 0;
}