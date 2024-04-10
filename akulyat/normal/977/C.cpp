#include <bits/stdc++.h>

using namespace std;

vector <long> m;
long n,k,i;

int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back(a);  }

sort(m.begin(), m.end());

if (k==0&&m[0]!=1)
  {
  cout<<1;
  return 0;
  }
if (k==0&&m[0]==1)
  {
  cout<<-1;
  return 0;
  }
if (m[k-1]!=m[k])
  {
  cout<<m[k-1];
  return 0;
  }
cout<<-1;
    return 0;
}