#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back


#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;

const long long N=1e3+5;

int vis[N], visited[N][N];
vector<int> g[N];
long long n, m, maxw, ct=0, totw, totb;
long long w[N], b[N], wcomp[N], bcomp[N], cache[N][N];
vector<int> comp[N];

void dfs(int k)
{
	if(vis[k])
		return;
	totw+=w[k];
	totb+=b[k];
	comp[ct].pb(k);
	vis[k]=1;
	for(auto it:g[k])
	{
		dfs(it);
	}
}

long long dp(int i, int w1)
{
	if(w1>maxw)
		return INT_MIN;
	if(i==ct+1)
		return 0;
	if(visited[i][w1])
	{
		return cache[i][w1];
	}
	visited[i][w1]=1;
	cache[i][w1]=dp(i+1, w1);
	cache[i][w1]=max(cache[i][w1], bcomp[i] + dp(i+1, w1+wcomp[i]));
	for(auto it:comp[i])
	{
		cache[i][w1]=max(cache[i][w1], b[it] + dp(i+1, w1+w[it]));
	}
	return cache[i][w1];
}

int main()
{
    IOS;
	cin>>n>>m>>maxw;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		ct++;
		totw=0;
		totb=0;
		dfs(i);
		wcomp[ct]=totw;
		bcomp[ct]=totb;
	}
	ll ans=dp(1,0);
	cout<<ans;
	return 0;
}