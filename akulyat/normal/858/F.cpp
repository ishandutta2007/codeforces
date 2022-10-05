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

long n,m,i,j;
vector <long> reb[gs+10];
vector <long> kid[gs+10];
set <pll> was;
set <ll> par;
vector <ll> ans,p;
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
    p[s]=v;
    DFS(s, c+1);
    }
  }
}

void work (ll v)
{
vector <ll> w;
for (auto s:reb[v])
    if (col[s]>col[v])
      if (was.find({v, s})==was.end()&&was.find({s, v})==was.end())
        w.push_back(s);
while (w.size()>1)
  {
  ans.push_back(w.back());
  w.pop_back();
  ans.push_back(v);
  ans.push_back(w.back());
  w.pop_back();
  }
if (!w.size()||par.find(v)!=par.end())
  return;

ll ost=w.back();
was.insert({p[v], v});
was.insert({v, p[v]});
ans.push_back(ost);
ans.push_back(v);
ans.push_back(p[v]);
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
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

for (i=0; i<n; i++)
  p.push_back(0);
for (i=0; i<n; i++)
  if (col[i]==-1)
    {
    par.insert(i);
    DFS(i, 0);
    }
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
vector <ll> por;
for (auto i:tos)
  por.push_back(i.S);

for (auto v:por)
  work(v);

cout<<ans.size()/3<<endl;
for (i=0; i<ans.size(); i++)
  {
  cout<<ans[i]+1<<' ';
  if (i%3==2)
    cout<<endl;
  }
 /*
cout<<"Information:"<<endl;
for (i=0; i<n; i++)
  cout<<col[i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<p[i]<<' ';
cout<<endl;
// */
    return 0;
}