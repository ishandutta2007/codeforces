#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const long long N=123456+5;

ll n,m, start, end1, ans2;;
vector<int> g[N];
int a[N], check[N], path[N], vis[N], dist[N];

void dfs(int k, int par, int distance)
{
	dist[k]=distance;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, distance+1);
	}
}

int dfs2(int k, int par)
{
	if(k==end1)
	{
		path[k]=1;
		return 1;
	}
	int check1=0;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		check1|=dfs2(it, k);
	}
	if(check1)
	{
		path[k]=1;
	}
	return check1;
}

ll dfs3(int k, int par)
{
	if(vis[k])
		return 0;
	vis[k]=1;
	ll store=0;
	for(auto it:g[k])
	{
		if(it==par)
		{
			continue;
		}
		store+=dfs3(it, k);
	}
	if(store)
	{
		return store+1;
	}
	else
	{
		if(check[k]&&!path[k])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int main()
{ 
	IOS;
	cin>>n>>m;
	if(n==1)
	{
		cout<<"1"<<endl<<"0";
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		check[a[i]]=1;
	}
	dfs(a[1], a[1], 0);
	int max1=0;
	int ind=0;
	for(int i=1;i<=n;i++)
	{
		if(dist[i]>max1 && check[i])
		{
			max1=dist[i];
			ind=i;
		}
	}
	start=ind;
	dfs(ind, ind, 0);
	max1=0;
	ind=0;
	for(int i=1;i<=n;i++)
	{
		if(dist[i]>max1 && check[i])
		{
			max1=dist[i];
			ind=i;
		}
	}
	end1=ind;
	dfs2(start, start);
	ans2=max1;
	for(int i=1;i<=n;i++)
	{
		if(path[i])
		{
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(path[i])
		{
			vis[i]=0;
			ans2+=2*(max(dfs3(i, i)-1,0LL));
		}
	}
	ll ans1=min(start,end1);
	if(m==1)
	{
		ans1=a[1];
	}
	cout<<ans1<<endl;
	cout<<ans2;
	return 0;
}