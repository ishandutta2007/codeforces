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


ll n,i,j, s, ans;
vector <ll> t1, t2;
vector <ll> m, was, ones;
bool viv=false;

void build()
{
s=1;
while (s<n)
  s<<=1;
t1.resize(2*s);
t2.resize(2*s);
for (ll i=0; i<n; i++)
  t1[s+i]=m[i];
for (ll i=s-1; i>0; i--)
  t1[i]=max(t1[2*i], t1[2*i+1]);
vector <ll> las(n+1, -1);
for (ll i=0; i<n; i++)
  {
  ll val=m[i];
  was.push_back(las[val]);
  las[val]=i;
  }
for (ll i=0; i<n; i++)
  t2[s+i]=was[i];
for (ll i=n; i<s; i++)
  t2[s+i]=-1;
for (ll i=s-1; i>0; i--)
  t2[i]=max(t2[2*i], t2[2*i+1]);
}

ll maxi(ll l, ll r, ll v, ll tl, ll tr)
{
if (r<tl||tr<l)
  return 0;
if (l<=tl&&tr<=r)
  return t1[v];
ll tm=tl+tr>>1;
ll v1=maxi(l, r, 2*v, tl, tm);
ll v2=maxi(l, r, 2*v+1, tm+1, tr);
//cout<<"Max on "<<tl<<' '<<tr<<" is "<<max(v1, v2)<<endl;
return max(v1, v2);
}

ll rep(ll l, ll r, ll v, ll tl, ll tr)
{
if (r<tl||tr<l)
  return -1;
if (l<=tl&&tr<=r)
  return t2[v];
ll tm=tl+tr>>1;
ll v1=rep(l, r, 2*v, tl, tm);
ll v2=rep(l, r, 2*v+1, tm+1, tr);
return max(v1, v2);
}

void work()
{
ones.push_back(-1);
for (ll i=0; i<n; i++)
  if (m[i]==1)
    ones.push_back(i);
ones.push_back(n);
if (viv)
  {
  for (auto i:ones)
    cout<<i<<' ';
  cout<<endl;
  }
for (ll i=1; i<ones.size()-1; i++)
  {
  ll pl=ones[i];
  if (viv)
    cout<<"Work1 "<<pl<<endl;
  ll lans=1;
  ll ma=1;
  for (ll j=pl+1; j<ones[i+1]; j++)
    {
    ma=max(ma, m[j]);
    ll l=j-ma+1;
    if (viv)
      cout<<"Will check "<<l<<' '<<j<<endl,
      cout<<maxi(l, j, 1, 0, s-1)<<' '<<rep(l, j, 1, 0, s-1)<<endl;
    if (l>=0&&maxi(l, j, 1, 0, s-1)==ma&&rep(l, j, 1, 0, s-1)<l)
      lans++;
    }
  if (viv)
    cout<<lans<<endl<<endl;
  ans+=lans;
  }
for (ll i=1; i<ones.size()-1; i++)
  {
  ll pl=ones[i];
  if (viv)
    cout<<"Work2 "<<pl<<endl;
  ll lans=0;
  ll ma=1;
  for (ll j=pl-1; j>ones[i-1]; j--)
    {
    ma=max(ma, m[j]);
    ll r=j+ma-1;
    if (r<=n-1&&maxi(j, r, 1, 0, s-1)==ma&&rep(j, r, 1, 0, s-1)<j)
      lans++;
    }
  if (viv)
    cout<<lans<<endl<<endl;
  ans+=lans;
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
build();
work();
cout<<ans<<endl;






    return 0;
}