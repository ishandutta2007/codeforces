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

ll t[ml];
ll n,q,i,j,zero,full,s;
vector <ll> m;
bool viv=false;

void build()
{
s=1;
while (s<n)
  s*=2;
for (i=0; i<n; i++)
  t[i+s]=m[i];
for (i=n; i<s; i++)
  t[i+s]=inf;
for (i=s-1; i>0; i--)
  t[i]=min(t[2*i], t[2*i+1]);
}

ll get(ll l, ll r, ll tl, ll tr, ll v)
{
if (r<tl||tr<l)
  return inf;
if (l<=tl&&tr<=r)
  return t[v];
ll tm=tr+tl>>1;
ll lv=get(l, r, tl, tm, 2*v);
ll rv=get(l, r, tm+1, tr, 2*v+1);
return min(lv, rv);
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>q;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  if (a==0)
    zero++;
  if (a==q)
    full++;
  m.push_back(a);
  }
m.push_back(1);

if (full==0&&zero==0)
  {
  cout<<"NO"<<endl;
  return 0;
  }

if (full==0)
  for (i=0; i<n; i++)
    if (m[i]==0)
      m[i]=q, i=n;

for (i=n; i>=0; i--)
  if (m[i]==0)
    m[i]=m[i+1];

vector <ll> l(q+1, -1);
vector <ll> r(q+1, -1);
for (i=0; i<n; i++)
  {
  r[m[i]]=i;
  if (l[m[i]]==-1)
    l[m[i]]=i;
  }

m.pop_back();
build();
for (i=1; i<=q; i++)
  if (l[i]!=-1)
    {
    if (get(l[i], r[i], 0, s-1, 1)!=i)
      {
      cout<<"NO"<<endl;
      return 0;
      }
    }

cout<<"YES"<<endl;
for (auto i:m)
  cout<<i<<' ';





    return 0;
}