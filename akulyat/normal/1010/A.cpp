#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long double eps=1e-8;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,k;
vector <ll> m,vz,pos;
bool viv=false;


int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  vz.push_back(a);
  pos.push_back(b);
  }
for (i=0; i<n; i++)
  {
  m.push_back(vz[i]);
  m.push_back(pos[(i+1)%n]);
  }
n*=2;
ld a=0;
ld b=mod;

while (abs(b-a)>eps)
  {
  ld mi=(a+b)/2;
  ld mas=mi+k;
  for (i=0; i<n; i++)
    {
    mas-=(mas/m[i]);
    }
  if ((mas-k)<eps)
    a=mi;
  else
    b=mi;
  }
cout.precision(15);
cout.fixed;
if (abs(mod-a)<eps*10000)
  {
  cout<<-1;
  return 0;
  }
cout<<a<<endl;


    return 0;
}