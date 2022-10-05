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

ll n,m,i,j, k;
ll ans;
vector <long> reb[gs+10];
vector <ll> col,tc;
vector <vector <ll> > here;
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
here[c].push_back(v);
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c);
    }
  }
}

void vic(ll kol, ll step)
{
ll res=1;
for (ll i=0; i<step ;i++)
  res*=kol, res%=mod;
ans-=res;
ans%=mod;
if (ans<0)
  ans+=mod;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
m=n-1;
for (i=0; i<m; i++)
  {
  long a,b,c;
  cin>>a>>b>>c;
  a--; b--;
  if (c==0)
    {
    reb[a].push_back(b);
    reb[b].push_back(a);
    }
  }
col.assign(n, -1);
ll tc=0;
for (ll i=0; i<n; i++)
  if (col[i]==-1)
    here.push_back({}), DFS(i, tc), tc++;

ans=1;
for (ll i=0; i<k; i++)
  ans*=n, ans%=mod;
for (ll j=0; j<tc; j++)
  vic(here[j].size(), k);
cout<<ans;










    return 0;
}