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

const ll N=305;

int n, dest;
vector< pair<int,int> > g[N];
int path[N], count1[N], a[N];

int dfs(int k, int par)
{
	if(k==dest)
		return 1;
	int check=0;
	for(auto it:g[k])
	{
		if(it.ff==par)
			continue;
		int cur=dfs(it.ff, k);
		if(cur==1)
		{
			check=1;
			path[k]=it.ff;
			count1[it.ss]++;
		}
	}
	return check;
}

int main()
{ 
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(mp(v,i));
		g[v].pb(mp(u,i));
	}
	int ind=1;
	int temp;
	a[0]=1;
	while(cin>>temp)
	{
		a[ind++]=temp;
	}
	a[ind++]=1;
	vector<int> ans;
	ans.pb(1);
	for(int i=1;i<ind;i++)
	{
		memset(path, -1, sizeof(path));
		dest=a[i];
		dfs(a[i-1], a[i-1]);
		int cur=path[a[i-1]];
		while(cur!=-1)
		{
			ans.pb(cur);
			cur=path[cur];
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		if(count1[i]!=2)
		{
			cout<<"-1";
			return 0;
		}
	}
	for(auto it:ans)
	{
		cout<<it<<" ";
	}
	return 0;
}