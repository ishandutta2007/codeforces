#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,k;
vector <ll> m;
bool viv=false;

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

int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a%=k;
  m.push_back(a);
  }
for (i=0; i<n; i++)
  m[i]=GCD(m[i], k);
for (i=1; i<n; i++)
  m[i]=GCD(m[i-1], m[i]);


ll del=m[n-1];

ll z=0;
cout<<(k/del)<<endl;
while (z<k)
  cout<<z<<' ', z+=del;


    return 0;
}