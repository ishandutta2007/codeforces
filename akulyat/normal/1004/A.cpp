#include <bits/stdc++.h>

using namespace std;

long long n,i,j,d;
vector <long long> m;


int main()
{
cin>>n>>d;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());

long long ans=2;
for (i=0; i<n-1; i++)
  {
  long long l=m[i+1]-m[i];
  if (l>=2*d)
    ans+=2;
  if (l==2*d)
    ans--;
  }

cout<<ans;

    return 0;
}