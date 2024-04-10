#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

struct vertex
{
ll v;
};
vertex t[ml];

ll n,i,j,s,l;
vector <ll> m;
ll k[200*kk];
bool viv=false;


void build()
{
s=1;
while (s<n+1)
  s*=2;
for (i=0; i<n+1; i++)
  t[i+s].v=0;
for (i=s-1; i>0; i--)
  t[i].v=0;
}

long long get(ll v)
{
if (v==1)
  return t[v].v;
return max(t[v].v, get(v/2));
}

void add(ll l, ll r, ll tl, ll tr, ll v, ll z)
{
//cout<<"Work in "<<v<<' '<<l<<' '<<r<<' '<<tl<<' '<<tr<<' '<<endl;
if (tr<l||r<tl)
  return;
if (l<=tl&&tr<=r)
  {
  t[v].v=max(t[v].v, z);
  return;
  }
ll tm=tl+tr>>1;
add(l, r, tl, tm, 2*v, z);
add(l, r, tm+1,  tr, 2*v+1, z);
}

void look()
{
cout<<"Tree ";
for (ll i=1; i<n+s+1; i++)
  cout<<t[i].v<<' ';
cout<<endl;
}

int main()
{
//viv=true;
cin>>n>>l;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--;
  k[a]++;
  k[b]--;
  }
ll sum=0;
for (i=0; i<l; i++)
  {
  sum+=k[i];
  m.push_back(sum);
  }
vector <ll> pre;
build();
for (i=0; i<l; i++)
  {
  pre.push_back(get(m[i]+s)+1);
  add(m[i], n, 0, s-1, 1, pre.back());
  if (viv)
    look();
  }

vector <ll> suf;
build();
for (i=l-1; i>=0; i--)
  {
  suf.push_back(get(m[i]+s)+1);
  add(m[i], n, 0, s-1, 1, suf.back());
  if (viv)
    look();
  }
reverse(suf.begin(), suf.end());

ll ans=0;
for (i=0; i<l; i++)
  ans=max(ans, suf[i]+pre[i]-1);

cout<<ans<<endl;
if (viv)
  {
  for (i=0; i<l; i++)
    cout<<k[i]<<' ';
  cout<<endl;
  for (i=0; i<l; i++)
    cout<<m[i]<<' ';
  cout<<endl;
  for (auto i:pre)
    cout<<i<<' ';
  cout<<endl;
  for (auto i:suf)
    cout<<i<<' ';
  cout<<endl;
  }
    return 0;
}