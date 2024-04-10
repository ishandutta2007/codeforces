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

struct store
{
	ll u,v,wt;

	void init(ll a, ll b, ll c)
	{
		u=a;
		v=b;
		wt=c;
	}
};

long double ans;
store edge[N];
ll n;
vector<ll> g[N];
int par[N];
long double subtree[N];

void dfs1(ll k, ll parent)
{
	subtree[k]=1;
	par[k]=parent;
	for(auto it:g[k])
	{
		if(it==parent)
			continue;
		dfs1(it,k);
		subtree[k]+=subtree[it];
	}
}

void calc()
{
	for(ll i=1;i<=n-1;i++)
	{
		ll u=edge[i].u;
		ll v=edge[i].v;
		ll w=edge[i].wt;
		if(par[u]==v)
		{
			ll a=subtree[u];
			ll b=n-a;
			long double current=a*(a-1)*b + b*(b-1)*a;
			long double denominator=n*(n-1)*(n-2)/6.0;
			current/=denominator;
			current*=w;
			ans+=current;
		}
		else
		{
			ll a=subtree[v];
			ll b=n-a;
			long double current=a*(a-1)*b + b*(b-1)*a;
			long double denominator=n*(n-1)*(n-2)/6.0;
			current/=denominator;
			current*=w;
			ans+=current;
		}
	}
}

long double calc2(ll i)
{
	ll u=edge[i].u;
	ll v=edge[i].v;
	ll w=edge[i].wt;
	if(par[u]==v)
	{
		ll a=subtree[u];
		ll b=n-a;
		long double current=a*(a-1)*b + b*(b-1)*a;
		long double denominator=n*(n-1)*(n-2)/6;
		current/=denominator;
		current*=w;
		return current;
	}
	else
	{
		ll a=subtree[v];
		ll b=n-a;
		long double current=a*(a-1)*b + b*(b-1)*a;
		long double denominator=n*(n-1)*(n-2)/6;
		current/=denominator;
		current*=w;
		return current;
	}
}
int main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		g[a].push_back(b);
		g[b].push_back(a);
		edge[i].init(a,b,w);
	}
	dfs1(1,0);
	calc();
	ll m;
	cin>>m;
	cout<<fixed<<setprecision(12);
	for(ll i=1;i<=m;i++)
	{
		ll ind, newwt;
		cin>>ind>>newwt;
		ans-=calc2(ind);
		edge[ind].wt=newwt;
		ans+=calc2(ind);
		cout<<ans<<endl;
	}
	return 0;
}