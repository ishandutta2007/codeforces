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

long n,m,i,j, c, q;
vector <long> reb[gs+10];
vector <unordered_map <ll, ll> > have;
vector <set <ll>> nb;
vector <ll> col,tc, par, sz;
bool viv=false;


void prepare()
{
for (ll i=0; i<n; i++)
  par.push_back(i);
sz.resize(n, 1);
nb.resize(n);
have.resize(n);
}

ll lead(ll v)
{
if (par[v]==v)
  return v;
par[v]=lead(par[v]);
return par[v];
}

void merge(ll v1, ll v2)
{
if (v1==v2)
  return;
if (sz[v1]+nb[v1].size()<sz[v2]+nb[v2].size())
  swap(v1, v2);
sz[v1]+=sz[v2];
sz[v2]=0;
par[v2]=v1;
for (auto v:nb[v2])
  nb[v1].insert(v);
}

void add(ll v1, ll v2, ll cr)
{
if (have[v1].find(cr)!=have[v1].end())
  merge(lead(v2), lead(have[v1][cr]));
if (have[v2].find(cr)!=have[v2].end())
  merge(lead(v1), lead(have[v2][cr]));
nb[lead(v1)].insert(v2);
nb[lead(v2)].insert(v1);
have[v1][cr]=v2;
have[v2][cr]=v1;
}

bool exist(ll st, ll fin)
{
if (lead(st)==lead(fin))
  return true;
ll v=lead(st);
if (nb[v].find(fin)!=nb[v].end())
  return true;
return false;
}

void qrs()
{
for (ll i=0; i<q; i++)
  {
  string str;
  cin>>str;
  if (str=="+")
    {
    ll a, b, c;
    cin>>a>>b>>c;
    a--, b--, c--;
    add(a, b, c);
    }
  else
    {
    ll a, b;
    cin>>a>>b;
    a--, b--;
    if (exist(a, b))
      cout<<"Yes\n";
    else
      cout<<"No\n";
    }
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>c>>q;
prepare();
for (i=0; i<m; i++)
  {
  long a,b, c;
  cin>>a>>b>>c;
  a--; b--; c--;
  add(a, b, c);
  }
qrs();







    return 0;
}