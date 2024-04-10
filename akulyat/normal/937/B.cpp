#include <bits/stdc++.h>

using namespace std;

long long p,x,i;

bool good (long long x)
{
for (long long i=2; i<(long long)sqrt(x)+3; i++)
  if (i<=p&&x%i==0)
    return false;
return true;
}
int main()
{
cin>>p>>x;
for (i=x; i>max(p, x-7000); i--)
  if (good(i))
    {
    cout<<i;
    return 0;
    }
cout<<-1;

    return 0;
}