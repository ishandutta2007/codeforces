#include <bits/stdc++.h>

using namespace std;

const long kk=1000;
long n,q,i,j;
vector <pair<long long, long long> > m;
long long sum;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }
cin>>q;
for (i=0; i<q; i++)
  {
  long a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }
m.push_back({0, 0});
m.push_back({kk*kk*kk+1, 0});
sort(m.begin(), m.end());
for (i=1; i<n+q+1; i++)
  {
  sum+=m[i].second;
  if (m[i].first==m[i-1].first&&m[i].second<=m[i-1].second)
    sum-=m[i].second;
  if (m[i].first==m[i+1].first&&m[i].second<m[i+1].second)
    sum-=m[i].second;
  }
cout<<sum;

    return 0;
}