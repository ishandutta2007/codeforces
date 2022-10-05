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
vector <ll> m, h;
bool viv=false;

void easy()
{
set <ll> s;
vector <ll> pl;
pl.resize(n+1);
for (ll i=0; i<n; i++)
  if (h[i]!=0)
    pl[h[i]]=-1;
for (ll i=0; i<n; i++)
  if (m[i]!=0)
    pl[m[i]]=i;
ll from=pl[1];
bool can=true;
if (from==-1)
  {
  can=false;
  return;
  }
for (ll j=from; j<n; j++)
  if (m[j]!=j-from+1)
    can=false;
if (!can)
  return;

for (auto i:h)
  s.insert(i);
ll val=n+1-from;
for (ll i=0; i<from; i++)
  {
  if (s.find(val)==s.end())
    return;
  val++;
  s.insert(m[i]);
  }
cout<<from<<endl;
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  h.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
easy();
ll ma=0;
for (ll i=0; i<n; i++)
  {
  ll val=m[i];
  if (val!=0)
    {
    ll cw=val-1;
    ll sh=i+1;
    ma=max(ma, sh-cw);
    }
  }
cout<<n+ma<<endl;



    return 0;
}