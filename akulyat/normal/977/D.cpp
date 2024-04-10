#include <bits/stdc++.h>

using namespace std;

long long n,i,j,u;
vector <long long> m,a;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back(a);}
for (i=0; i<n; i++)
  {
  a.clear();
  a.push_back(m[i]);
  for (u=0; u<n; u++)
  for (j=0; j<n; j++)
    {
    if (m[j]*3==a.back())
      a.push_back(m[j]);
    else if (m[j]==a.back()*2)
      a.push_back(m[j]);
    }
  if (a.size()==n)
    {
    for (i=0; i<n; i++)
      cout<<a[i]<<' ';
    return 0;
    }
  }
    return 0;
}