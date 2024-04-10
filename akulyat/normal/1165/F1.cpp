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


ll n,i,j, sg, sumpr;
vector <ll> m;
vector <vector <ll>> dis;
bool viv=false;

bool able(ll days)
{
ll need=sumpr-days;
vector <pll> v;
for (ll i=0; i<n; i++)
  for (ll j=0; j<dis[i].size(); j++)
    if (dis[i][j]<=days)
      v.push_back({dis[i][j], i});
sort(v.rbegin(), v.rend());
vector <bool> was(n, false);
ll eat_to=inf;
for (ll i=0; i<v.size(); i++)
  {
  eat_to=min(eat_to, v[i].F+1);
  ll eat=min(eat_to-1, m[v[i].S]);
  if (was[v[i].S]==false)
    was[v[i].S]=true,
    eat_to-=eat,
    need-=eat;
  }
if (need<=0)
  return true;
return false;
}

ll solve()
{
ll l=0;
ll r=ml;
while (l+1<r)
  {
  ll mi=l+r>>1;
  if (able(mi))
    r=mi;
  else
    l=mi;
  }
return r;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>sg;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  sumpr+=2*a;
  m.push_back(a);
  }
dis.resize(n);
for (i=0; i<sg; i++)
  {
  ll _d, _t;
  cin>>_d>>_t;
  _t--;
  dis[_t].push_back(_d);
  }
cout<<solve();



    return 0;
}