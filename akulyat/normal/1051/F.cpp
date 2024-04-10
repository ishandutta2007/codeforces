#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
//typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long gs=101*kk;

long n,m,i,j,t;
vector <long> reb[gs+10];
vector <ll> w[gs+10];
vector <vector <ll> > ld;
ll p[gs+10][22];
long long col[gs+10];
long long black[gs+10];
long long grey[gs+10];
long long l[gs+10];
long long tc[gs+10];
bool viv=false;

void DFS(long v, long c, ll len)
{
grey[v]=t; t++;
col[v]=c;
l[v]=len;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  ll nl=w[v][i];
  if (col[s]==-1)
    {
    p[s][0]=v;
    DFS(s, c+1, len+nl);
    }
  }
black[v]=t; t++;
}

void Dij(ll v)
{
ll i;
vector <ll> col(n, inf);
col[v]=0;
set <pll> st;
for (i=0; i<n; i++)
  st.insert({col[i], i});
while (st.size())
  {
  ll v=(*st.begin()).S;
  for (ll i=0; i<reb[v].size(); i++)
    {
    ll s=reb[v][i];
    ll nl=w[v][i];
    if (col[s]>col[v]+nl)
      {
      pll a={col[s], s};
      pll b={col[v]+nl, s};
      col[s]=col[v]+nl;
      st.erase(a);
      st.insert(b);
      }
    }
  st.erase(st.begin());
  }
ld.push_back(col);
}

ll com(ll a, ll b)
{
ll na=a;
ll nb=b;
if (grey[na]<=grey[nb]&&black[na]>=black[nb])
  return na;
if (grey[nb]<=grey[na]&&black[nb]>=black[na])
  return nb;

ll j=19;
while (j>=0)
  {
  ll v=p[na][j];
  if (!(grey[v]<=grey[nb]&&black[v]>=black[nb]))
    na=v;
  j--;
  }
na=p[na][0];
return na;
}

void solve(ll a, ll b)
{
ll ans=0;
ans=l[a]+l[b];
ll c=com(a, b);
ans-=2*l[c];
for (ll i=0; i<ld.size(); i++)
  {
  ll lans=ld[i][a]+ld[i][b];
  ans=min(ans, lans);
  }
cout<<ans<<'\n';
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long a,b,c;
  cin>>a>>b>>c;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  w[a].push_back(c);
  w[b].push_back(c);
  }
for (i=0; i<n; i++)
  col[i]=-1;

ll t=0;
DFS(0, 0, 0);
p[0][0]=0;
for (j=1; j<20; j++)
  for (i=0; i<n; i++)
    p[i][j]=p[p[i][j-1]][j-1];

set <ll> was;
for (i=0; i<n; i++)
  for (auto s:reb[i])
    if (p[s][0]!=i&&p[i][0]!=s)
      {
//      cout<<"not {"<<i<<' '<<s<<"} in the tree"<<endl;
      if (was.find(s)==was.end()&&was.find(i)==was.end())
        {
//        cout<<s<<':'<<endl;
        Dij(s), was.insert(s);
/*
        for (auto i:ld.back())
          cout<<i<<' ';
        cout<<endl;
*/
        }
      }
ll q;
cin>>q;
while (q)
  {
  ll a,b;
  cin>>a>>b;
  a--, b--;
  solve(a, b);
  q--;
  }
/*
for (i=0; i<n; i++)
  cout<<p[i][0]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<l[i]<<' ';
cout<<endl;
*/



    return 0;
}