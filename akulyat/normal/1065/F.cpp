#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long gs=kk*kk+kk;

long n,m,i,j,k;
vector <long> reb[gs+10];
vector <ll> por;
ll endin[gs+10];
ll ans[gs+10];
ll have[gs+10];
ll back[gs+10];
ll near[gs+10];
ll p[gs][23];
long long col[gs+10];
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

void poryadok()
{
for (i=0; i<n; i++)
  col[i]=-1;
DFS(0, 0);
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
for (auto i:tos)
  por.push_back(i.S);
}

void binup()
{
ll i,j,v;
for (v=0; v<n; v++)
  {
  for (auto s:reb[v])
    if (col[s]<col[v])
      p[v][0]=s;
  }
p[0][0]=0;
for (j=1; j<22; j++)
  for (i=0; i<n; i++)
    p[i][j]=p[p[i][j-1]][j-1];
}

void found(ll v)
{
if (v==0)
  return;
if (reb[v].size()>1)
  return;
ll l=k;
if (col[v]<l)
  return;
ll cur=v;
for (j=0; j<=20; j++)
  {
  if (l&1)
    cur=p[cur][j];
  l>>=1;
  }
endin[cur]++;
}

void count(ll v)
{
vector <ll> kids;
for (auto s:reb[v])
  if (col[s]>col[v])
    kids.push_back(s);
if (kids.empty())
  {ans[v]=1; have[v]=1; back[v]=1; near[v]=0; return;}
near[v]=mod;
for (auto s:kids)
  near[v]=min(near[v], near[s]+1);
for (auto s:kids)
  if (near[s]<k)
    ans[s]-=back[s],
    back[v]+=back[s];
ans[v]=back[v];
vector <ll> w;
for (auto s:kids)
  w.push_back(ans[s]);
ll add=0;
for (auto i:w)
  add=max(add, i);
ans[v]+=add;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=1; i<n; i++)
  {
  long a,b;
  cin>>b;
  a=i; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }

poryadok();
//binup();
//for (i=0; i<n; i++)
//  found(i);
for (auto i:por)
  count(i);
cout<<ans[0]<<endl;
 /*
for (i=0; i<n; i++)
  cout<<ans[i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<back[i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<near[i]<<' ';
cout<<endl;
// */
    return 0;
}
/*
12 2
1 1 2 2 2 3 3 4 4 6 7

14 2
1 1 1 1 1 2 5 6 7 8 9 12 13

*/