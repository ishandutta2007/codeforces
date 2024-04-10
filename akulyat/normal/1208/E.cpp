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


ll n,i,j, w;
vector <vector <ll> > m;
bool viv=false;

ll s;
vector <ll> t;

build()
{
s=1;
while (s<w)
  s<<=1;
t.resize(2*s);
}

ll get(ll pl)
{
pl+=s;
ll res=0;
while (pl)
  {
  res+=t[pl];
  pl>>=1;
  }
return res;
}

void add(ll l, ll r, ll v, ll tl, ll tr, ll val)
{
if (r<tl||tr<l)
  return;
if (l<=tl&&tr<=r)
  {
  t[v]+=val;
  return;
  }

ll tm=tl+tr>>1;
add(l, r, 2*v, tl, tm, val);
add(l, r, 2*v+1, tm+1, tr, val);
}

void easy(vector <ll> v)
{
ll n=v.size();
vector <ll> pr=v;
for (ll i=1; i<pr.size(); i++)
  pr[i]=max(pr[i], pr[i-1]);
vector <ll> suf=v;
for (ll i=(ll)suf.size()-2; i>=0; i--)
  suf[i]=max(suf[i], suf[i+1]);

if (viv)
  {
  for (auto i:v)
    cout<<i<<' ';
  cout<<endl;
  for (auto i:pr)
    cout<<i<<' ';
  cout<<endl;
  for (auto i:suf)
    cout<<i<<' ';
  cout<<endl;
  }

for (ll i=0; i<pr.size(); i++)
  t[s+i]+=max(0ll, pr[i]);
for (ll i=0; i<suf.size(); i++)
  t[s+w-1-i]+=max(0ll, suf[suf.size()-1-i]);
add(pr.size(), w-1-suf.size(), 1, 0, s-1, max(0ll, pr.back()));
}

void hard(vector <ll> v)
{
ll n=v.size();
ll wind=w-v.size()+1;
ll r=-1;
ll l=r-wind;

vector <ll> nex;
nex.resize(v.size());
nex.back()=w+1;
vector <ll> st(1, v.size()-1);
for (ll i=(ll)v.size()-2; i>=0; i--)
  {
  while (st.size()&&v[st.back()]<=v[i])
    st.pop_back();
  if (st.empty())
    nex[i]=w+1;
  else
    nex[i]=st.back();
  st.push_back(i);
  }

if (viv)
  {
  cout<<"Array: ";
  for (auto i:v)
    cout<<i<<' ';
  cout<<endl;
  cout<<"Next: ";
  for (auto i:nex)
    cout<<i<<' ';
  cout<<endl;
  }

ll mini=0;
for (ll i=0; i<w; i++)
  {
  mini=max(mini, i-wind+1);
  if (viv)
    cout<<"now mini="<<mini<<" with val="<<v[mini]<<endl;
  while (nex[mini]<=i)
    mini=nex[mini];
  bool need=true;
  if (v[mini]<0)
    if (i+1+v.size()<=w||i>v.size()-1)
      t[i+s]+=0, need=false;
  if (need)
    t[i+s]+=v[mini];
  }
}

void show()
{
vector <ll> ans;
for (ll i=0; i<w; i++)
  ans.push_back(get(i));
for (auto i:ans)
  cout<<i<<' ';
}

void read()
{
cin>>n>>w;
for (ll i=0; i<n; i++)
  {
  m.push_back({});
  ll k;
  cin>>k;
  for (ll j=0; j<k; j++)
    {
    ll a;
    cin>>a;
    m.back().push_back(a);
    }
  }
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
build();
for (ll i=0; i<n; i++)
  if (2*m[i].size()>w)
    hard(m[i]);
  else
    easy(m[i]);
show();

    return 0;
}