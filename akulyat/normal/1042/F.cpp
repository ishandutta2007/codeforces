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
const long long gs=kk*kk;

long n,m,i,j,k;
vector <long> reb[gs+10];
vector <ll> len,ans;
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


void solve(ll v)
{
vector <ll> kids;
for (auto s:reb[v])
  if (col[s]>col[v])
    kids.push_back(s);
if (kids.size()==0)
  {
  ans[v]=1;
  len[v]=0;
  return;
  }
if (kids.size()==1)
  {
  ll s=kids[0];
  ans[v]=ans[s];
  len[v]=len[s]+1;
  return;
  }
for (auto s:kids)
  ans[v]+=ans[s];
vector <pll> m;
for (auto s:kids)
  m.push_back({len[s], s});
sort(m.begin(), m.end());
while (m.size()>1&&m.back().F+m[m.size()-2].F>k-2)
  m.pop_back();
ans[v]-=(m.size()-1);
len[v]=m.back().F+1;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
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

ll st=0;
for (i=0; i<n; i++)
  if (reb[i].size()>1)
    st=i;

DFS(st, 0);
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
vector <ll> por;
for (auto i:tos)
  por.push_back(i.S);

for (i=0; i<n; i++)
  len.push_back(inf),
  ans.push_back(0);
for (auto v:por)
  solve(v);
cout<<ans[st]<<endl;
//viv=true;
if (viv)
  {
  for (auto i:por)
    cout<<i<<' ';
  cout<<endl;
  for (i=0; i<n; i++)
    cout<<ans[i]<<' ';
  cout<<endl;
  for (i=0; i<n; i++)
    cout<<len[i]<<' ';
  cout<<endl;
  }

    return 0;
}