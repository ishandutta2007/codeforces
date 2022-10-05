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
const ll N=4*ml+110;

struct node
{
  ll val;
  ll push;
};

ll n,i,j, r, ans, s;
vector <pll> m;
vector <node> t;
vector <vector <ll>> have;
bool viv=false;


void build()
{
s=1;
while (s<N)
  s<<=1;
t.resize(2*s);
}

void push(ll v)
{
if (v>=s)
  return;
t[2*v].val+=t[v].push;
t[2*v].push+=t[v].push;
t[2*v+1].val+=t[v].push;
t[2*v+1].push+=t[v].push;
t[v].push=0;
}

void upd(ll v)
{
if (v>=s)
  return;
t[v].val=max(t[2*v].val, t[2*v+1].val);
}

void add(ll l, ll r, ll v, ll tl, ll tr, ll val)
{
if (r<tl||tr<l)
  return;
push(v);
if (l<=tl&&tr<=r)
  {
  t[v].val+=val;
  t[v].push+=val;
  return;
  }
ll tm=tl+tr>>1;
add(l, r, 2*v, tl, tm, val);
add(l, r, 2*v+1, tm+1, tr, val);
upd(v);
}

ll get(ll l, ll r, ll v, ll tl, ll tr)
{
if (r<tl||tr<l)
  return 0;
push(v);
if (l<=tl&&tr<=r)
  return t[v].val;
ll tm=tl+tr>>1;
ll lans=0;
lans=max(lans, get(l, r, 2*v, tl, tm));
lans=max(lans, get(l, r, 2*v+1, tm+1, tr));
upd(v);
return lans;
}


void erase(ll x)
{
if (x<0)
  return;
for (auto y:have[x])
  {
  ll from=y-r;
  from=max(from, 0ll);
  add(from, y, 1, 0, s-1, -1);
  }
}

void insert(ll x)
{
erase(x-r-1);
for (auto y:have[x])
  {
  ll from=y-r;
  from=max(from, 0ll);
  add(from, y, 1, 0, s-1, 1);
  }
ans=max(ans, get(0, s-1, 1, 0, s-1));
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n>>r;
r*=2;
for (i=0; i<n; i++)
  {
  ll a, b;
  cin>>a>>b;
  m.push_back({b-a, b+a});
  }
ll con=2*ml;
for (auto &p:m)
  p.F+=con,
  p.S+=con;
sort(m.begin(), m.end());
if (viv)
  {
  for (auto i:m)
    cout<<i.F<<' '<<i.S<<";   ";
  cout<<endl;
  }
have.resize(N);
for (auto pr:m)
  have[pr.F].push_back(pr.S);
if (viv)
  for (ll i=0; i<10; i++)
    {
    cout<<i<<": ";
    for (auto v:have[i])
      cout<<v<<' ';
    cout<<endl;
    }
build();
for (ll i=0; i<N; i++)
  insert(i);
cout<<ans;






    return 0;
}
/**
|y0-x0-y1+x1|+|y0+|
.....g..
...aggg.
...ggggg
...0ggg.
.....g..
0 2   2 2
1 0  -1 1
2 0  -2 2





**/