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

long n,m,st,i,j;
vector <long> reb[gs+10];
vector <long> kid[gs+10];
vector <ll> p;
long long col[gs+10];
long long tc[gs+10];
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

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>st;
st--;
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
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
vector <ll> por;
for (auto i:tos)
  por.push_back(i.S);

for (i=0; i<n; i++)
  {
  p.push_back(0);
  for (auto s:reb[i])
    {
    if (col[s]<col[i])
      p[i]=s;
    else
      kid[i].push_back(s);
    }
  }
vector <ll> longest(n, 0);
for (auto v:por)
  for (auto s:kid[v])
    longest[v]=max(longest[v], longest[s]+1);

ll ans=col[i]*2;
vector <ll> path;
j=st;
while (j!=0)
  path.push_back(j), j=p[j];
path.push_back(0);
reverse(path.begin(), path.end());
ll len=path.size();
while (path.size())
  {
  ll v=path.back();
  path.pop_back();
  if (col[v]>=((col[st]+2)/2))
    ans=max(ans, 2*(col[v]-1)+2*longest[v]+2);
  }
cout<<ans;

    return 0;
}