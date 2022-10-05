#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
long long n,i;
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

long long mimi=kk*kk*kk*10;
for (i=0; i<n; i++)
  {
  long long z=(m[i]/n)*n;
  mimi=min(mimi, z);
  }

for (i=0; i<n; i++)
  m[i]-=mimi;

for (i=0; i<n; i++)
  {
  if (m[i]<=i)
    {
    cout<<i+1<<endl;
    return 0;
    }
  m[i]-=n;
  }
for (i=0; i<n; i++)
  {
  if (m[i]<=i)
    {
    cout<<i+1<<endl;
    return 0;
    }
  m[i]-=n;
  }





    return 0;
}