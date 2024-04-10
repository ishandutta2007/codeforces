#include <bits/stdc++.h>

using namespace std;

long long n,i,j;
vector <pair <long long, long long> > m;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }
reverse(m.begin(), m.end());
long long last=-100;
for (i=0; i<n; i++)
  {
  if (m[i].second<m[i].first)
      swap(m[i].first, m[i].second);
  if (m[i].first<last)
      swap(m[i].first, m[i].second);
  if (m[i].first<last)
    {
    cout<<"NO";
      return 0;
    }
  last=m[i].first;
  }

cout<<"YES";
    return 0;
}