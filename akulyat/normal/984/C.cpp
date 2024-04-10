#include <bits/stdc++.h>

using namespace std;
long long n,i;

long long GCD(long long x, long long y)
{
while (x!=0&&y!=0)
  {
  if (x>=y)
    x%=y;
  else
    y%=x;
  }
return x+y;
}

bool sea(long long c, long long m)
{
if (m%2!=0&&c%2==0)
  return false;
if (m%3!=0&&c%3==0)
  return false;
if (m%5!=0&&c%5==0)
  return false;
if (m%7!=0&&c%7==0)
  return false;
if (m%11!=0&&c%11==0)
  return false;
if (m%13!=0&&c%13==0)
  return false;

while (c%2==0)
  c/=2;
while (c%3==0)
  c/=3;
while (c%5==0)
  c/=5;
while (c%7==0)
  c/=7;
while (c%11==0)
  c/=11;
while (c%13==0)
  c/=13;

long long th=-1;
while (th!=c)
  {
  th=c;
  c/=GCD(c, m);
  }
return th==1;
}

int main()
{
ios_base::sync_with_stdio(0);
cin>>n;
for (long u=0; i<n; i++)
  {
  long long p,q,b;
  bool good=true;
  cin>>p>>q>>b;
  long long gg=GCD(p, q);
  q/=gg;
  good=sea(q, b);
  if (good)
    cout<<"Finite"<<endl;
  else
    cout<<"Infinite"<<endl;
  }


    return 0;
}