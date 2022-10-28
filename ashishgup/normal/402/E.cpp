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

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=2005;

int ct=0, ct2=0;
int vis[N], vis2[N];
int a[N][N];
vector<int> g[N], rg[N];

void dfs(int k)
{
	if(vis[k])
		return;
	ct++;
	vis[k]=1;
	for(auto it:g[k])
		dfs(it);
}

void dfs2(int k)
{
	if(vis2[k])
		return;
	ct2++;
	vis2[k]=1;
	for(auto it:rg[k])
		dfs2(it);
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int store;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>0)
			{
				g[i].pb(j);
				rg[j].pb(i);
			}
			if(i==j && a[i][j]>0)
				store=i;
		}
	}
	dfs(store);
	dfs2(store);
	if(ct<n || ct2<n)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	return 0;
}