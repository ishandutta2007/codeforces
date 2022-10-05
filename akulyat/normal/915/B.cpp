#include <bits/stdc++.h>

using namespace std;

int main()
{
long int a,i,n,k,l,r;
cin>>n>>k>>l>>r;
if ((l==1)&&(r==n))
  a=0; else
  if (l==1)
    a=abs(k-r)+1; else
    if (r==n)
      a=(abs(k-l))+1; else
        a=min((abs(k-l)), abs(k-r))+r-l+2;
cout<<a;
   return 0;
}