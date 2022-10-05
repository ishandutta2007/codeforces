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
const long long gs=200*kk;

long long n,m,i,j,ans,L,S;
vector <long> reb[gs+10];
ll p[20][gs];
ll w[20][gs];
vector <ll> wp,up;
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

void read()
{
cin>>n>>L>>S;
m=n-1;
for (ll i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  wp.push_back(a);
  if (wp.back()>S)
    {
    cout<<-1;
    exit(0);
    }
  }
for (ll i=1; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  reb[a].push_back(i);
  reb[i].push_back(a);
  }
}

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

vector <ll> sorted()
{
for (i=0; i<n; i++)
  col[i]=-1;
DFS(0, 0);
vector <pll> tos;
for (ll i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
vector <ll> por;
for (auto i:tos)
  por.push_back(i.S);
return por;
}

void parents()
{
for (ll v=0; v<n; v++)
  for (auto s:reb[v])
    if (col[s]<col[v])
      p[0][v]=s, w[0][v]=wp[s];
w[0][0]=inf;
for (ll j=1; j<20; j++)
  for (ll v=0; v<n; v++)
    {
    ll s=p[j-1][v];
    p[j][v]=p[j-1][s],
    w[j][v]=w[j-1][v]+w[j-1][s],
    w[j][v]=min(w[j][v], inf);
    }
for (ll i=0; i<n; i++)
  up.push_back(inf);
}

void build(ll v)
{
ll vost=L;
vost--;
ll wost=S;
wost-=wp[v];
ll add=1LL<<19;
ll cur=v;
for (ll j=19; j>=0; j--)
  {
  if (add<=vost&&w[j][cur]<=wost)
    {
    wost-=w[j][cur];
    vost-=add;
    cur=p[j][cur];
    }
  add>>=1;
  }
up[v]=cur;
}

void work(ll v)
{
vector <ll> kids;
for (auto s:reb[v])
  if (col[s]>col[v])
    kids.push_back(s);
if (kids.size())
  ans+=kids.size()-1;

ll upto=inf;
for (auto s:kids)
  if (up[s]<=v)
    upto=min(upto, up[s]);
if (upto==inf)
  {
  if (kids.size())
    ans++;
  build(v);
  return;
  }
up[v]=upto;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
vector <ll> por=sorted();
parents();

for (auto i:por)
  work(i);
ans++;
cout<<ans<<endl;

//viv=true;
if (viv)
  {
  for (i=0; i<n; i++)
    cout<<'{'<<p[0][i]<<' '<<w[0][i]<<'}'<<' ';
  cout<<endl;
  for (auto i:por)
    cout<<i<<' ';
  cout<<endl;
  for (auto i:up)
    cout<<i<<' ';
  cout<<endl;
  for (ll v=0; v<n; v++)
    {
    cout<<v<<": ";
    for (auto s:reb[v])
      cout<<s<<' ';
    cout<<endl;
    }
  for (i=0; i<n; i++)
    cout<<col[i]<<' ';
  cout<<endl;
  }




    return 0;
}