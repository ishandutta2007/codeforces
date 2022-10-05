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
vector <pll> m,p;
bool viv=false;
set <pll> h;


void write(ll a, ll b)
{
cout<<a<<' '<<b<<endl;
exit(0);
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  p.push_back({a, b});
  h.insert({a, b});
  }

for (ll i=0; i<n; i++)
  {
  ll x,y;
  x=m[0].F+p[i].F;
  y=m[0].S+p[i].S;
  bool can=true;
  for (ll j=0; j<n; j++)
    {
    pll need={x-m[j].F, y-m[j].S};
    if (h.count(need)==0)
      can=false;
    }
//  cout<<x<<' '<<y<<endl;
  if (can)
    write(x, y);

  }













    return 0;
}