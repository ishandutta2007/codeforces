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

long n,m,i,j;
vector <long> reb[gs+10];
vector <ll> col,tc,por,s,kol,w,t,ans;
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

vector <ll> upor()
{
vector <pll> tos;
for (ll i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.begin(), tos.end());
vector <ll> r;
for (auto i:tos)
  r.push_back(i.S);
return r;
}

void work(ll v)
{
s[v]=w[v];
kol[v]=1;
for(auto sos:reb[v])
  if (col[sos]>col[v])
    s[v]+=s[sos],
    kol[v]+=kol[sos],
    t[v]+=(t[sos]+s[sos]);
}

void count(ll v)
{
if (v==0)
  return;
ll p=0;
for (auto sos:reb[v])
  if (col[sos]<col[v])
    p=sos;
ans[v]=t[v]+(ans[p]-t[v]-s[v]*1)+(s[0]-s[v])*1;
if (viv)
  cout<<v<<' '<<p<<' '<<t[v]<<' '<<ans[p]<<' '<<s[v]*1<<' '<<s[0]<<' '<<s[v]<<endl;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m=n-1;
w.resize(n);
for (auto &i:w)
  cin>>i;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
col.assign(n, -1);
s.assign(n, 0);
kol.assign(n, 0);
t.assign(n, 0);
ans.assign(n, 0);
DFS(0, 0);
por=upor();
reverse(por.begin(), por.end());
for (auto i:por)
  work(i);
ans[0]=t[0];
reverse(por.begin(), por.end());
for (auto i:por)
  count(i);
cout<<*max_element(ans.begin(), ans.end());

    return 0;
}