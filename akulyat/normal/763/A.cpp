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

long n,m,i,j, number;
vector <long> reb[gs+10];
vector <ll> col,tc, ord, num, sz;
vector <bool> good;
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

vector <ll> get_order()
{
DFS(0, 0);
vector <pll> tos;
for (ll i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.begin(), tos.end());
vector <ll> res;
for (auto i:tos)
  res.push_back(i.S);
reverse(res.begin(), res.end());
return res;
}

void check(ll v)
{
sz[v]=1;
for (auto s:reb[v])
  if (col[s]>col[v])
    good[v]=good[v]&good[s], good[v]=good[v]&(tc[v]==tc[s]), sz[v]+=sz[s];
}

void tr(ll v)
{
bool cont=true;
for (auto s:reb[v])
  if (col[s]>col[v])
    {
    if (!good[s])
      cont=false;
    num[tc[s]]-=sz[s];
    if (num[tc[s]]==0)
      number--;
    }
num[tc[v]]--;
if (num[tc[v]]==0)
  number--;
if (number>1)
  cont=false;
/**
cout<<v<<' '<<number<<": ";
for (i=0; i<3; i++)
  cout<<num[i]<<' ';
cout<<endl;
**/
for (auto s:reb[v])
  if (col[s]>col[v])
    {
    if (num[tc[s]]==0)
      number++;
    num[tc[s]]+=sz[s];
    }
if (num[tc[v]]==0)
  number++;
num[tc[v]]++;
if (!cont)
  return;

cout<<"YES\n";
cout<<v+1;
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m=n-1;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
col.resize(n, -1);
tc.resize(n, -1);
sz.resize(n, 0);
num.resize(100*kk, 0);
for (auto &i:tc)
  cin>>i, i--, num[i]++;
for (auto i:num)
  if (i)
    number++;
/**
cout<<"OOO "<<' '<<number<<": ";
for (i=0; i<3; i++)
  cout<<num[i]<<' ';
cout<<endl;
**/
ord=get_order();
good.resize(n, true);
for (auto i:ord)
  check(i);
for (auto i:ord)
  tr(i);
cout<<"NO";


    return 0;
}