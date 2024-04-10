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

ll n,m;
vll rt,sz;

void initialise()
{
	for(ll i=0;i<m;i++)
	{
		rt[i]=i;
		sz[i]=1;
	}
}

ll root(ll i)
{
	while(i!=rt[i])
	{
		rt[i]=rt[rt[i]];
		i=rt[i];
	}
	return i;
}

void union1(ll a,ll b)
{
	if(root(a)==root(b))
		return;
	ll rta=root(a);
	ll rtb=root(b);
	ll sza=sz[rta];
	ll szb=sz[rtb];
	if(sza>=szb)
	{
		rt[rtb]=rt[rta];
		sz[rta]+=sz[rtb];
		sz[rtb]=0;
	}
	else
	{
		rt[rta]=rt[rtb];
		sz[rtb]+=sz[rta];
		sz[rta]=0;
	}
}
int main()
{
	IOS;
	cin>>n>>m;
	ll ans=0;
	vll vis(m,0);
	rt=vll(m,0);
	sz=vll(m,0);
	initialise();
	for(ll i=0;i<n;i++)
	{
		ll lang;
		cin>>lang;
		if(lang==0)
		{
			ans++;
			continue;
		}
		ll st;
		cin>>st;
		st--;
		lang--;
		vis[st]=1;
		while(lang--)
		{
			ll cur;
			cin>>cur;
			cur--;
			vis[cur]=1;
			union1(st,cur);
			st=cur;
		}
	}
	bool check=false;
	for(ll i=0;i<m;i++)
	{
		if(rt[i]==i&&vis[i]==1)
		{
			ans++;
			check=true;
		}
	}
	if(check)
		ans--;
	cout<<ans;
	return 0;
}