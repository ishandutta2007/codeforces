#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long	 ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const long long gs=1100*kk;

long n,m,i,j;
vector <long> reb[gs+10];
vector <vector <ll>> kids;
vector <ll> col,tc, p, q, link, ans, gans;
vector <unordered_map <ll, ll>> cnt;
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
    kids[v].push_back(s);
		DFS(s, c+1);
		}
	}
q.push_back(v);
}

void lst(ll v)
{
cnt[v][col[v]]=1;
ans[v]=col[v];
gans[v]=0;
}

void add(ll v, pll p)
{
cnt[v][p.F]+=p.S;
if (cnt[v][p.F]>cnt[v][ans[v]]||cnt[v][p.F]==cnt[v][ans[v]]&&p.F<ans[v])
  ans[v]=p.F;
}

void work(ll v)
{
if (viv)
  cout<<"Work "<<v<<endl;
if (kids[v].empty())
  {lst(v); return;}
pll lans={-1, v};
for (auto k:kids[v])
  if (ans[link[k]]>lans.F)
    lans.F=ans[link[k]], lans.S=link[k];
link[v]=lans.S;
for (auto k:kids[v])
  if (link[k]!=link[v])
    {
    for (pll p:cnt[link[k]])
      add(link[v], p);
    }
add(link[v], {col[v], 1});
gans[v]=ans[link[v]]-col[v];
}

int main()
{
//viv=true;
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
col.assign(n, -1);
p.assign(n, 0);
ans.assign(n, -1);
gans.assign(n, -1);
kids.resize(n);
cnt.resize(n);
for (ll i=0; i<n; i++)
  link.push_back(i);
DFS(0, 0);

for (auto v:q)
  work(v);

for (auto i:gans)
  cout<<i<<' ';





		return 0;
}