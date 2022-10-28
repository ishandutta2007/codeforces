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

int n,m;
int colorset[N];
vector<int> g[N];
set<int> contains[N];
set<int> colors[N];
int ans[N];

void dfs(int k, int par)
{
	for(auto it:contains[k])
	{
		if(ans[it]!=-1)
		{
			colors[k].insert(ans[it]);
		}
	}
	int col=1;
	for(auto it:contains[k])
	{
		if(ans[it]==-1)
		{
			while(colors[k].find(col)!=colors[k].end())
			{
				col++;
			}
			ans[it]=col;
			colors[k].insert(col++);
		}
	}
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it,k);
	}
}
int main()
{
	IOS;
	cin>>n>>m;
	memset(ans,-1,sizeof(ans));
	int answer1=0;
	for(int i=1;i<=n;i++)
	{
		int s;
		cin>>s;
		answer1=max(answer1,s);
		while(s--)
		{
			int ice;
			cin>>ice;
			contains[i].insert(ice);
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	cout<<max(answer1,1)<<endl;
	for(int i=1;i<=m;i++)
	{
		cout<<max(ans[i],1)<<" ";
	}
	return 0;
}