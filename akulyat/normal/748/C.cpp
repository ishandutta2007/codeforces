#include <iostream>

using namespace std;

long long d,u,l,r,n,i;
string s;

int main()
{
cin>>n>>s;
long long ans=0;
for (i=0; i<n; i++)
  {
  if (s[i]=='R')
    r++;
  if (s[i]=='U')
    u++;
  if (s[i]=='L')
    l++;
  if (s[i]=='D')
    d++;
  if (r*l>0||d*u>0)
    {
    ans++;
    r=0; l=0; u=0; d=0;
    if (s[i]=='R')
      r++;
    if (s[i]=='U')
      u++;
    if (s[i]=='L')
      l++;
    if (s[i]=='D')
      d++;
    }
  }
ans++;

cout<<ans;

    return 0;
}