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
vector <ll> m, pl;
vector <pll> d;
bool viv=false;

void swapa(ll a, ll b)
{
//cout<<"AAAAAAAA "<<a<<' '<<b<<endl;
if (a==b)
  return;
swap(pl[m[a]], pl[m[b]]);
swap(m[a], m[b]);
d.push_back({a, b});
}

void work(ll val)
{
if (pl[val]>=n/2)
  swapa(0, pl[val]);
else
  swapa(n-1, pl[val]);

if ((pl[val]==0)^(val>=n/2))
  swapa(0, n-1);

swapa(pl[val], val);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
pl.resize(n);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  pl[a]=i;
  m.push_back(a);
  }
for (ll i=1; i<n-1; i++)
  work(i);

//viv=true;
if (viv)
  {
  cout<<"Kuk ";
  for (auto i:m)
    cout<<i<<' ';
  cout<<endl;
  }
if (m[0]!=0)
  swapa(0, n-1);
cout<<d.size()<<endl;
for (auto p:d)
  cout<<p.F+1<<' '<<p.S+1<<'\n';





    return 0;
}