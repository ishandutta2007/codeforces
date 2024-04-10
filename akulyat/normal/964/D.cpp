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
const long long gs=500*kk;
long n,m,i,j;
vector <long> reb[gs+10];
vector <long> kid[gs+10];
long long root;
long long col[gs+10];
long long tc[gs+10];
long long par[gs+10];
vector <bool> good;
vector <ll> ans;
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1);
    }
  }
}

bool check(ll v)
{
ll l=kid[v].size();
ll kol=0;
for (ll i=0; i<l; i++)
  {
  ll s=kid[v][i];
  if (good[s])
    kol++;
  }
if (kol&1)
  return false;
return true;
}

void go(ll v)
{
if (viv)
  cout<<"I voshel v "<<v<<endl;
ll l=kid[v].size();
for (ll i=0; i<l; i++)
  {
  ll s=kid[v][i];
  if (!good[s])
    go(s);
  }
ans.push_back(v);
for (ll i=0; i<l; i++)
  {
  ll s=kid[v][i];
  if (good[s])
    go(s);
  }
}


int main()
{
//viv=true;
cin>>n;
m=n-1;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  par[i]=a;
  if (a!=-1)
    {
    kid[a].push_back(i);
    reb[a].push_back(i);
    reb[i].push_back(a);
    }
  else
    root=i;
  }
for (i=0; i<n; i++)
  col[i]=-1;

for (i=0; i<n; i++)
  tc[i]=-1;

DFS(root, 0);

set <pll> tos;
for (i=0; i<n; i++)
  tos.insert({col[i], i});
vector <ll> work;
for (auto i:tos)
  work.push_back(i.S);
for (i=0; i<n; i++)
  good.push_back(false);
for (i=n-1; i>=0; i--)
  {
  ll v=work[i];
  good[v]=check(v);
  }

if (!good[root])
  {
  cout<<"NO"<<endl;
  return 0;
  }
if (viv)
  for (i=0; i<n; i++)
    {
    for (auto j:kid[i])
      cout<<j<<' ';
    cout<<endl;
    }

go(root);

cout<<"YES"<<endl;
for (auto i:ans)
  cout<<++i<<'\n';
cout<<endl;

if (viv)
  {
  for (auto i:good)
    cout<<i<<' ';
  cout<<endl;
  }

    return 0;
}