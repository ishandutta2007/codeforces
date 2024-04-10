#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, m, a[N];

bool comp(int &x, int &y)
{
   int p=abs(m + 1 - 2*x);
   int q=abs(m + 1 - 2*y);
   if(p!=q)
      return p<q;
   return x<y;
}

int32_t main()
{
   IOS;
   cin>>n>>m;
   for(int i=1;i<=m;i++)
   {
      a[i]=i;
   }
   sort(a+1, a+m+1, comp);
   a[0]=a[m];
   for(int i=1;i<=n;i++)
   {
      cout<<a[i%m]<<endl;
   }
}