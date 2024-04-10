#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long eps=1e-9;
const long double M_PI=3.14159265357989;

ll n,i,j,r;
vector <ll> m;
bool viv=false;

bool more(ld rr)
{
ld a=r+rr;
ld b=rr+rr;
ld cosa=1-(b*b/(2*a*a));
ld kol=2*M_PI;
ld ug=acos(cosa);
kol/=ug;
if (viv)
  cout<<a<<' '<<b<<' '<<cosa<<' '<<ug<<' '<<kol<<endl;
if (kol>n+eps)
  return true;
return false;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>r;
ld lg=0;
ld rg=1*ml;
cout.precision(15);
for (ll j=0; j<ml; j++)
  {
  if (viv)
    cout<<lg<<' '<<rg<<endl;
  ld mi=(lg+rg)/2.0;
  if (more(mi))
    lg=mi;
  else
    rg=mi;
  }
cout<<fixed<<lg<<endl;


    return 0;
}