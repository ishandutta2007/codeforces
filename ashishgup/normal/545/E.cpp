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

int main()
{
	IOS;
	ll n,m;
	cin>>n>>m;
	vector< vector<pair<pair<ll,ll>,ll> > > g(n+1);
	for(ll i=0;i<m;i++)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		g[a].pb(mp(mp(w,b),i+1));
		g[b].pb(mp(mp(w,a),i+1));
	}
	ll source;
	cin>>source;
	set<pair <pair<ll,ll>,pair<ll,ll> > > s2;
	vll dist(n+1,LLONG_MAX);
	dist[source]=0;
	s2.insert(mp(mp(0,source),mp(0,0)));
		
	
	
	ll ans=0;
	vll ans2;
	vll vis(n+1,0);
	ll count=0;

		for(auto it:s2)
		{
			ll w=it.ss.ff;
			ll node=it.ff.ss;
			if(vis[node])
				continue;
			vis[node]=1;
			count++;
			ans+=w;
			ll edge=it.ss.ss;
			if(edge!=0)
				ans2.pb(edge);
				if(count==n)
					break;
			for(auto i:g[node])
			{
				ll v=i.ff.ss;
				ll u=node;
				w=i.ff.ff;
				
				if(dist[v]>=dist[u]+w)
				{
					s2.erase(mp(mp(dist[v],v),mp(w,i.ss)));
					dist[v]=dist[u]+w;
					s2.insert(mp(mp(dist[v],v),mp(w,i.ss)));
				}
			}
		}
	
	
	cout<<ans<<endl;
	for(auto it:ans2)
	{
		cout<<it<<" ";
	}
	return 0;
	
}