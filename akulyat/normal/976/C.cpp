#include <bits/stdc++.h>

using namespace std;

long n,i;
vector <pair <pair <long, long>, long> > m;
int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a,b;
  cin>>a>>b;
  m.push_back({{a, b}, i});
  }
sort(m.begin(), m.end());
for (i=1; i<n; i++)
  {
  if (m[i].first.first >=m[i-1].first.first&&
      m[i].first.second<=m[i-1].first.second)
    {
    cout<<m[i].second+1<<' '<<m[i-1].second+1;
    return 0;
    }
  }
for (i=0; i<n-1; i++)
  {
  if (m[i].first.first >=m[i+1].first.first&&
      m[i].first.second<=m[i+1].first.second)
    {
    cout<<m[i].second+1<<' '<<m[i+1].second+1;
    return 0;
    }
  }
cout<<-1<<' '<<-1;


    return 0;
}