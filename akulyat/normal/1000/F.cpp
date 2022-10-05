#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long    ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

vector <ll> t;
ll n,i,j, q, s, nex_r;
vector <ll> m, ans;
vector <pair <pll, ll> > qr;
map <ll, ll> mp;
bool viv=false;

void show()
{
if (!viv)
  return;
cout<<"Last have"<<endl;
for (ll i=0; i<n; i++)
  cout<<t[i+s]<<' ';
cout<<endl;
}

void read()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
cin>>q;

for (ll i=0; i<q; i++)
  {
  ll l, r;
  cin>>l>>r;
  l--, r--;
  qr.push_back({{r, l}, i});
  }
sort(qr.begin(), qr.end());
}

void build()
{
s=1;
while (s<n)
  s<<=1;
t.resize(2*s);
for (auto &i:t)
  i=n;
}

void cmp(ll v)
{
if (v<1)
  return;
t[v]=min(t[2*v], t[2*v+1]);
cmp(v/2);
}

void make(ll v, ll val)
{
t[v]=val;
cmp(v/2);
}

void upd()
{
ll val=m[nex_r];
if (viv)
  cout<<"Update right point to "<<nex_r<<" that is "<<val<<endl;
if (mp.find(val)!=mp.end())
  {
  make(mp[val]+s, n);
  make(nex_r+s, mp[val]);
  }
else
  make(nex_r+s, -1);
mp[val]=nex_r;
nex_r++;

show();
}

ll lef(ll l, ll r, ll v, ll tl, ll tr)
{
if (tr<l||r<tl)
  return n;
if (l<=tl&&tr<=r)
  return t[v];
ll tm=tl+tr>>1;
ll l1=lef(l, r, 2*v, tl, tm);
ll l2=lef(l, r, 2*v+1, tm+1, tr);
return min(l1, l2);
}

ll mini(ll l, ll r, ll v, ll tl, ll tr)
{
if (tl==tr)
  return v-s;
ll tm=tl+tr>>1;
ll l1=lef(l, r, 2*v, tl, tm);
ll l2=lef(l, r, 2*v+1, tm+1, tr);
if (l1<l2)
  return mini(l, r, 2*v, tl, tm);
else
  return mini(l, r, 2*v+1, tm+1, tr);
}

void work(pair <pll, ll> p)
{
ll num=p.S;
ll r=p.F.F;
ll l=p.F.S;
if (viv)
  cout<<"Work seg "<<num<<"=["<<l<<"; "<<r<<"] "<<endl;
if (lef(l, r, 1, 0, s-1)>=l)
  {
  ans[num]=0;
  return;
  }
ll pl=mini(l, r, 1, 0, s-1);
ans[num]=m[pl];
}

void solve()
{
ans.resize(q);
nex_r=0;
for (auto p:qr)
  {
  ll loc_r=p.F.F;
  while (nex_r<=loc_r)
    upd();
  work(p);
  }
}

void write()
{
for (auto i:ans)
  cout<<i<<'\n';
cout<<endl;
}


int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
build();
solve();
write();


    return 0;
}