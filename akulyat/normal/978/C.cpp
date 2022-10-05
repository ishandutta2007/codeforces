#include <bits/stdc++.h>

using namespace std;

long long n,q,i;
vector <long long> m;

int main()
{
cin>>n>>q;
for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back(a);}

long long j=0;
long long sum=m[j];

for (long u=0; u<q; u++)
  {
  long long e;
  cin>>e;
  while (sum<e)
    {
    j++;
    sum+=m[j];
    }
  cout<<j+1<<' ';
  cout<<e-(sum-m[j])<<endl;
  }
    return 0;
}