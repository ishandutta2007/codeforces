#include <bits/stdc++.h>

using namespace std;

long long n,i;

long long GCD(long long a, long long b)
{
a=abs(a); b=abs(b);
while (a!=0&&b!=0)
  {
  if (a>=b)
    a%=b;
  else
    b%=a;
  }
return a+b;
}

bool kub(long long v)
{
long long a=0, b=1000001;
while (a+1!=b)
  {
  long long m=(a+b)/2;
  if (m*m*m>=v)
    b=m;
  else
    a=m;
  }
if (b*b*b==v)
  return true;
return false;

}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  long long a,b;
  cin>>a>>b;
  long long p=a*b;
  if (!kub(p))
    cout<<"No"<<'\n';
  else
    {
    long long g=GCD(a, b);
    if (p%(g*g)!=0)
      cout<<"No"<<'\n';
    else
      {
      p/=(g*g);
      if (g%p!=0)
        cout<<"No"<<'\n';
      else
        cout<<"Yes"<<'\n';
      }
    }
  }




    return 0;
}