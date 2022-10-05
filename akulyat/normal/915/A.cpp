#include <bits/stdc++.h>

using namespace std;

int main()
{
long int i,n,k,b,ma=0;
cin>>n>>k;
for (i=0; i<n; i++)
  {
  cin>>b;
  if ((k%b==0)&&(b>ma))
    ma=b;
  }
cout<<k/ma;

   return 0;
}