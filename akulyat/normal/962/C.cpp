#include <bits/stdc++.h>

using namespace std;


string s;
long n,i;


int main()
{
cin>>s;
n=s.size();

long long ans=100;
for (long long u=0; u<(1<<n); u++)
  {
  long long u1=u;
  long long ubr=n;
  vector <long> need;
  for (i=0; i<n; i++)
    {
    need.push_back(u1&1);
    u1/=2;
    }
  for (i=0; i<n; i++)
    if (need[i]&1)
      ubr--;
  bool dodo=true;
  for (i=0; i<n; i++)
    if (need[i]&1)
      {
      if (s[i]=='0')
        dodo=false;
      i=n;
      }
  if (dodo)
    {
    long long ch=0;
    for (i=0; i<n; i++)
      if (need[i]&1)
        {
        ch*=10;
        ch+=(s[i]-'0');
        }
    if (ch!=0)
      if ((long long)sqrt(ch)*(long long)sqrt(ch)==ch)
        ans=min(ans, ubr);
    }
  }


if (ans==100)
  {
  cout<<-1;
  return 0;
  }

cout<<ans;

    return 0;
}