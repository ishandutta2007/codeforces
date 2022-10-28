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

ll n;
vvll g;
vll ans;
vll vis;
ll val;
ll st;
void bfs(ll k)
{
	vis[k]=1;
	ans[k]=val;
	val++;
	val=val%st;
	queue<ll> q;
	q.push(k);
	vector<set<ll>> s(n+1);
	while(!q.empty())
	{
		ll temp=q.front();
		s[temp].insert(ans[temp]);
		q.pop();
		ll count=1;
		for(auto i:g[temp])
		{
			if(!vis[i])
			{
				vis[i]=1;
				while(s[temp].find((ans[temp]+count)%st)!=s[temp].end())
				{
					count++;
				}
				ans[i]=ans[temp]+count;
				ans[i]=ans[i]%st;
				s[temp].insert(ans[i]);
				s[i].insert(ans[temp]);
				count++;
				q.push(i);
			}
		}
	}
}
int main()
{
	IOS;
	cin>>n;
	g.resize(n+1);
	vis.resize(n+1,0);
	ans.resize(n+1);
	for(ll i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	ll k=0;
	ll source=1;
	for(ll i=1;i<=n;i++)
	{
		ll sz=g[i].size();
		if(sz>k)
		{
			k=sz;
			source=i;
		}
	}
	st=k+1;
	cout<<k+1<<endl;
	val=0;
	//cout<<source<<endl;
	bfs(source);
	for(ll i=1;i<=n;i++)
	{
		cout<<ans[i]+1<<" ";
	}
	return 0;
}