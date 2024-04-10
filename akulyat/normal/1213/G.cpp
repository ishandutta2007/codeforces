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
const long long gs=500*kk;

long n,m,i,j, q;
ll kol;
vector <long> reb[gs+10];
vector <ll> col,tc, p, sz;
vector <pair <ll, pll>> rebs;
vector <pll> ar;
bool viv=false;

void prepare()
{
for (ll i=0; i<n; i++)
  p.push_back(i), sz.push_back(1);
}

ll par(ll v)
{
if (p[v]==v)
  return v;
return par(p[v]);
}

ll ckol(ll n)
{
return (n*(n-1))/2;
}

void merge(ll a, ll b)
{
ll pa=par(a);
ll pb=par(b);
if (pa==pb)
  return;
a=pa;
b=pb;
if (sz[a]<sz[b])
  swap(a, b);
if (viv)
  cout<<"merge "<<pa<<' '<<pb<<endl,
  cout<<""<<sz[pa]<<' '<<sz[pb]<<endl;
kol-=ckol(sz[a]);
kol-=ckol(sz[b]);
if (viv)
  cout<<'-'<<sz[a];
if (viv)
  cout<<'-'<<sz[b];

sz[a]+=sz[b];
sz[b]=0;
p[b]=a;
kol+=ckol(sz[a]);
if (viv)
  cout<<'+'<<sz[a]<<endl;
}

void answer()
{
for (ll i=0; i<q; i++)
  {
  ll w;
  cin>>w;
  ll z=upper_bound(ar.begin(), ar.end(), make_pair(w, inf))-ar.begin();
  z--;
  if (z<0)
    cout<<0<<' ';
  else
    cout<<ar[z].S<<' ';
  }
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>q;
m=n-1;
for (i=0; i<m; i++)
  {
  long a,b, c;
  cin>>a>>b>>c;
  a--; b--;
  rebs.push_back({c, {a, b}});
  }
prepare();
sort(rebs.begin(), rebs.end());
kol=0;
for (ll i=0; i<m; i++)
  {
  merge(rebs[i].S.F, rebs[i].S.S);
  ar.push_back({rebs[i].F, kol});
  }
answer();




    return 0;
}