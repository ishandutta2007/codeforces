#include <bits/stdc++.h>

using namespace std;

long long n,k;
long long b,i;

vector <long> s;
vector < pair<long, long> > m;

int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  long a;
  cin>>a;
  m.push_back({a, i});
  }
sort(m.begin(), m.end());
b=-1;
for (i=0; i<n; i++)
  {
  long long a;
  a=m[i].first;
  if (a!=b)
    s.push_back(m[i].second+1);
  b=a;
  }

if (s.size()<k)
  {
  cout<<"NO";
  return 0;
  }

cout<<"YES"<<endl;
for (i=0; i<k; i++)
  cout<<s[i]<<' ';

    return 0;
}