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

const ll N=2e5+5;

int n;
vector<int> g[N];
int a[N], parent[N];
ll dp[N][2];

void dfs(int k, int par)
{
	parent[k]=par;
	int ct=0;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		ct++;
	}
	dp[k][0]=a[k];
	dp[k][1]=LLONG_MIN;
	if(ct==0)
	{
		dp[k][1]=LLONG_MIN;
	}
	else
	{
		for(auto it:g[k])
		{
			if(it==par)
				continue;
			dp[k][0]+=dp[it][0];
		}
		for(auto it:g[k])
		{
			if(it==par)
				continue;
			dp[k][1]=Max(dp[k][1],dp[it][0],dp[it][1]);
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
	dfs(1,1);
	ll ans=LLONG_MIN;
	for(int i=1;i<=n;i++)
	{
		vector<ll> cur;
		for(auto it:g[i])
		{
			if(it==parent[i])
				continue;
			cur.pb(max(dp[it][0],dp[it][1]));
		}
		if(cur.size()<=1)
			continue;
		sort(cur.rbegin(),cur.rend());
		ans=max(ans,cur[0]+cur[1]);
	}
	if(ans!=LLONG_MIN)
		cout<<ans;
	else
		cout<<"Impossible";
	return 0;
}