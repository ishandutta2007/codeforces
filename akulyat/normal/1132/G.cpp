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
//const long long inf=ml*ml*ml+7;

struct vertex
{
  ll max,  push;
};

vector <vertex> t;
ll n,i,j,s, k;
vector <ll> m, las;
bool viv=false;

void read()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
}

void build()
{
s=1;
while (s<n)
  s<<=1;
t.resize(2*s);
}

void prepare()
{
vector <ll> st;
for (ll i=0; i<n; i++)
  {
  while (st.size()&&m[st.back()]<m[i])
    st.pop_back();
  if (st.size())
    las.push_back(st.back());
  else
    las.push_back(-1);
  st.push_back(i);
  }
build();
}

void upd(ll v)
{
if (v>=s)
  return;
ll val=max(t[2*v].max, t[2*v+1].max);
t[v].max=max(t[v].max, val);
}

void push(ll v)
{
if (v>=s)
  return;
ll add=t[v].push;
t[v].push=0;
t[2*v].max+=add;
t[2*v+1].max+=add;
t[2*v].push+=add;
t[2*v+1].push+=add;
}

void add(ll l, ll r, ll v, ll tl, ll tr, ll val)
{
if (r<tl||tr<l)
  return;
push(v);
if (l<=tl&&tr<=r)
  {
  t[v].push+=val;
  t[v].max+=val;
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
  return t[v].max;
ll tm=tl+tr>>1;
ll v1=get(l, r, 2*v, tl, tm);
ll v2=get(l, r, 2*v+1, tm+1, tr);
return max(v1, v2);
}

void work(ll pl)
{
ll l=las[pl]+1;
ll r=pl;
add(l, r, 1, 0, s-1, 1);
if (pl>=k-1)
  cout<<get(pl-k+1, pl, 1, 0, s-1)<<' ';
}

void write()
{
if (!viv)
  return;
cout<<"Segment tree:"<<endl;
for (ll i=1; i<2*s; i++)
  cout<<"{"<<t[i].max<<' '<<t[i].push<<"} ";
cout<<endl;
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
prepare();
if (viv)
  {
  cout<<"Better:"<<endl;
  for (auto i:las)
    cout<<i<<' ';
  cout<<endl;
  }
for (ll i=0; i<n; i++)
  work(i);


    return 0;
}