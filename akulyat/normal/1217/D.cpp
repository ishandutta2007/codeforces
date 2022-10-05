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
vector <ll> col,tc;
vector <pll> all;
bool viv=false;
bool was;


void DFS(long v)
{
col[v]=1;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==1)
    was=true;
  if (col[s]==-1)
    DFS(s);
  }
col[v]=2;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  all.push_back({a, b});
  }
col.assign(n, -1);
was=false;
for (ll i=0; i<n; i++)
  if (col[i]==-1)
    DFS(i);

vector <ll> ans(m, 1);
ll num=1;
if (was)
  {
  for (ll i=0; i<m; i++)
    if (all[i].F>all[i].S)
      ans[i]=2;
  num=2;
  }

cout<<num<<endl;
for (auto i:ans)
  cout<<i<<' ';




    return 0;
}