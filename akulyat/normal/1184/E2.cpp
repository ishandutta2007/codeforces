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

long n,m,i,j, v1, v2;
vector <vector <pll>> reb;
vector <ll> col,tc;
vector <ll> p, up;
vector <vector <ll>> pr, ma;
vector <pll> l;
vector <ll> st;
bool viv=false;



ll build()
{
set <pair <ll, pll>> can;
for (auto p:reb[0])
  can.insert({p.S, {0, p.F}});
vector <ll> hard(n, -1);
while (can.size())
  {
  auto z=*can.begin();
  ll add=z.S.S;
  ll was=z.S.F;
  ll nw=z.F;
  col[add]=col[was]+1;
  p[add]=was;
  up[add]=nw;
  hard[add]=max(hard[was], nw);
  for (auto pr:reb[add])
    {
    if (can.find({pr.S, {pr.F, add}})!=can.end())
      can.erase({pr.S, {pr.F, add}});
    else
      can.insert({pr.S, {add, pr.F}});
    }
  }
}

void Pbuild()
{
pr.resize(n);
for (auto &v:pr)
  v.resize(20);
ma.resize(n);
for (auto &v:ma)
  v.resize(20);
for (ll i=0; i<n; i++)
  pr[i][0]=p[i];
for (ll i=0; i<n; i++)
  ma[i][0]=up[i];
for (ll i=0; i<19; i++)
  {
  for (ll v=0; v<n; v++)
    pr[v][i+1]=pr[pr[v][i]][i];
  for (ll v=0; v<n; v++)
    ma[v][i+1]=max(ma[v][i], ma[pr[v][i]][i]);
  }
st.push_back(1);
for (ll i=1; i<20; i++)
  st.push_back(st.back()*2);
}

ll work(ll a, ll b)
{
ll mama=-1;
for (ll i=19; i>=0; i--)
  if (col[a]-st[i]>=col[b])
    {
    mama=max(mama, ma[a][i]);
    a=pr[a][i];
    }
for (ll i=19; i>=0; i--)
  if (col[b]-st[i]>=col[a])
    {
    mama=max(mama, ma[b][i]);
    b=pr[b][i];
    }
if (a==b)
  return mama;
for (ll i=19; i>=0; i--)
  if (pr[a][i]!=pr[b][i])
    {
    mama=max(mama, ma[b][i]);
    mama=max(mama, ma[a][i]);
    b=pr[b][i];
    a=pr[a][i];
    }
mama=max(mama, up[a]);
mama=max(mama, up[b]);
return mama;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n>>m;
reb.resize(n);
for (i=0; i<m; i++)
  {
  long a,b, c;
  cin>>a>>b>>c;
  a--; b--;
  reb[a].push_back({b, c});
  reb[b].push_back({a, c});
  l.push_back({a, b});
  }
col.assign(n, -1);
tc.assign(n, -1);
p.assign(n, 0);
up.assign(n, 0);
for (ll i=0; i<n; i++)
  p[i]=i;
build();
Pbuild();

for (auto v:l)
  {
  if (p[v.F]!=v.S&&p[v.S]!=v.F)
    cout<<work(v.F, v.S)<<'\n';
  else
    if (viv)
      cout<<"In MST"<<endl;
  }






    return 0;
}