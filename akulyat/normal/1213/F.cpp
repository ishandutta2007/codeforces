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


ll n,i,j, k, tc;
vector <ll> p1, p2;
bool viv=false;
vector <vector <ll>> reb, reb2;
vector <ll> col, q, comp, colc, rest, buk;
vector <vector <ll>> incl;

void bad()
{
cout<<"NO"<<endl;
exit(0);
}

void DFS(ll v)
{
col[v]=1;
for (auto s:reb[v])
  if (col[s]==-1)
    DFS(s);
q.push_back(v);
}

void DFS2(ll v, ll lc)
{
comp[v]=lc;
incl[lc].push_back(v);
for (auto s:reb[v])
  if (comp[s]==-1)
    DFS2(s, lc);
}

void DFS3(ll c)
{
colc[c]=1;
for (auto s:reb2[c])
  if (colc[s]==-1)
    DFS3(s);
rest.push_back(c);
}

void build()
{
for (ll i=0; i<n-1; i++)
  reb[p1[i]].push_back(p1[i+1]);
for (ll i=0; i<n-1; i++)
  reb[p2[i]].push_back(p2[i+1]);
col.resize(n, -1);
for (ll i=0; i<n; i++)
  if (col[i]==-1)
    DFS(i);

comp.resize(n, -1);
tc=0;

for (auto v:q)
  if (comp[v]==-1)
    incl.push_back({}), DFS2(v, tc), tc++;
buk.resize(tc, -1);

if (tc<k)
  bad();

reb2.resize(tc);
for (ll i=0; i<n; i++)
  {
  for (auto s:reb[i])
    {
    ll c1=comp[i];
    ll c2=comp[s];
    if (c1!=c2)
      reb2[c1].push_back(c2);
    }
  }
colc.resize(tc, -1);
for (ll i=0; i<tc; i++)
  if (colc[i]==-1)
    DFS3(i);
reverse(rest.begin(), rest.end());
for (ll i=0; i<rest.size(); i++)
  buk[rest[i]]=i;
}

void show()
{
string ans;
ans.resize(n, '0');
for (ll i=0; i<tc; i++)
  {
  for (auto pl:incl[i])
    ans[pl]=char('a'+min(buk[i], 25ll));
  }
cout<<"YES"<<endl;
cout<<ans<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
reb.resize(n);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  p1.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  p2.push_back(a);
  }
build();

show();



    return 0;
}