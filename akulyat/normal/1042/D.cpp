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

vector <ll> t[ml];
ll n,i,j,s,k;
vector <ll> m;
bool viv=false;

vector <ll> merge(vector <ll> a, vector <ll> b)
{
vector <ll> r;
a.push_back(inf);
b.push_back(inf);
reverse(a.begin(), a.end());
reverse(b.begin(), b.end());
while (a.size()+b.size()>2)
  if (a.back()<=b.back())
    r.push_back(a.back()), a.pop_back();
  else
    r.push_back(b.back()), b.pop_back();
return r;
}

void build()
{
s=1;
while (s<n)
  s*=2;
for (i=0; i<n; i++)
  t[i+s].push_back(m[i]);
for (i=s-1; i>0; i--)
  t[i]=merge(t[2*i], t[2*i+1]);
}

ll get(ll l, ll r, ll tl, ll tr, ll v, ll need)
{
if (r<tl||tr<l)
  return 0;

if (l<=tl&&tr<=r)
  return tr-tl+1-(upper_bound(t[v].begin(), t[v].end(), need)-t[v].begin());

ll tm=tl+tr>>1;
return get(l, r, tl, tm, 2*v, need)+get(l, r, tm+1, tr, 2*v+1, need);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
m.push_back(0);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a+m.back());
  }
n++;
build();
ll ans=0;
for (i=1; i<n; i++)
  {
  ll need=m[i]-k;
  ans+=get(0, i-1, 0, s-1, 1, need);
  }
cout<<ans<<endl;

    return 0;
}