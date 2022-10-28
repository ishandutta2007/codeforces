#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=3e5+5;

int n, m, q, farthest, maxlvl;
int root[N], sz[N], diam[N], vis[N];
vector<int> g[N];

void dfs(int k, int par, int lvl)
{
	vis[k]=1;
	if(lvl>maxlvl)
	{
		maxlvl=lvl;
		farthest=k;
	}
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
}

void init()
{
	for(int i=1;i<=n;i++)
	{
		root[i]=i;
		sz[i]=1;
	}
}

int rt(int k)
{
	while(k!=root[k])
	{
		root[k]=root[root[k]];
		k=root[k];
	}
	return k;
}

void union1(int u, int v)
{
	int root1=rt(u);
	int root2=rt(v);
	if(root1==root2)
		return;
	if(sz[root1]>=sz[root2])
	{
		sz[root1]+=sz[root2];
		sz[root2]=0;
		int pos_diam=max(diam[root1], diam[root2]);
		diam[root1]=diam[root1]/2 + diam[root2]/2 + 1 + diam[root1]%2 + diam[root2]%2; 
		diam[root1]=max(diam[root1], pos_diam);
		root[root2]=root[root1];
	}
	else
	{
		sz[root2]+=sz[root1];
		sz[root1]=0;
		int pos_diam=max(diam[root1], diam[root2]);
		diam[root2]=diam[root1]/2 + diam[root2]/2 + 1 + diam[root1]%2 + diam[root2]%2; 
		diam[root2]=max(diam[root2], pos_diam);
		root[root1]=root[root2];
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>q;
	init();
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
		union1(u, v);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		maxlvl=0;
		dfs(i, 0, 1);
		maxlvl=0;
		dfs(farthest, 0, 1);
		diam[rt(farthest)]=maxlvl-1;
	}
	for(int i=1;i<=q;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int x;
			cin>>x;
			cout<<diam[rt(x)]<<endl;
		}
		else
		{
			int x, y;
			cin>>x>>y;
			union1(x, y);
		}
	}
	return 0;
}