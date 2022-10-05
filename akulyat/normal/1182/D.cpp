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
const long long gs=500*kk;

long n,m,i,j, lp1, lp2, mid;
vector <long> reb[gs+10];
vector <ll> col,tc, por, p;
vector <pll> down;
vector <pair <ll, pll>> lonp;
vector <bool> online;
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

vector <ll> get_por()
{
vector <pll> tos;
for (ll i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.begin(), tos.end());
vector <ll> res;
for (auto i:tos)
  res.push_back(i.S);
return res;
}

void work(ll v)
{
vector <ll> kids;
for (auto sos:reb[v])
  if (col[sos]>col[v])
    kids.push_back(sos);
vector <pll> tos;
tos.push_back({0, v});
tos.push_back({0, v});
for (auto sos:kids)
  tos.push_back({down[sos].F+1, down[sos].S});
sort(tos.rbegin(), tos.rend());
down[v]=tos[0];
lonp[v].F=tos[0].F+tos[1].F+1;
lonp[v].S.F=tos[0].S;
lonp[v].S.S=tos[1].S;
}

void prepare()
{
DFS(0, 0);
por=get_por();
reverse(por.begin(), por.end());
down.resize(n);
lonp.resize(n);
for (auto v:por)
  work(v);
if (viv)
  {
  for (auto i:down)
    cout<<i.F<<' '<<i.S<<"; ";
  cout<<endl;
  for (auto i:lonp)
    cout<<i.F<<' '<<i.S.F<<' '<<i.S.S<<"; ";
  cout<<endl;
  }

vector <pll> tos;
for (ll i=0; i<n; i++)
  tos.push_back({lonp[i].F, i});
sort(tos.rbegin(), tos.rend());
ll par=tos[0].S;
lp1=lonp[par].S.F;
lp2=lonp[par].S.S;
}

void reroot(ll root)
{
col.clear();
col.resize(n, -1);
p.clear();
p.resize(n, -1);
DFS(root, 0);
p[root]=root;
}

ll find_middle()
{
ll now=lp2;
ll st_lev=col[now];
while (col[now]*2>st_lev)
  now=p[now];
return now;
}

void check_online(ll v)
{
online[v]=online[p[v]];
tc[v]=1;
if (v!=mid)
  if (reb[v].size()>2)
    online[v]=false;
for (auto sos:reb[v])
  if (tc[sos]==-1)
    check_online(sos);
}

vector <ll> find_vis()
{
reroot(mid);
vector <pll> tos;
online.resize(n, false);
online[mid]=true;
check_online(mid);
for (ll i=0; i<n; i++)
  if (reb[i].size()==1&&online[i])
    {
    ll sos=reb[i][0];
    if (col[sos]<col[i])
      tos.push_back({col[i], i});
    }
sort(tos.begin(), tos.end());
vector <ll> res;
for (auto i:tos)
  res.push_back(i.S);
return res;
}

void check(ll v)
{
set <ll> on_lev[n+3];
reroot(v);
for (ll i=0; i<n; i++)
  {
  on_lev[col[i]].insert(reb[i].size());
  if (on_lev[col[i]].size()>1)
    return;
  }
if (viv)
  cout<<"Answer: ";
cout<<v+1<<endl;
if (!viv)
  exit(0);
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
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
col.assign(n, -1);
p.assign(n, -1);
tc.assign(n, -1);
prepare();
reroot(lp1);
mid=find_middle();
check(mid);
vector <ll> vis=find_vis();
for (ll i=0; i<3; i++)
  if (i<vis.size())
    check(vis[i]);
for (ll i=0; i<3; i++)
  if ((ll)vis.size()-1-i>=0)
    check(vis[vis.size()-1-i]);
cout<<-1<<endl;
if (viv)
  {
  cout<<"Middle is "<<mid<<endl;
  cout<<"Longest path points are "<<lp1<<' '<<lp2<<endl;
  }

    return 0;
}