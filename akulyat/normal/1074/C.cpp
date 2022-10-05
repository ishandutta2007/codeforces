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


ll n,i,j,best=0;
vector <pll> m,xp,yp,p;
vector <ll> x,y;
bool viv=false;

pll obr(pll a)
{
pll r;
r.F=a.S;
r.S=a.F;
return r;
}

void easy()
{
ll ans=x.back()-x[0]+y.back()-y[0];
ans*=2;
for (ll i=3; i<=n; i++)
  cout<<ans<<' ';
exit(0);
}

void add(pll a, pll b, pll c)
{
ll x0=min(a.F, min(b.F, c.F));
ll x1=max(a.F, max(b.F, c.F));
ll y0=min(a.S, min(b.S, c.S));
ll y1=max(a.S, max(b.S, c.S));
ll lbest=2*(x1+y1-x0-y0);
//cout<<lbest<<endl;
best=max(best, lbest);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  x.push_back(a);
  y.push_back(b);
  xp.push_back({a, b});
  yp.push_back({b, a});
  }
sort(x.begin(), x.end());
sort(y.begin(), y.end());
sort(xp.begin(), xp.end());
sort(yp.begin(), yp.end());

for (auto i:xp)
  if (i.F==xp[0].F||i.F==xp.back().F)
    p.push_back(i);
for (auto i:yp)
  if (i.F==yp[0].F||i.F==yp.back().F)
    p.push_back(obr(i));

for (auto i:p)
  for (auto j:p)
    for (auto u:xp)
      add(i, j, u);
cout<<best<<' ';
for (ll i=4; i<=n; i++)
  {
  ll ans=x.back()+y.back()-x[0]-y[0];
  ans*=2;
  cout<<ans<<' ';
  }






    return 0;
}