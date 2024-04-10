#include <bits/stdc++.h>

using namespace std;

long long i,n;
map <long long, long long> m;

int main()
{
cin>>n;
for (i=0; i<1000; i++)
  m[i]=0;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m[a]++;
  }
long long ans=0;
for (i=0; i<1000; i++)
  ans=max(ans, m[i]);

cout<<ans;

    return 0;
}