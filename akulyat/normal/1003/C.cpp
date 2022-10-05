#include <bits/stdc++.h>

using namespace std;

long long i,n,k;
vector <long long> m;
long double ans;

void found(long long p)
{
long long i;
long long sum=0;
for (i=p; i<n; i++)
  {
  sum+=m[i];
  if (i-p+1>=k)
    ans=max(ans, (long double)sum/(long double)(i-p+1));
  }
}

int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }
for (i=0; i<n; i++)
  found(i);

cout.precision(10);
cout<<fixed<<ans;



    return 0;
}