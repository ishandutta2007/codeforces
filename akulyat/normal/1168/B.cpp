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
const vector <ll> mod={ml*kk+7, 998244353};
const vector <ll> con={2, 2};
const long long inf=ml*ml*ml+7;
const ll K=2;

ll n,i,j, ans;
string s;
vector <ll> st[K];
vector <ll> h, h2;
vector <pll> seg;
bool viv=false;

void change()
{
reverse(s.begin(), s.end());
for (auto &i:s)
  if (i=='0')
    i='1';
  else
    i='0';
}

void prepare()
{
for (ll i=0; i<K; i++)
  {
  st[i].push_back(1);
  for (ll i=0; i<ml/2; i++)
    st[i].push_back((st[i].back()*con[i])%mod[i]);
  }
for (ll i=0; i<K; i++)
  {
  h.push_back(0);
  for (ll i=0; i<n; i++)
    {
    h.push_back(h.back());
    h.back()*=con[i];
    if (s[i]=='1')
      h.back()++;
    h.back()%=mod[i];
    }
  }
change();
for (ll i=0; i<K; i++)
  {
  h2.push_back(0);
  for (ll i=0; i<n; i++)
    {
    h2.push_back(h2.back());
    h2.back()*=con[i];
    if (s[i]=='1')
      h2.back()++;
    h2.back()%=mod[i];
    }
  }

change();
}

pll has(ll l, ll r)
{
vector <ll> var;
for (ll i=0; i<K; i++)
  {
  ll res=h[r+1]-((h[l]*st[i][r-l])%mod[i]);
  while (res<0)
    res+=mod[i];
  while (res>=mod[i])
    res-=mod[i];
  var.push_back(res);
  }
pll res={var[0], var[1]};
return res;
}

pll has2(ll l, ll r)
{
vector <ll> var;
for (ll i=0; i<K; i++)
  {
  ll res=h2[r+1]-((h2[l]*st[i][r-l])%mod[i]);
  while (res<0)
    res+=mod[i];
  while (res>=mod[i])
    res-=mod[i];
  var.push_back(res);
  }
pll res={var[0], var[1]};
return res;
}

bool same(ll pl, ll rad)
{
ll l1=pl-rad;
ll r1=pl-1;
ll r2=pl+rad;
ll l2=pl+1;
l1=n-1-l1;
r1=n-1-r1;
swap(l1, r1);
if (has(l2, r2)==has2(l1, r1))
  return true;
return false;
}

void add(ll pl)
{
ll l=0;
ll r=max(pl, n-1-pl);
if (same(pl, r))
  return;
while (l+1<r)
  {
  ll mi=l+r>>1;
  if (same(pl, mi))
    l=mi;
  else
    r=mi;
  }
if (viv)
  {
  cout<<"For "<<pl<<" add "<<pl-r<<' '<<pl+r<<endl;
  }
seg.push_back({pl-r, pl+r});
}

void solve()
{
for (auto &pr:seg)
  swap(pr.F, pr.S);
sort(seg.begin(), seg.end());
reverse(seg.begin(), seg.end());
ll r=0;
ll maxi=-1;
ll ans=0;
for (ll i=0; i<n; i++)
  {
  while (r<n&& maxi<i)
    {
    r++;
    while (seg.size()&&seg.back().F==r)
      {
      maxi=max(maxi, seg.back().S);
      seg.pop_back();
      }
    }
  if (maxi>=i)
    ans+=n-r;
  }
cout<<ans<<endl;
}

void check(ll l)
{
if (viv)
  cout<<"Work "<<l<<' '<<s[l]<<endl;
string ss;
ss+=s[l];
ll r=l;
bool cont=true;
while (cont&&r<n)
  {
  r++;
  if (r!=n)
    ss+=s[r];
  for (ll lol=(ll)ss.size()-3; lol>=0; lol-=2)
    if (ss[lol]==ss.back()&&ss[lol]==ss[(lol+ss.size()-1)/2])
      cont=false;
  }
if (viv)
  cout<<"have "<<l<<' '<<r<<' '<<ss<<endl;
ans-=(r-l);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>s;
n=s.size();
ans=(n*(n+1))/2;
for (ll i=0; i<n; i++)
  check(i);
cout<<ans<<endl;
/**
prepare();
for (ll i=0; i<n; i++)
  add(i);
solve();
**/




    return 0;
}
/**





**/