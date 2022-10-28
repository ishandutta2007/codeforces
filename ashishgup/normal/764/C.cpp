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
vvll g;
vll vis;
vll col;
vll sz(1e5+1,0);
ll count1=0;
vvll countcol;
void dfs(ll k)
{
	if(vis[k])
	{
		return;
	}
	count1++;
	vis[k]=1;
	for(auto i:g[k])
	{
		if(col[i]==col[k])
			dfs(i);
		else
		{
			countcol[k].pb(col[i]);
		}
	}
}
int main()
{
	cin>>n;
	g.resize(n+1);
	vis.resize(n+1,0);
	col.resize(n+1,0);
	countcol.resize(n+1);
	for(ll i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(ll i=0;i<n;i++)
	{
		cin>>col[i+1];
	}
	if(n==2)
	{
		cout<<"YES"<<endl<<"1";
		return 0;
	}
	ll connected=0;
	vpll szcon;
	for(ll i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		connected++;
		count1=0;
		dfs(i);
		sz[col[i]]=count1;
		szcon.pb(mp(count1,i));
	}
	if(connected==1)
	{
		cout<<"YES"<<endl<<"1";
		return 0;
	}
	sort(sz.rbegin(),sz.rend());
	sort(szcon.rbegin(),szcon.rend());
	bool check=false;
	/*for(ll i=0;i<=n;i++)
	{
		cout<<countcol[i].size()<<" ";
	}*/
	for(ll i=1;i<=n;i++)
	{
		ll st=countcol[i].size();
		if(st==connected-1)
		{
			cout<<"YES"<<endl<<i;
			check=true;
			return 0;
		}
	}
	if(!check)
	{
		cout<<"NO";
	}
	/*for(ll i=1;i<=n;i++)
	{
		ll st=countcol[i].size();
		if(st==1)
		{
			cout<<"YES"<<endl<<i;
			return 0;
		}
	}*/
	

	return 0;
}