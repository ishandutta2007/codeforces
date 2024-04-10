#include <bits/stdc++.h>

using namespace std;

const long long inf=(long long)1000*1000*1000*1000;

long long n,i,j;
vector <long long> s,c,best;
int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a; cin>>a; s.push_back(a);
  }
for (i=0; i<n; i++)
  {
  long long a; cin>>a; c.push_back(a);
  }

for (i=0; i<n; i++)
  best.push_back(inf);



for (i=0; i<n; i++)
  for (j=i+1; j<n; j++)
    {
    if (s[j]>s[i])
      best[i]=min(c[j], best[i]);
    }


long long ans=inf;
for (i=0; i<n; i++)
  {
  for (j=i+1; j<n; j++)
    if (s[j]>s[i])
      {
      ans=min(ans, c[i]+c[j]+best[j]);
      }
  }

if (ans!=inf)
  cout<<ans;
else
  cout<<-1;


    return 0;
}