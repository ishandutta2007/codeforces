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

const int N = 3e5 + 5;

struct data
{
	int u,v,w;
};

int n,m;
data edges[N];
int dp[N], max1[N], temp[N];

bool comp(data d1, data d2)
{
	return d1.w<d2.w;
}

int main()
{
	IOS;
	cin>>n>>m;
	for(int i=0;i<=m;i++)
	{
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
	}
	sort(edges,edges+m,comp);
	int ans=0;
	set<int> store;
	for(int i=0;i<m;i++)
	{
		if((i<m-1 && edges[i].w != edges[i+1].w) || i==m-1)
		{
			int u=edges[i].u;
			int v=edges[i].v;
			if(store.find(v)==store.end())
				temp[v]=dp[u]+1;
			else
				temp[v]=max(temp[v],dp[u]+1);
			store.insert(v);
			for(auto it:store)
			{
				dp[it]=max(dp[it],temp[it]);
			}
			store.clear();
		}
		else
		{
			int u=edges[i].u;
			int v=edges[i].v;
			if(store.find(v)==store.end())
				temp[v]=dp[u]+1;
			else
				temp[v]=max(temp[v],dp[u]+1);
			store.insert(v);
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}