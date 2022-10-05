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


ll t[800*kk+100];
ll n,s,i,j,k,sum,kol,ans;
vector <ll> m;
bool viv=false;

void build()
{
s=1;
while (s<n)
  s*=2;
for (ll i=0; i<n; i++)
  t[i+s]=m[i];
for (ll i=s-1; i>0; i--)
  t[i]=t[2*i]+t[2*i+1];
}

ll get(ll l, ll r, ll tl, ll tr, ll v)
{
if (r<tl||tr<l)
  return 0;
if (l<=tl&&tr<=r)
  return t[v];
ll tm=tr+tl>>1;
ll res=0;
res+=get(l, r, tl, tm, 2*v);
res+=get(l, r, tm+1, tr, 2*v+1);
return res;
}


void erase(ll v)
{
if (viv)
  cout<<"Delete "<<v<<endl;
sum-=m[v];
ll p=v+s;
while (p)
  {
  t[p]-=m[v];
  p/=2;
  }
kol--;
m[v]=0;
}

void work()
{
if (viv)
  {
  cout<<k<<' '<<sum<<' '<<endl;
  for (ll i=0; i<n+s; i++)
    cout<<t[i]<<' ';
  cout<<endl;
  }
ll l=-1;
ll r=n-1;
while (l+1<r)
  {
  ll m=l+r>>1;
  ll sum=get(0, m, 0, s-1, 1);
  if (viv)
    cout<<"Sum "<<0<<' '<<m<<' '<<sum<<endl;
  if (sum<=k)
    l=m;
  else
    r=m;
  }

erase(r);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  sum+=a;
  }
build();
kol=n;
ans=0;
while (kol)
  {
  ans+=(k/sum)*kol;
  k%=sum;
  while (k<sum)
    work();
  }
cout<<ans<<endl;


    return 0;
}