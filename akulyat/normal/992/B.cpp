#include <bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b)
{
if (a==0&&b==0)
  return 1;
while (a!=0&&b!=0)
  {
  if (a>=b)
    a%=b;
  else
    b%=a;
  }
return a+b;
}

vector <long long> m;

void cou(long long v)
{
long long x=v;
long long i;
for (i=1; i<(long long)sqrt(v)+10; i++)
  if (x%i==0)
  {
  if (i*i<=x)
    {
    m.push_back(i);
    if (i*i<x)
      m.push_back(x/i);
    }
  }
}

long long l,r,x,y,p,ans,i;

int main()
{
cin>>l>>r>>x>>y;
p=x*y;

cou(y);

for (i=0; i<m.size(); i++)
  {
  long long v=m[i];
  if (p%v==0)
    {
    long long z=p/v;
    if (GCD(z, v)==x&&v<=r&&z<=r&&v>=l&&z>=l)
      {
      ans++;
      }
    }
  }

cout<<ans;



    return 0;
}