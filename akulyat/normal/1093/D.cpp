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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;
const long long gs=500*kk;

long n,m,i,j;
ll cur;
vector <vector <ll> > reb;
vector <ll> col,tc,st,st3,was,have;
bool viv=false;
bool bad;

void DFS(long v, long c)
{
col[v]=c;
have.push_back(v);
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

void prepare()
{
st.push_back(1);
for (ll i=0; i<400*kk; i++)
  st.push_back(st.back()*2), st.back()%=mod;
st3.push_back(1);
for (ll i=0; i<400*kk; i++)
  st3.push_back(st3.back()*3), st3.back()%=mod;
}

void solve()
{
cin>>n>>m;
reb.clear();
reb={};
reb.assign(n, {});
for (ll i=0; i<m; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
col.clear();
col.assign(n, -1);
bad=false;
ll ans=1;
for (ll i=0; i<n; i++)
  if (col[i]==-1)
    {
    have.clear();
    DFS(i, 0);
    ll a=0,b=0;
    for (auto i:have)
      if (col[i]&1)
        a++;
      else
        b++;
    ll lans=st[a]+st[b];
    if (have.size()==1)
      lans=3;
    for (auto v:have)
      for (auto s:reb[v])
        if ((col[v]&1)==(col[s]&1))
          lans=0;
    lans%=mod;
    ans*=lans;
    ans%=mod;
    }
cout<<ans<<'\n';
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
prepare();
while (t)
  {
  solve();
  t--;
  }








    return 0;
}