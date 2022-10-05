#include <bits/stdc++.h>

using namespace std;

long long i,n,a,b,x;
vector <long long> m;
string s;
int main()
{
cin>>a>>b>>x;

if (2*a==x)
  {
  for (i=0; i<a; i++)
    s+="01";
  for (i=a; i<b; i++)
    s="1"+s;
  cout<<s;
  return 0;
  }

x++;
long long l=0;
while (x>0)
  {
  s+='0'+(l&1);
  if (l&1)
    b--;
  else
    a--;
  l++;
  x--;
  }
while (a>0)
  {
  s='0'+s;
  a--;
  }
while (b>0)
  {
  if (s.back()=='0')
    {
    s.pop_back();
    s+="10";
    }
  else
    s+='1';
  b--;
  }

cout<<s;

    return 0;
}