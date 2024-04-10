#include <bits/stdc++.h>

using namespace std;

long long n,i,j,u;
vector <long long> m;


int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());

i=0;
j=n-1;
for (u=0; u<n; u++)
  {
  if (m[u]>m[i])
    i++;
  else
    j--;
  }

cout<<i;


    return 0;

}