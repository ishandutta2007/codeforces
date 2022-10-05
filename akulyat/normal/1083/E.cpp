#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <ld, ld> pld;
typedef pair <pll, ll> ppll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j;
vector <ppll> m;
bool viv=false;

ld inter(pll a, pll b)
{
return (ld)(b.S-a.S)/(ld)(a.F-b.F);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m.push_back({{0, 0}, 0});
for (i=0; i<n; i++)
  {
  ll a,b,c;
  cin>>a>>b>>c;
  m.push_back({{a, b}, c});
  }
sort(m.begin(), m.end());
vector <ppll> p;
vector <ld> g;
vector <ll> ans;
p.push_back({{0, 0}, 0});
g.push_back(inf);
g.push_back(-inf);
ans.push_back(0);
for (ll i=1; i<=n; i++)
  {
  if (viv)
    {
    cout<<i<<":"<<endl;
    for (auto i:p)
      cout<<i.F.F<<'_'<<i.F.S<<' ';
    cout<<endl;
    for (auto i:g)
      cout<<i<<' ';
    cout<<endl;
    }
  ll y=m[i].F.S;
  ll x=m[i].F.F;
  ll pr=m[i].S;
  ll l=0;
  ll r=g.size()-1;
  while (l+1!=r)
    {
    ll mi=l+r>>1;
    if (g[mi]<y)
      r=mi;
    else
      l=mi;
    }
  ll lans=x*y-pr+p[l].F.S+y*p[l].F.F;
  ans.push_back(lans);
  bool cont=true;
  g.pop_back();
  while (cont)
    {
    ld pt=inter(p.back().F, {-m[i].F.F, ans.back()});
    cont=false;
    if (pt>g.back())
      {
      cont=true;
      p.pop_back();
      g.pop_back();
      }
    else
      {
      g.push_back(pt);
      p.push_back({{-m[i].F.F, ans.back()}, i});
      }
    }
  g.push_back(-inf);
  }
if (viv)
  {
  for (auto i:ans)
    cout<<i<<' ';
  cout<<endl;
  }
cout<<*max_element(ans.begin(), ans.end());






    return 0;
}