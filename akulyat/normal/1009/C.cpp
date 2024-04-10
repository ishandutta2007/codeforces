#include <bits/stdc++.h>

using namespace std;

long long n,q;

int main()
{
cin>>n>>q;
long long ans=0;
for (long long u=0; u<q; u++)
  {
  long long x, d;
  cin>>x>>d;
  ans+=x*n;
  if (d>0)
    {
    ans+=((n*(n-1))/2)*d;
    }
  else
    {
    long long a=n/2;
    long long b=n-1-a;
    ans+=((a*(a+1))/2)*d;
    ans+=((b*(b+1))/2)*d;
    }
  }

long double ot=(long double)ans/(long double)n;
cout.precision(15);
cout<<fixed<<ot<<endl;

    return 0;
}