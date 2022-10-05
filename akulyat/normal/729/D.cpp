#include <bits/stdc++.h>

using namespace std;

long long n,a,b,k,z,sum,i;
string s;

int main()
{
cin>>n>>a>>b>>k>>s;
z=-1;
n++;
s+='1';
for (i=0; i<n; i++)
  if (s[i]!='0')
    {
    long long d=(i-z)-1;
    d-=(d%b);
    d/=b;
//    cout<<"In place "<<i<<" i add "<<d<<endl;;
    sum+=d;
    z=i;
    }

long long ans=sum-a+1;
cout<<ans<<endl;

long long kol=0;
for (i=0; i<n; i++)
  {
  if (s[i]=='0')
    kol++;
  else
    kol=0;
  if (kol==b)
    {
    cout<<i+1<<' ';
    kol=0;
    ans--;
    }
  if (ans==0)
    i=n;
  }



    return 0;
}