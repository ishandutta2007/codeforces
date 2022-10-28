#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=1e6+5;
const int MOD=1e9+9;

int n;
int d[N], f[N], f2[N], vis[N];
set<int> g[N];
vector<int> ans;

void dfs2(int k, int par)
{
	if(k==0)
		return;
	if(vis[k])
		return;
	vis[k]=1;
	ans.push_back(k);
	for(auto it:g[k])
	{
		if(it==par)
			continue;		
		dfs2(it, k);
	}
}

void dfs(int k, int par)
{	
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
	}
	if(d[k]%2==0)
	{
		d[par]--;
		dfs2(k, par);
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int cur;
		cin>>cur;
		if(cur)
		{
			g[i].insert(cur);
			g[cur].insert(i);
			d[cur]++;
			d[i]++;
		}
	}
	dfs(1, 0);
	if(ans.size()!=n)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	for(auto it:ans)
		cout<<it<<endl;
	return 0;
}