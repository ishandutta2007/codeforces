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
vector <vector <ll> > pl;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (auto v:m)
  {
  pl.push_back({});
  vector <ll> a,b;
  for (ll i=1; i<(ll)sqrt(v)+3; i++)
    if (v%i==0&&i*i<=v)
      {
      a.push_back(i);
      b.push_back(v/i);
      if (i*i==v)
        b.pop_back();
      }
  reverse(b.begin(), b.end());
  for (auto i:a)
    pl.back().push_back(i);
  for (auto i:b)
    pl.back().push_back(i);
  reverse(pl.back().begin(), pl.back().end());
  }

set <pll> s;
s.insert({0, 1});
ll ans=0;
for (i=0; i<n; i++)
  {
  for (auto p:pl[i])
    {
    auto z=s.lower_bound({p-1, -1});
    if (z!=s.end()&&(*z).F==p-1)
      {
      ll kol=(*z).S;
      pll a={p, kol};
//      cout<<m[i]<<" can be "<<p<<" in "<<kol<<" cases "<<endl;
      ans+=kol;
      ans%=mod;
      auto x=s.lower_bound({p, -1});
      if (x!=s.end()&&(*x).F==p)
          {
          ll add=(*x).S;
          s.erase(x);
          a.S+=add;
          a.S%=mod;
          }
      s.insert(a);
      }
    }
  }
cout<<ans<<endl;






    return 0;
}