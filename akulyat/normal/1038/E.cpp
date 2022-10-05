#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
//typedef long long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long gs=1*kk;

struct vertex
{
  ll c,b,a;
};

long long n,m,i,j;
ll ans;
vector <long> reb[gs+10];
vector <ll> self;
vector <ll> all;
vector <vertex> dop;
ll kol[5][5];
vector <ll> w[5][5];
long long col[gs+10];
long long tc[gs+10];
bool can[5][5];
bool viv=false;

bool cmp(vertex a, vertex b)
{
if (a.c<b.c)
  return true;
if (a.c>b.c)
  return false;
if (a.a<b.a)
  return true;
if (a.a>b.a)
  return false;
if (a.b<b.b)
  return true;
if (a.b>b.b)
  return false;
return true;
}

void DFS(long long v, long long c)
{
col[v]=c;
long long l=reb[v].size();
for (long long i=0; i<l; i++)
  {
  long long s=reb[v][i];
  if (col[s]==-1&&can[v][s])
    {
    DFS(s, c);
    }
  }
}


bool bad(ll j)
{
ll i;
ll a=dop[j].a;
ll b=dop[j].b;
//cout<<a<<' '<<b<<endl;
if (kol[a][b]==1)
  can[a][b]=false,
  can[b][a]=false;
for (i=0; i<4; i++)
  col[i]=-1;
DFS(0, 0);
can[a][b]=true;
can[b][a]=true;
//for (i=0; i<4; i++)
//  cout<<col[i]<<' ';
//cout<<endl;
for (i=0; i<4; i++)
  if (col[i]==-1)
    return true;
return false;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<4; i++)
  for (j=0; j<4; j++)
    can[i][j]=true;
for (i=0; i<4; i++)
  self.push_back(0);
for (i=0; i<n; i++)
  {
  long long a,b,c;
  cin>>a>>c>>b;
  a--; b--;
  if (a==b)
    self[a]+=c;
  else
    reb[a].push_back(b),
    reb[b].push_back(a),
    kol[a][b]++,
    kol[b][a]++,
    w[a][b].push_back(c),
    w[b][a].push_back(c),
    all.push_back(c),
    dop.push_back({c, a, b});
  }
sort(all.begin(), all.end());
sort(dop.begin(), dop.end(), cmp);
//for (i=0; i<dop.size(); i++)
//  cout<<dop[i].c<<' '<<dop[i].a<<' '<<dop[i].b<<endl;
for (i=0; i<4; i++)
  col[i]=-1,
  sort(reb[i].begin(), reb[i].end());

ll tc=0;
for (i=0; i<4; i++)
  if (col[i]==-1)
    DFS(i, tc), tc++;

if (tc==1)
  {
  ans=0;
  for (i=0; i<4; i++)
    ans+=self[i];
  ll st=1;
  for (i=0; i<4; i++)
    if (!(reb[i].size()&1))
      st=0;
  vector <ll> r;
  for (i=0; i<4; i++)
    r.push_back(reb[i].size());
  sort(r.begin(), r.end());
  if (r[0]==1&&r[1]==1&&r[2]==1&&r[3]==3)
    {
    vector <ll> pot(4, 0);
    for (i=0; i<4; i++)
      pot[i]+=self[i];
    for (i=0; i<4; i++)
      for (j=0; j<4; j++)
        for (auto v:w[i][j])
          pot[i]+=v;
    sort(pot.begin(), pot.end());
    for (auto v:all)
      ans+=v;
    ans-=pot[0];
    cout<<ans;
    return 0;
    }
  if (st==1)
    {
    ll j=0;
    while (bad(j))
      j++;
    ans+=all[0];
    ans-=all[j];
    }
  for (i=st; i<all.size(); i++)
    ans+=all[i];
  cout<<ans;
  return 0;
  }

for (ll u=0; u<tc; u++)
  {
  ll lans=0;
  for (i=0; i<4; i++)
    if (col[i]==u)
      lans+=self[i];
  for (i=0; i<4; i++)
    for (j=i+1; j<4; j++)
      if (col[i]==col[j]&&col[i]==u)
        for (auto v:w[i][j])
          lans+=v;
  ans=max(ans, lans);
  }
cout<<ans<<endl;
/*
for (i=0; i<4; i++)
  cout<<col[i]<<' ';
cout<<endl;
for (i=0; i<4; i++)
  cout<<self[i]<<' ';
cout<<endl;
for (i=0; i<4; i++)
  {
  for (auto s:reb[i])
    cout<<s<<' ';
  cout<<endl;
  }
*/


    return 0;
}