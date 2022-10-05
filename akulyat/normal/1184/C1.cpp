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


ll n,i,j;
ll kx0, kx1, ky0, ky1;
vector <pll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ll x0=inf, x1=-inf, y0=inf, y1=-inf;
for (i=0; i<4*n+1; i++)
  {
  ll a, b;
  cin>>a>>b;
  x0=min(x0, a);
  x1=max(x1, a);
  y0=min(y0, b);
  y1=max(y1, b);
  m.push_back({a, b});
  }
for (auto p:m)
  {
  if (p.F==x0)
    kx0++;
  if (p.F==x1)
    kx1++;
  if (p.S==y0)
    ky0++;
  if (p.S==y1)
    ky1++;
  }

if (kx0==1)
  for (auto p:m)
    if (p.F==x0)
      {
      cout<<p.F<<' '<<p.S;
      exit(0);
      }
if (kx1==1)
  for (auto p:m)
    if (p.F==x1)
      {
      cout<<p.F<<' '<<p.S;
      exit(0);
      }
if (ky0==1)
  for (auto p:m)
    if (p.S==y0)
      {
      cout<<p.F<<' '<<p.S;
      exit(0);
      }
if (ky1==1)
  for (auto p:m)
    if (p.S==y1)
      {
      cout<<p.F<<' '<<p.S;
      exit(0);
      }

for (auto p:m)
  if (p.F!=x0&&p.F!=x1&&p.S!=y0&&p.S!=y1)
    cout<<p.F<<' '<<p.S<<endl;






    return 0;
}
/**
......
f.....
fff...
f.f...
fff...
......
**/