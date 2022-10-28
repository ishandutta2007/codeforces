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

const int N=1e2+5;

int n, m, check1=1, vis[N], ans[N];
vector<int> g[N];
pair<int, int> edge[N];

int check(int i, int j)
{
	int a=edge[i].ff;
	int b=edge[i].ss;
	int c=edge[j].ff;
	int d=edge[j].ss;
	if(a>b)
		swap(a,b);
	if(c>d)
		swap(c,d);
	if(a>c&&a<d&&(b<c||b>d))
		return 1;
	else if(b>c&&b<d&&(a<c||a>d))
		return 1;
	return 0;
}

void dfs(int k, int type)
{
	if(vis[k])
	{
		if(ans[k]!=type)
			check1=0;
		return;
	}
	ans[k]=type;
	vis[k]=1;
	for(auto it:g[k])
		dfs(it, type^1);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		edge[i].ff=u;
		edge[i].ss=v;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(check(i,j))
			{
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!vis[i])
		{
			dfs(i, 0);
		}
	}
	if(!check1)
	{
		cout<<"Impossible";
	}
	else
	{
		for(int i=1;i<=m;i++)
			cout<<(ans[i]?'i':'o');
	}
}