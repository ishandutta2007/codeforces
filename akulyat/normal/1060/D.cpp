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
set <pair <pll, ll> > r,l;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ll ans=n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  ans+=max(a, b);
  if (a>b)
    l.insert({{a, b}, i});
  if (a<b)
    r.insert({{b, a}, i});
  }

while (l.size()&&r.size())
  {
  auto a=(*l.rbegin()).F;
  auto b=(*r.rbegin()).F;
  if (min(a.F, b.F)<=max(a.S, b.S))
    {
    if (a.F>b.F)
      l.erase(l.find(*l.rbegin()));
    else
      r.erase(r.find(*r.rbegin()));
    }
  else
    {
    ans-=(min(a.F, b.F)-max(a.S, b.S));
    pair <pll, ll> add;
    ll nl=b.S;
    ll nr=a.S;
    ll num=(*l.rbegin()).S;
    l.erase(l.find(*l.rbegin()));
    r.erase(r.find(*r.rbegin()));
    if (nl>nr)
      l.insert({{nl, nr}, num});
    if (nl<nr)
      r.insert({{nr, nl}, num});
    }
  }
cout<<ans;





    return 0;
}