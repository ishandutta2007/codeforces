#include <bits/stdc++.h>

using namespace std;

long long n,i,k,j;
vector <long long> m,r;
int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }


long long h=0;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  r.push_back(a);
  if (r.back()==1)
    h+=m[i];
  }

long long now=0;
for (i=0; i<k; i++)
  {
  if (r[i]==0)
    now+=m[i];
  }
long long ans=h+now;

for (i=k; i<n; i++)
  {
  if (r[i-k]==0)
    now-=m[i-k];
  if (r[i]==0)
    now+=m[i];
  ans=max(ans, h+now);
  }

cout<<ans;


    return 0;
}