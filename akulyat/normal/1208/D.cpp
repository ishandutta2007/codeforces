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
vector <ll> m, ans;
bool viv=false;

struct vertex
{
  ll v, push;
};

ll s;
vector <ll> t;

void build()
{
s=1;
while (s<n)
  s<<=1;
t.resize(2*s);

ll cntr=0;
for (ll i=0; i<n; i++)
  t[s+i]=cntr, cntr+=(i+1);
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



void work()
{
for (ll i=n-1; i>=0; i--)
  {
  ll l=0;
  ll r=n;
  while (l+1<r)
    {
    ll mi=l+r>>1;
    ll val=get(mi);
    if (val<=m[i])
      l=mi;
    else
      r=mi;
    }
  ans.push_back(l+1);
  add(ans.back(), n-1, 1, 0, s-1, -ans.back());
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
build();
work();
reverse(ans.begin(), ans.end());
for (auto i:ans)
  cout<<i<<' ';



    return 0;
}