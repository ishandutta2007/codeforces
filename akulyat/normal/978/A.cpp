#include <bits/stdc++.h>

using namespace std;

long i,j,n;
vector <long> m,k;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back(a);}
reverse(m.begin(), m.end());
for (i=0; i<n; i++)
  {
  long g=true;
  for (j=0; j<i; j++)
    if (m[i]==m[j])
      g=false;
  if (g)
    k.push_back(m[i]);
  }
reverse(k.begin(), k.end());
cout<<k.size()<<endl;

for (i=0; i<k.size(); i++)
  cout<<k[i]<<' ';


    return 0;
}