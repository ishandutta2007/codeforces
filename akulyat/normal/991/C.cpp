#include <bits/stdc++.h>

using namespace std;

long long n,i;

int main()
{

cin>>n;

long long a=0;
long long b=n;

while (a+1!=b)
  {
  long long m=(a+b)/2;
  long long z=n;
  long long v=0, p=0;
  while (z>0)
    {
    long long s=min(m, z);
    v+=s;
    z-=s;
    z-=(z/10);
    }
//  cout<<m<<' '<<v<<endl;
  if (2*v>=n)
    b=m;
  else
    a=m;
  }

cout<<b;


    return 0;
}