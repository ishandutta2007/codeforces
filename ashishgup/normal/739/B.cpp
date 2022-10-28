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

const int N=2e5+5;
const int LG=19;

int n;
long long a[N], par[LG][N], cost[LG][N], answer[N], degree[N], temp[N];
vector<int> g[N];

void precompute()
{
	for(int i=1;i<LG;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(par[i-1][j])
			{
				par[i][j]=par[i-1][par[i-1][j]];
				cost[i][j]=cost[i-1][j] + cost[i-1][par[i-1][j]]; 
			}
		}
	}
}

bool check(ll k, ll ind)
{
	ll cur=ind;
	ll curcost=0;
	for(int i=0;i<LG;i++)
	{
		if(k & (1<<i))
		{
			curcost+=cost[i][cur];
			cur=par[i][cur];
		}
	}
	if(!cur)
	{
		return 0;
	}
	if(curcost<=a[ind])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

ll walk(ll k, ll ind)
{
	ll cur=ind;
	for(int i=0;i<LG;i++)
	{
		if(k & (1<<i))
		{
			cur=par[i][cur];
		}
	}
	return cur;
}

ll binarysearch(ll lo, ll hi, ll ind)
{
	while(lo<hi)
	{
		ll mid=(lo+hi+1)>>1;
		if(check(mid, ind))
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	ll store=walk(lo, ind);
	answer[par[0][store]]-=1;
	answer[par[0][ind]]+=1;
	return lo;
}

int dfs(int k, int par)
{
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		answer[k]+=answer[it];
	}
	return answer[k];
}

int main()
{ 
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		cin>>par[0][i]>>cost[0][i];
		g[i].pb(par[0][i]);
		g[par[0][i]].pb(i);
	}
	precompute();
	for(int i=1;i<=n;i++)
	{
		binarysearch(0, n, i);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
	{
		cout<<answer[i]<<" ";
	}
	return 0;
}