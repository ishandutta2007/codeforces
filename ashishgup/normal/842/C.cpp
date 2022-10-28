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
typedef pair<long long, long long> pll;
typedef vector<long long> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 2000000011
#define MOD2 2000000033

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const long long N=2e5+5;

int n;
int a[N];
vector<int> g[N];
int ans[N];
vector<int> factors;

void dfs1(int k, int par, int val)
{
	ans[k]=val;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs1(it,k,gcd(val,a[it]));
	}
}

void dfs2(int k, int par, int lvl, int fact, int occ)
{
	if(k==1)
	{
		for(auto it:g[k])
		{
			if(it==par)
				continue;
			for(auto fac:factors)
			{
				dfs2(it, k, lvl+1, fac, 1);
			}
		}
		return;
	}
	int check= a[k]%fact == 0;
	if(occ + check>= lvl)
	{
		ans[k]=max(ans[k],fact);
	}
	else
	{
		return;
	}
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		if(a[k]%fact==0)
		{
			dfs2(it, k, lvl+1, fact, occ+1);
		}
		else
		{
			dfs2(it, k, lvl+1, fact, occ);
		}
	}
}
int main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i*i<=a[1];i++)
	{
		if(a[1]%i == 0)
		{
			factors.pb(i);
			if(a[1]/i != i)
			{
				factors.pb(a[1]/i);
			}
		}
	}
	factors.pb(a[1]);
	dfs1(1,1,0);
	dfs2(1,1,0,0,0);
	ans[1]=a[1];
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}