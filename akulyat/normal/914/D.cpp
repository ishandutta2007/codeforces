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

long long t[3*ml];

ll n,i,j,s,q;
vector <ll> m;
bool viv=false;


long long GCD(long long a, long long b)
{
if (a==0&&b==0)
  return 1;
while (a!=0&&b!=0)
  {
  if (a>=b)
    a%=b;
  else
    b%=a;
  }
return a+b;
}

void count(ll p)
{
t[p]=t[2*p];
if (t[2*p+1]!=mod)
  t[p]=GCD(t[p], t[2*p+1]);
}

void build()
{
s=1;
while (s<n)
  s*=2;

for (ll i=0; i<n; i++)
  t[i+s]=m[i];
for (ll i=n; i<s; i++)
  t[i+s]=mod;
for (ll i=s-1; i>0; i--)
  count(i);
}

void change(ll p, ll v)
{
if (p>=s)
  t[p]=v;
else
  count(p);
if (p!=1)
  change(p/2, v);
}

ll get(ll l, ll r, ll tl, ll tr, ll v, ll z)
{
if (viv)
  cout<<"In "<<v<<endl;
if (tr<l||r<tl)
  return 0;
if (l<=tl&&tr<=r)
  if (t[v]%z==0)
    return 0;
if (tl==tr)
  return 1;

ll tm=tr+tl>>1;
ll ans=0;
ans+=get(l, r, tl, tm, 2*v, z);
if (ans>=2)
  return ans;
ans+=get(l, r, tm+1, tr, 2*v+1, z);
return ans;
}

void write()
{
for (ll i=1; i<n+s; i++)
  cout<<t[i]<<' ';
cout<<endl;
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
if (viv)
  write();

cin>>q;
for (ll u=0; u<q; u++)
  {
  short ty;
  cin>>ty;
  if (ty==1)
    {
    ll l,r,v;
    cin>>l>>r>>v;
    l--; r--;
    if (get(l, r, 0, s-1, 1, v)<=1)
      cout<<"YES"<<'\n';
    else
      cout<<"NO"<<'\n';
    }
  if (ty==2)
    {
    ll p,v;
    cin>>p>>v;
    p--;
    change(p+s, v);
    }
  if (viv)
    write();
  }

    return 0;
}