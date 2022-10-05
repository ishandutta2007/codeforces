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
const long long gs=20*kk;

long n,m,i,j,na,nb;
vector <long> reb[gs+10];
vector <ll> col,tc,p;
set <ll> a,b;
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

ll ask(ll b, ll x)
{
cout<<char('A'+b)<<' '<<x+1<<endl;
ll v;
cin>>v;
v--;
return v;
}

void solve()
{
cin>>n;
for (i=0; i<n; i++)
  reb[i].clear();
for (i=0; i<n-1; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
a.clear();
cin>>na;
for (ll i=0; i<na; i++)
  {
  ll v;
  cin>>v;
  v--;
  a.insert(v);
  }
b.clear();
cin>>nb;
for (ll i=0; i<nb; i++)
  {
  ll v;
  cin>>v;
  v--;
  b.insert(v);
  }
col.clear();
col.resize(n);
for (auto &i:col) i=-1;

ll v=ask(1, *b.begin());
if (a.find(v)!=a.end())
  {
  cout<<'C'<<' '<<v+1<<endl;
  return;
  }
ll s=*a.begin();
p.clear();
p.assign(n, v);
DFS(v, 0);
while (a.find(p[s])!=a.end())
  s=p[s];
ll should=ask(0, s);
if (b.find(should)==b.end())
  {
  cout<<'C'<<' '<<-1<<endl;
  return;
  }
cout<<'C'<<' '<<s+1<<endl;
return;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t)
  solve(), t--;

    return 0;
}