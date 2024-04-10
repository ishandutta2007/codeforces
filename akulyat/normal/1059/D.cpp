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
const long double eps=1e-8;

ll n,i,j;
vector <pll> m;
bool viv=false;

bool work(ld rad)
{
ld l=-inf;
ld r=inf;
for (auto i:m)
  {
  if (abs(i.S-rad)>rad)
    l=inf, r=-inf;
  else
    {
    ld hord=sqrt(rad*rad-(i.S-rad)*(i.S-rad));
    l=max(l, i.F-hord);
    r=min(r, i.F+hord);
    }
  }
if (l<r)
  return true;
return false;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ll mz=0;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  if (b>0)
    mz++;
  m.push_back({a, abs(b)});
  }
if (mz!=0&&mz!=n)
  {
  cout<<-1;
  return 0;
  }

ld l=0;
ld r=mod*ml;
while (l<r-eps&&(r-l)/r>eps)
  {
  ld mi=(l+r)/2;
  if (work(mi))
    r=mi;
  else
    l=mi;
  }

cout.precision(20);
cout<<fixed<<r<<endl;

    return 0;
}