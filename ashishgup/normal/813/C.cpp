#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long double ld;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<pair<ll,ll> > > vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

ll n,x;
vvll g;
vll vis1;
vll level;
vll levelmax;
vll vis2;
vll vis3;
vll vis4;
vll check;
void dfs1(ll k,ll lvl)
{
	if(vis1[k])
		return;
	vis1[k]=1;
	level[k]=lvl;
	for(auto it:g[k])
	{
		dfs1(it,lvl+1);	
	}	
}

ll dfs2(ll k,int p)
{
	if(vis2[k])
		return levelmax[k];
	vis2[k]=1;
	levelmax[k]=level[k];
	for(auto it:g[k])
	{
		if(it==p) continue;
		levelmax[k]=max(levelmax[k],dfs2(it,k));
	}
	return levelmax[k];
}

bool dfs3(ll i,int p)
{
	if(vis3[i])
		return check[i];
	vis3[i]=1;
	for(auto it:g[i])
	{
		if(it==p) continue;
		check[i]=check[i]||dfs3(it,i);
	}
	if(i==x)
	{
		check[i]=1;
	}
	return check[i];
}

void dfs4(ll k,ll lvl)
{
	if(vis4[k])
		return;
	if(!check[k]&&k!=x)
	{
		return;
	}
	if(lvl>=(level[x]+1)/2)
		return;
	levelmax[x]=max(levelmax[x],levelmax[k]);
	if(check[k])
	{
		levelmax[x]=max(levelmax[x],levelmax[k]);
	}
	vis4[k]=1;
	for(auto it:g[k])
	{
		dfs4(it,lvl+1);
	}
}
int main()
{
	IOS;
	cin>>n>>x;
	g.resize(n+1);
	vis1=vll(n+1,0);
	level=vll(n+1,0);
	levelmax=vll(n+1,0);
	vis2=vll(n+1,0);
	vis3=vll(n+1,0);
	check=vll(n+1,0);
	vis4=vll(n+1,0);
	for(ll i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs1(1,0);
	/*ll ct=0;
	for(auto it:level)
	{
		if(ct>0)
			cout<<it<<" ";
		ct++;
	}
	cout<<endl;*/
	dfs2(1,0);
	/*ct=0;
	for(auto it:levelmax)
	{
		if(ct>0)
		cout<<it<<" ";
		ct++;
	}
	cout<<endl;*/
	dfs3(1,0);
	/*ct=0;
	for(auto it:check)
	{
		if(ct>0)
		cout<<it<<" ";
		ct++;
	}*/
	dfs4(x,0);
	ll ans=levelmax[x];
	cout<<ans*2;
	return 0;
}