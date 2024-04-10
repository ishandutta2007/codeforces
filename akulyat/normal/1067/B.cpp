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

long n,m,i,j,k,v,trl;
vector <long> reb[gs+10];
vector <ll> por;
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

void bad()
{
  cout<<"No";
  exit(0);
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

void pora()
{
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
por.clear();
for (auto i:tos)
  por.push_back(i.S);
}

ll findv()
{
ll v=0;
vector <ll> la(n, 0);
vector <ll> lb(n, 0);
for (auto v:por)
  {
  for (auto s:reb[v])
    if (col[s]>col[v])
      {
      if (la[s]+1>=la[v])
        lb[v]=la[v], la[v]=la[s]+1;
      else
        if (la[s]+1>=lb[v])
          lb[v]=la[s]+1;
      }
  }
ll len=la[0]+lb[0];
if (len&1)
  bad();
trl=len/2;
if (la[0]==lb[0])
  return 0;
ll st=0;
for (i=0; i<n; i++)
  if (col[i]==la[0])
    st=i;
while (col[st]!=la[0]-trl)
  for (ll i=0; i<reb[st].size(); i++)
    if (col[reb[st][i]]<col[st])
      st=reb[st][i], i=ml;
return st;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
if (n<=3)
  bad();
m=n-1;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
for (i=0; i<n; i++)
  col[i]=-1;

DFS(0, 0);
pora();

v=findv();
for (i=0; i<n; i++)
  col[i]=-1;
DFS(v, 0);
pora();
if (reb[v].size()<3)
  bad();
if (trl!=k)
  bad();
for (i=0; i<n; i++)
  {
  ll kids=0;
  for (auto s:reb[i])
    if (col[s]>col[i])
      kids++;
  if (kids<=2&&kids!=0)
    bad();
  if (kids==0&&col[i]!=trl)
    bad();
  if (col[i]>trl)
    bad();
  }

cout<<"Yes";








    return 0;
}