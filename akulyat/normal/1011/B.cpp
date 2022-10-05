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
long long kol[kk];
bool viv=false;


int main()
{
cin>>k>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  kol[a]++;
  }
ll a=0;
ll b=1000;
while (a+1!=b)
  {
  ll m=a+b>>1;
  ll z=0;
  for (i=0; i<kk; i++)
    z+=kol[i]/m;
  if (z>=k)
    a=m;
  else
    b=m;
  }
cout<<a;



    return 0;
}