#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

typedef long long ll;

const int N=5e3+5;

int n,m,T;
vector<pair<int, int> > g[N];
int cache[N][N];
int path[N][N];

int dfs(int k, int count)
{
	if(k==1)
	{
		if(count==0)
			return 0;
		else
			return 1e9+1;
	}
	if(count<0)
	{
		return 1e9+1;
	}
	if(cache[k][count]!=-1)
	{
		return cache[k][count];
	}
	int ans=1e9+1;
	for(auto it:g[k])
	{
		int cur=it.ss + dfs(it.ff, count-1);
		if(cur<ans)
		{
			ans=cur;
			path[k][count]=it.ff;
		}
	}
	cache[k][count]=ans;
	return ans;
}


int main()
{
    IOS;
	cin>>n>>m>>T;
	for(int i=1;i<=m;i++)
	{
		int u,v,tim;
		cin>>u>>v>>tim;
		g[v].pb(mp(u,tim));
	}	
	memset(cache, -1, sizeof(cache));
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(dfs(n, i)<=T)
		{
			ans=i;
		}
	}
	cout<<ans+1<<endl;
	vector<int> ans2;
	int curi=n;
	int curj=ans;
	while(curi!=0)
	{
		ans2.pb(curi);
		curi=path[curi][curj];
		curj--;
	}
	reverse(ans2.begin(),ans2.end());
	for(auto it:ans2)
	{
		cout<<it<<" ";
	}
	return 0;
}