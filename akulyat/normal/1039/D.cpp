#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long    ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long gs=500*kk;

long n,m,i,j;
vector <long> reb[gs+10];
vector <ll> ans,por;
long long col[gs+10];
long long tc[gs+10];
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
    DFS(s, c+1);
    }
  }
}

void update(ll &f, ll &s, ll t)
{
ll ma=max(f, t);
ll mi=min(s, t);
s=f+s+t-ma-mi;
f=ma;
}

void zap(ll k)
{
vector <ll> lans(n, 0);
vector <ll> ost(n, 1);

for (auto v:por)
  {
  ll f=0,se=0;
  for (auto s:reb[v])
    if (col[s]>col[v])
      {
      lans[v]+=lans[s];
      update(f, se, ost[s]);
      }
  ost[v]=f+1;
  if (f+se+1>=k)
    {
    ost[v]=0;
    lans[v]++;
    }
  }
ans[k]=lans[por.back()];
if (viv)
  {
  cout<<k<<':'<<endl;
  for (i=0; i<n; i++)
    cout<<lans[i]<<' ';
  cout<<endl;
  for (i=0; i<n; i++)
    cout<<ost[i]<<' ';
  cout<<endl;
  cout<<"Local answer="<<ans[k]<<endl;
  }
}

void work(ll l, ll r)
{
if (viv)
  cout<<"Work "<<l<<' '<<r<<endl;
if (ans[l]==-1)
  zap(l);
if (ans[r]==-1)
  zap(r);
if (ans[l]==ans[r])
  {
  for (ll i=l+1; i<r; i++)
    ans[i]=ans[l];
  return;
  }
ll m=l+r>>1;
if (m!=r)
  work(l, m);
if (m!=l)
  work(m, r);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
for (i=0; i<n; i++)
  col[i]=-1;

DFS(0, 0);
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
for (auto i:tos)
  por.push_back(i.S);
for (i=0; i<=n; i++)
  ans.push_back(-1);
ans[1]=n;
ll z=ll(sqrt(n));
z+=2;
z=min((ll)n, z);
for (i=2; i<=z; i++)
  zap(i);
work(z, n);
for (i=1; i<=n; i++)
  cout<<ans[i]<<'\n';

    return 0;
}