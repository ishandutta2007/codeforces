#include <bits/stdc++.h>

using namespace std;

long long n,i,j,ans;
vector <long long> m;

int main()
{
cin>>n;
for (i=0; i<2*n; i++)
  { long long a; cin>>a; m.push_back(a); }

for (i=0; i<n; i++)
  {
  long long v=m[2*i];
  long long p=2*i+1;
  for (j=2*i+1; j<2*n; j++)
    if (m[j]==v)
      p=j;
  while (p!=2*i+1)
    {
    swap(m[p], m[p-1]);
    p--;
    ans++;
    }
  }
cout<<ans;
    return 0;
}