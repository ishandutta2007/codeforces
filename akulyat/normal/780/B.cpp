#include <bits/stdc++.h>

using namespace std;

const long double eps=0.000000001;
long long n,i,j;
vector < pair<long long, long long> > m;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long a; cin>>a;
  m.push_back({a, 0});
  }
for (i=0; i<n; i++)
  {
  long a; cin>>a;
  m[i].second=a;
  }

long double ans=0;
long double b=1000000000;

while (b-ans>eps)
  {
//  cout<<ans<<' '<<b<<endl;
  long double mi=(b+ans)/2;
  long double l=m[0].first-m[0].second*mi;
  long double r=m[0].first+m[0].second*mi;
  for (i=1; i<n; i++)
    {
    long double l1=m[i].first-m[i].second*mi;
    long double r1=m[i].first+m[i].second*mi;
    l=max(l, l1);
    r=min(r, r1);
    }
  if (r>l)
    b=mi;
  else
    ans=mi;
  }

cout.precision(8);
cout<<fixed<<ans;

    return 0;
}