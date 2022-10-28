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
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5 + 5;

ll n;
int parent[N];
vector<int> g[N];
long double ans[N];
long double subtree[N];

void dfs1(ll k, ll parent)
{
	subtree[k]=1;
	for(auto it:g[k])
	{
		if(it==parent)
			continue;
		dfs1(it,k);
		subtree[k]+=subtree[it];
	}
}

void dfs2(ll k, ll parent)
{
	ans[k]=ans[parent]+1;
	ans[k]+=0.5*((subtree[parent]-1)-subtree[k]);
	for(auto it:g[k])
	{
		if(it==parent)
			continue;
		dfs2(it,k);
	}
}
int main()
{
	IOS;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>parent[i];
		g[i].pb(parent[i]);
		g[parent[i]].pb(i);
	}
	subtree[0]=n+1;
	dfs1(1,0);
	dfs2(1,0);
	cout<<fixed<<setprecision(9);
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}