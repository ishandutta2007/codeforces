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
vector <ll> m;
bool viv=false;
set <ll> s;
map <ll, vector <pll> > mp;

ll rast(pll a, pll b)
{
return abs(a.F-b.F)+abs(a.S-b.S);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  s.insert(max(a, b));
  mp[max(a, b)].push_back({a, -b});
  }
for (auto v:s)
  sort(mp[v].begin(), mp[v].end());

ll a=0;
ll b=0;
pll sp={0, 0};
pll se={0, 0};
for (auto v:s)
  {
  pll nsp=mp[v][0];
  pll nse=mp[v].back();
  ll na=min(a+rast(se, nsp), b+rast(sp, nsp));
  ll nb=min(a+rast(se, nse), b+rast(sp, nse));
  ll r=rast(nsp, nse);
  na+=r, nb+=r;
  se=nse;
  sp=nsp;
  a=na;
  b=nb;
//  cout<<a<<' '<<b<<endl;
  }
cout<<min(a, b);










    return 0;
}