#include <bits/stdc++.h>

using namespace std;

long n,i,sum;
int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long a; cin>>a;
  sum+=abs(a);
  }
cout<<sum;

    return 0;
}