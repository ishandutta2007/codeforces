#include <bits/stdc++.h>

using namespace std;

long long n,i,j,sum;
vector <long long> m;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  sum+=a;
  }
for (auto i:m)
  m.push_back(i);

long long ans=1e9;
for (i=0; i<n; i++)
  {
  long long z=0;
  for (j=i; j<i+n; j++)
    {
    z+=m[j];
    ans=min(ans, 2*abs(sum/2-z));
    }
  }

cout<<ans;


    return 0;
}