#include <bits/stdc++.h>

using namespace std;

long long n,i,j;
vector <long long> m,a,b,z;
map <long long, long long> mps,mpf;
set <long long> s;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }

for (i=0; i<n; i++)
  {
  long long v=m[i];
  if (mps.find(v)==mps.end())
    mps[v]=i;
  mpf[v]=i;
  s.insert(v);
  }

for (auto j:s)
  {
  a.push_back(mps[j]);
  b.push_back(mpf[j]);
  }
long long l=a.size();
for (auto i:b)
  z.push_back(i);
sort(z.begin(), z.end());

/*
for (auto i:a)
  cout<<i<<' ';
cout<<endl;
for (auto i:b)
  cout<<i<<' ';
cout<<endl;
for (auto i:z)
  cout<<i<<' ';
cout<<endl;
*/

long long ans=0;
for (i=0; i<l; i++)
  {
  long long st=a[i];
  long long kol=lower_bound(z.begin(), z.end(), st)-z.begin();
  kol=l-kol;
  if (st==b[i])
    kol--;
  ans+=kol;
  }

cout<<ans;

    return 0;
}