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
vector <pll> m;
bool viv=false;

bool check(ll v1, ll v2)
{
for (ll i=0; i<n; i++)
  {
  set <ll> s;
  s.insert(v1);
  s.insert(v2);
  s.insert(m[i].F);
  s.insert(m[i].S);
  if (s.size()==4)
    return false;
  }
return true;
}

bool check(ll v)
{
for (ll i=0; i<n; i++)
  if (m[i].F!=v&&m[i].S!=v)
    {
    return check(v, m[i].F)||check(v, m[i].S);
    }
return true;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll k;
cin>>k>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }
if (check(m[0].F)||check(m[0].S))
  cout<<"YES";
else
  cout<<"NO";

    return 0;
}