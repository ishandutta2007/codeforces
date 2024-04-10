#include <bits/stdc++.h>

using namespace std;

long long n,i;
long long x[200000],y[200000], need[200000];

void work(long long rx, long long ry, long long a, long long b)
{
long long ost=n-1;
for (i=0; i<n; i++)
  {
  need[i]=1;
  }

for (i=0; i<n; i++)
  if (x[i]!=a||y[i]!=b)
    {
    long long c=x[i]-a;
    long long d=y[i]-b;
    if (rx*d==c*ry)
      {
      ost--;
      need[i]=0;
      }
    }
  else
    need[i]=0;

if (ost<=2)
  {
  cout<<"YES"<<endl;
  exit(0);
  }

long long f=0;
long long s=0;
for (i=0; i<n; i++)
  if (need[i]==1)
    {
    f=i;
    i=n;
    need[f]=0;
    ost--;
    }
for (i=0; i<n; i++)
  if (need[i]==1)
    {
    s=i;
    rx=x[f]-x[s];
    ry=y[f]-y[s];
    i=n;
    need[s]=0;
    ost--;
    }



for (i=0; i<n; i++)
  if (need[i]==1)
    {
    long long a=x[f];
    long long b=y[f];
    long long c=x[i]-a;
    long long d=y[i]-b;
    if (rx*d==c*ry)
      {
      ost--;
      need[i]=0;
      }
    }

if (ost==0)
  {
  cout<<"YES"<<endl;
  exit(0);
  }

}


int main()
{
cin>>n;
for (i=0; i<n; i++)
  cin>>x[i]>>y[i];

if (n<=4)
  {
  cout<<"YES"<<endl;
  return 0;
  }

work(x[1]-x[0], y[1]-y[0], x[0], y[0]);
work(x[1]-x[2], y[1]-y[2], x[1], y[1]);
work(x[2]-x[0], y[2]-y[0], x[2], y[2]);


cout<<"NO"<<endl;


   return 0;
}