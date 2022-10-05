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



ll n,i,j,l,pl;
vector <ll> m,p;
vector <bool> have;
bool viv=false;
map <ll, ll> numb;


vector <long long> erat(long long last)
{
vector <bool> bad;
vector <long long> r;
for (long long i=0; i<last+10; i++)
  bad.push_back(true);
for (long long i=2; i<=last; i++)
  if (bad[i])
    {
    long long j=2;
    while (j*i<=last)
      {
      bad[j*i]=false;
      j++;
      }
    r.push_back(i);
    }
return r;
}

bool can(ll v)
{
if (viv)
  cout<<"In "<<v<<": ";
ll v1=v;
vector <ll> prd;
for (ll j=2; j<ll(sqrt(v)+3); j++)
  if (j*j<=v)
    if (!(v1%j))
      {
      prd.push_back(j);
      while (!(v1%j))
        v1/=j;
      }
if (v1-1)
  prd.push_back(v1);
if (viv)
  {
  for (auto u:prd)
    cout<<u<<' ';
  cout<<endl;
  }

ll l=prd.size();
for (auto i:prd)
  if (have[numb[i]])
    return false;

for (auto i:prd)
  have[numb[i]]=true;
return true;
}

ll change(ll v)
{
while (!can(v))
  v++;
return v;
}

int main()
{
//viv=true;
p=erat(10*ml);
if (viv)
  {
  for (i=0; i<10; i++)
    cout<<p[i]<<' ';
  cout<<endl;
  }
l=p.size();
for (i=0; i<l; i++)
  numb[p[i]]=i;

cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (auto i:p)
  have.push_back(false);
pl=n;
for (i=0; i<n; i++)
  {
  if (can(m[i]))
    cout<<m[i]<<' ';
  else
    {
    ll z=m[i];
//    cout<<change(m[i]);
/*
    ll z=lower_bound(p.begin(), p.end(), m[i]+1)-p.begin();
    while (have[z])
      z++;
    have[z]=true;
    cout<<p[z]<<' ';
*/
    while (!can(z))
      z++;
    cout<<z<<' ';
    pl=i+1;
    i=n;
    }
  if (viv)
    {
    for (ll j=0; j<10; j++)
      cout<<have[j];
    cout<<endl;
    }
  }
ll j=0;
for (i=pl; i<n; i++)
  {
  while (have[j])
    j++;
  cout<<p[j]<<' ';
  j++;
  }

    return 0;
}

/*
5
2 3 5 4 13
*/