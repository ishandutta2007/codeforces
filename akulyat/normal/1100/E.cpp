#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long    ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long gs=500*kk;

long n,m,i,j,to,ti;
vector <long> reb[gs+10];
vector <long> c[gs+10];
vector <ll> col,tc,tin,tout;
vector <pll> allr;
bool viv=false;
bool nor;

void DFS(long v)
{
col[v]=1;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  long cost=c[v][i];
  if (col[s]==1&&cost>to)
    nor=false;
  if (col[s]==-1&&cost>to)
    {
    DFS(s);
    }
  }
col[v]=2;
}

void DFS2(long v)
{
tin[v]=ti; ti++;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  long cost=c[v][i];
  if (tin[s]==-1&&cost>to)
    {
    DFS2(s);
    }
  }
tout[v]=ti; ti++;
}

bool wc(ll pr)
{
to=pr;
nor=true;
for (ll i=0; i<n; i++)
  col[i]=-1;
for (ll i=0; i<n; i++)
  if (col[i]==-1)
    DFS(i);
return nor;
}

void work(ll pr)
{
to=pr;
tin.assign(n, -1);
tout.assign(n, -1);
ti=0;
for (ll i=0; i<n; i++)
  if (tin[i]==-1)
    DFS2(i);
vector <pll> tos;
for (ll i=0; i<n; i++)
  tos.push_back({tout[i], i});
sort(tos.rbegin(), tos.rend());
vector <ll> por;
for (auto i:tos)
  por.push_back(i.S);
//viv=true;
if (viv)
  {
  cout<<"Por: ";
  for (auto i:por)
    cout<<i<<' ';
  cout<<endl;
  }
vector <ll> tc(n);
for (ll i=0; i<n; i++)
  tc[por[i]]=i;
vector <ll> ans;
for (ll i=0; i<m; i++)
  {
  ll a=allr[i].F;
  ll b=allr[i].S;
  if (tc[b]<tc[a])
    ans.push_back(i+1);
  }
cout<<ans.size()<<endl;
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long a,b,pr;
  cin>>a>>b>>pr;
  a--; b--;
  reb[a].push_back(b);
  c[a].push_back(pr);
  allr.push_back({a, b});
  }
col.assign(n, -1);
tc.assign(n, -1);

ll l=-1;
ll r=mod;
while (l+1<r)
  {
  ll mi=l+r>>1;
  if (wc(mi))
    r=mi;
  else
    l=mi;
  }
cout<<r<<' ';
work(r);


    return 0;
}