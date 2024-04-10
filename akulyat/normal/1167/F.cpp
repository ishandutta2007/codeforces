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


ll n,i,j, ans, s;
vector <ll> m;
vector <pll> t;
bool viv=false;

void build()
{
s=1;
while (s<n)
  s<<=1;
t.resize(2*s, {0, 0});
}

void change(ll v, ll val)
{
v+=s;
while (v)
  {
  t[v].F+=val;
  t[v].S++;
  v>>=1;
  }
}

ll sum(ll l, ll r, ll v, ll tl, ll tr)
{
if (r<tl||tr<l)
  return 0;
if (l<=tl&&tr<=r)
  return t[v].F;
ll tm=tl+tr>>1;
ll lans=0;
lans+=sum(l, r, 2*v, tl, tm);
lans+=sum(l, r, 2*v+1, tm+1, tr);
if (viv)
  cout<<"sum on "<<tl<<' '<<tr<<" is "<<lans<<endl;
return lans;
}

ll kol(ll l, ll r, ll v, ll tl, ll tr)
{
if (r<tl||tr<l)
  return 0;
if (l<=tl&&tr<=r)
  return t[v].S;
ll tm=tl+tr>>1;
ll lans=0;
lans+=kol(l, r, 2*v, tl, tm);
lans+=kol(l, r, 2*v+1, tm+1, tr);
return lans;
}

void solve(ll pos)
{
ll seg=(pos+1)*(n-pos);
if (viv)
  cout<<"Work with pos="<<pos<<" it is val="<<m[pos]<<endl;
if (viv)
  cout<<seg<<endl;
          if (viv)
            cout<<"get "<<-sum(pos+1, s-1, 1, 0, s-1)+kol(pos+1, s-1, 1, 0, s-1)*n<<endl;
seg+=(-sum(pos+1, s-1, 1, 0, s-1)+kol(pos+1, s-1, 1, 0, s-1)*n)*(pos+1);
seg%=mod;
          if (viv)
            cout<<"get "<<sum(0, pos-1, 1, 0, s-1)<<endl;
seg+=(sum(0, pos-1, 1, 0, s-1)+kol(0, pos-1, 1, 0, s-1))*(n-pos);
seg%=mod;
/**
for (ll i=0; i<n; i++)
  if (m[i]<m[pos])
    if (i<pos)
      seg+=(i+1)*(n-pos);
    else
      seg+=(n-i)*(pos+1);
**/

seg%=mod;
ans+=((seg*m[pos])%mod);
ans%=mod;
change(pos, pos);
if (viv)
  cout<<seg<<endl;
if (viv)
  cout<<"______"<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n;
vector <pll> p;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  p.push_back({a, i});
  }
sort(p.begin(), p.end());
build();
for (auto pr:p)
  solve(pr.S);
cout<<ans<<endl;








    return 0;
}
/**
9 6 8 10






**/