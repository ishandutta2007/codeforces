#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
long long n,k,i,j;
vector <long long> m;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  long a; cin>>a;
  m.push_back(a);
  }

long long a=0, b=10*kk*kk+7;

while (a+1!=b)
  {
  long long mi=(a+b)/2;
  long long ans=0;

  for (i=0; i<n; i++)
    {
    long long v=m[i];
    long long c=1, d=0;
    if (v<mi)
      c=0;
    while (2*mi<=v)
      {
      long long c1=0, d1=0;
      if (v&1)
        {
        c1=c;
        d1=c;
        d1+=2*d;
        }
      else
        {
        c1=2*c;
        d1=d;
        c1+=d;
        }
      c=c1;
      d=d1;
      v/=2;
      }
    if (2*mi==v+1)
      d*=2;
    ans+=(c+d);
    }

  if (ans>=k)
    a=mi;
  else
    b=mi;
  }
if (a==0)
  a--;
cout<<a<<endl;

    return 0;
}