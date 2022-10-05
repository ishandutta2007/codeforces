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

long n,m,i,j, s, b, k, h;
vector <long> reb[gs+10];
vector <vector <ll>> dist;
vector <pair <ll, pll>> putin;
vector <pll> navalny;

vector <ll> edros;
vector <bool> was;

vector <vector <ll>> p_reb, n_reb;
vector <ll> col,tc;
bool viv=false;

void BFS(long v)
{
vector <long> st;
st.push_back(v);
long s=0;
tc[v]=0;

while (s<st.size())
  {
  long e=st[s];
  long l=reb[e].size();
  for (long i=0; i<l; i++)
    {
    long s=reb[e][i];
    if (tc[s]==-1)
      {
      st.push_back(s);
      tc[s]=tc[e]+1;
      }
    }
  s++;
  }
}

void all_dist()
{
for (ll i=0; i<n; i++)
  {
  tc.clear();
  tc.resize(n, -1);
  BFS(i);
  dist.push_back(tc);
  }
}


void make_edges()
{
p_reb.resize(s);
n_reb.resize(b);
if (viv)
  cout<<"Let's work"<<endl;
for (ll i=0; i<s; i++)
  for (ll j=0; j<b; j++)
    if (putin[i].S.F>=navalny[j].S)
      if (dist[putin[i].F][navalny[j].F]<=putin[i].S.S)
        p_reb[i].push_back(j),
        n_reb[j].push_back(i);
if (viv)
  {
  cout<<"Put:"<<endl;
  for (auto vec:p_reb)
    {
    for (auto e:vec)
      cout<<e<<' ';
    cout<<endl;
    }
  cout<<"Nav:"<<endl;
  for (auto vec:n_reb)
    {
    for (auto e:vec)
      cout<<e<<' ';
    cout<<endl;
    }
  }
}


bool kuhn(ll er)
{
if (viv)
  cout<<"Try found for er="<<er<<endl;
if (was[er])
  return false;
was[er]=true;
for (auto fbk:p_reb[er])
  if (edros[fbk]==-1||kuhn(edros[fbk]))
    {
    edros[fbk]=er;
    if (viv)
      cout<<"OK "<<er<<" on "<<fbk<<endl;
    return true;
    }
return false;
}

ll max_matching()
{
make_edges();
edros.resize(b, -1);
was.resize(s);
ll lans=0;
for (ll i=0; i<s; i++)
  {
  for (j=0; j<was.size(); j++)
    was[j]=false;
  if (kuhn(i))
    lans++;
  }
if (viv)
  {
  cout<<"Answer is "<<lans<<endl;
  for (auto i:edros)
    cout<<i<<' ';
  cout<<endl;
  }
return lans;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
all_dist();
if (viv)
  {
  for (auto v:dist)
    {
    for (auto d:v)
      cout<<d<<' ';
    cout<<endl;
    }
  }

cin>>s>>b>>k>>h;
for (ll i=0; i<s; i++)
  {
  ll a, b, c;
  cin>>a>>b>>c;
  a--;
  putin.push_back({a, {b, c}});
  }
for (ll i=0; i<b; i++)
  {
  ll a, b;
  cin>>a>>b;
  a--;
  navalny.push_back({a, b});
  }

ll mm=max_matching();
ll ans=inf;
for (ll i=0; i<=s; i++)
  {
  ll lans=0;
  lans+=min(i, mm)*k;
  lans+=(s-i)*h;
  ans=min(ans, lans);
  }
cout<<ans;


    return 0;
}
/**
6 7
1 2
2 3
3 4
4 6
6 5
4 4
3 6
4 2 7 8
1 10 2
3 8 2
5 1 0
6 5 4
3 7
5 2



**/