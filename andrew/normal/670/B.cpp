#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[100001],n,m,i,j,k,sc;
int main ()
{
  ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n >> k;
   for(i=1;i<=n;i++)cin >> a[i];
   ll c=1;
   while(1)
   {
       if(k<=c)
       {
          cout << a[k] << endl;
          return 0;
       }
       k-=c;
       c++;
   }
 return 0;
}