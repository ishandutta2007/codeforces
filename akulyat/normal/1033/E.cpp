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

long long n,m,i,j,full,k0,k1,rm;
vector <long> reb[gs+10];
vector <ll> path,gp;
vector <ll> p[2];
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

void good(vector <ll> p)
{
cout<<"Y "<<p.size()<<endl;
for (auto i:p)
  cout<<i+1<<' ';
cout<<endl;
exit(0);
}

void bad(vector <ll> p)
{
cout<<"N "<<p.size()<<endl;
for (auto i:p)
  cout<<i+1<<' ';
cout<<endl;
exit(0);
}

void DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    DFS(s, c);
  }
}

void DFS2(long v, long c, long v2)
{
col[v]=c;
path.push_back(v);
if (v==v2)
  gp=path;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    DFS2(s, c, v2);
  }
path.pop_back();
}

void bipart(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    bipart(s, c^1);
  }
}

vector <ll> seg(ll l, ll r)
{
vector <ll> v;
for (ll i=l; i<=r; i++)
  v.push_back(i);
return v;
}

vector <ll> segw(ll l, ll r, ll x)
{
vector <ll> v;
for (ll i=l; i<=r; i++)
  if (i!=x)
    v.push_back(i);
return v;
}

ll ask(vector <ll> gr)
{
if (gr.size()<2)
  return 0;
cout<<"? "<<gr.size()<<endl;
for (auto i:gr)
  cout<<i+1<<' ';
cout<<endl;
ll edges;
cin>>edges;
return edges;
}

void partner(ll v)
{
ll l=0;
ll r=n-1;
while (l<r)
  {
  ll m=l+r>>1;
  vector <ll> a=segw(l, m, v);
  vector <ll> b=seg(l, m);
  if (v<l||m<v)
    b.push_back(v);
  ll kol=ask(a)-ask(b);
  if (kol)
    r=m;
  else
    l=m+1;
  }
if (viv)
  cout<<"Friends: "<<v+1<<' '<<l+1<<endl;
reb[v].push_back(l);
reb[l].push_back(v);
m++;
}

void found()
{
for (i=0; i<n; i++)
  col[i]=-1;
ll tc=0;
for (i=0; i<n; i++)
  if (col[i]==-1)
    DFS(i, tc), tc++;

vector <ll> a,b;
for (i=0; i<n; i++)
  if (col[i])
    b.push_back(i);
  else
    a.push_back(i);

ll l=0;
ll r=b.size()-1;
ll ins=ask(a);
while (l!=r)
  {
  ll m=l+r>>1;
  vector <ll> a1=a;
  vector <ll> b1;
  for (ll i=l; i<=m; i++)
    b1.push_back(b[i]);
  ll ins2=ask(b1);
  for (auto i:b1)
    a1.push_back(i);
  ll kol=ask(a1)-ins-ins2;
  if (kol)
    r=m;
  else
    l=m+1;
  }
ll v1=b[l];

l=0;
r=a.size()-1;
while (l!=r)
  {
  ll m=l+r>>1;
  vector <ll> a1;
  for (ll i=l; i<=m; i++)
    a1.push_back(a[i]);
  ll ins=ask(a1);
  a1.push_back(v1);
  ll kol=ask(a1)-ins;
  if (kol)
    r=m;
  else
    l=m+1;
  }
ll v2=a[l];
reb[v1].push_back(v2);
reb[v2].push_back(v1);
m++;
}


void bp(vector <ll> p)
{
vector <ll> f;
ll full=ask(p);
for (ll i=0; i<p.size(); i++)
  {
  vector <ll> a;
  for (j=0; j<p.size(); j++)
    if (j!=i)
      a.push_back(p[j]);
  f.push_back(full-ask(a));
  }
ll v1=0;
while (!f[v1])
  v1++;

ll v2=0;
for (i=0; i<p.size(); i++)
  if (i!=v1)
    if (ask({p[v1], p[i]}))
      v2=i, i=p.size();
v1=p[v1];
v2=p[v2];
for (i=0; i<n; i++)
  col[i]=-1;
DFS2(v1, 0, v2);
bad(gp);
}


int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
//cin>>rm;
if (n==1)
  {
  cout<<"Y "<<1<<endl;
  cout<<1<<endl;
  return 0;
  }

full=ask(seg(0, n-1));
for (i=0; i<n; i++)
  if (reb[i].empty())
    partner(i);
if (viv)
  {
  cout<<"After finding of partner:"<<endl;
  for (i=0; i<n; i++)
    {
    cout<<i<<": ";
    for (auto s:reb[i])
      cout<<s<<' ';
    cout<<endl;
    }
  }

while (n-1-m)
  found();
if (viv)
  {
  cout<<"After tree building:"<<endl;
  for (i=0; i<n; i++)
    {
    cout<<i<<": ";
    for (auto s:reb[i])
      cout<<s<<' ';
    cout<<endl;
    }
  }

for (i=0; i<n; i++)
  col[i]=-1;
bipart(0, 0);

if (viv)
  {
  cout<<"After coloring:"<<endl;
  for (i=0; i<n; i++)
    cout<<col[i]<<' ';
  cout<<endl;
  }

for (i=0; i<n; i++)
  if (col[i])
    p[0].push_back(i);
  else
    p[1].push_back(i);

if (viv)
  {
  cout<<"Parts are:"<<endl;
  for (auto i:p[0])
    cout<<i<<' ';
  cout<<endl;
  for (auto i:p[1])
    cout<<i<<' ';
  cout<<endl;
  }

k0=ask(p[0]);
k1=ask(p[1]);
if (!k0&&!k1)
  good(p[0]);

if (k0)
  bp(p[0]);
else
  bp(p[1]);

    return 0;
}