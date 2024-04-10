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
bool viv=false;

ll will()
{
set <pair <ll, pll>> can;
for (auto p:reb[v1])
  can.insert({p.S, {v1, p.F}});
vector <ll> hard(n, -1);
while (can.size())
  {
  auto z=*can.begin();
  ll add=z.S.S;
  ll was=z.S.F;
  ll nw=z.F;
  hard[add]=max(hard[was], nw);
  for (auto pr:reb[add])
    {
    if (can.find({pr.S, {pr.F, add}})!=can.end())
      can.erase({pr.S, {pr.F, add}});
    else
      can.insert({pr.S, {add, pr.F}});
    }
  }
if (viv)
  {
  for (auto i:hard)
    cout<<i<<' ';
  cout<<endl;
  }
ll kol=0;
for (auto i:hard)
  if (i==-1)
    kol++;
if (kol>1)
  return mod-7;
return hard[v2];
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
  if (i)
    {
    reb[a].push_back({b, c});
    reb[b].push_back({a, c});
    }
  else
    v1=a, v2=b;
  }
col.assign(n, -1);
tc.assign(n, -1);

cout<<will();





    return 0;
}