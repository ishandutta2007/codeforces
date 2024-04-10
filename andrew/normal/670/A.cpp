#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[10001],n,m,i,j,k,sc;
int main ()
{
  ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n;
   ll mx=0,mn=1e18;
   for(i=1;i<=7;i++)
   {
       ll sc=0;
       ll ms=i;
       for(k=i;k<i+n;k++)
       {

        if(ms==6 or ms==7)sc++;
        ms++;
        if(ms==8)ms=1;
        if(ms==8)ms=1;
       }
       //cout <<sc << " " << i << endl;
       mx=max(mx,sc);
       mn=min(mn,sc);
   }
   cout << mn << " " << mx << endl;
 return 0;
}