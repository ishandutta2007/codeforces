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

typedef long long ll;
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

ll n;
vvll f;
vvll e;
vll vis;
vll vis2;
vll vise;
bool check;
ll counts=0;

void dfs(ll k)
{
	if(vis[k])
	{
		return;
	}
	counts++;
	vis[k]=1;
	vis2[k]=1;
	for(auto i:f[k])
	{
		dfs(i);
	}
}

void dfs2(ll parent, ll k)
{
	if(vise[k])
	{
		return;
	}
	vise[k]=1;
	if(vis2[k]&&vis2[parent]&&parent!=k)
	{
		check=false;
	}
	for(auto i:e[k])
	{
		dfs2(k,i);
	}
}
int main()
{
	cin>>n;
	ll k;
	cin>>k;
	f=vvll(n+1);
	e=vvll(n+1);
	for(ll i=0;i<k;i++)
	{
		ll a,b;
		cin>>a>>b;
		f[a].pb(b);
		f[b].pb(a);
	}
	ll m;
	cin>>m;
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		e[a].pb(b);
		e[b].pb(a);
	}
	vis=vll (n+1,0);
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		if(vis[i])
		{
			continue;
		}
		counts=0;
		vis2=vll (n+1,0);
		vise=vll (n+1,0);
		check=true;
		dfs(i);
		for(ll j=1;j<=n;j++)
		{
			if(vis2[j])
			{
				dfs2(j,j);
			}
		}
		//cout<<counts<<endl;
		if(check)
		{
			ans=max(ans,counts);
		}
	}
	cout<<ans;
}