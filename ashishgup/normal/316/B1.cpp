
 #include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, x, cnt=0, sz;
int a[N], idx[N], store[N], comp[N], vis[N][N];
vector<int> g[N];
set<int> ans;

void dfs(int i, int level)
{
	sz++;
	idx[i]=level;
	comp[i]=cnt;
	for(auto &it:g[i])
		dfs(it, level+1);
}

void dp(int i, int sz)
{
	if(i==cnt+1)
	{
		ans.insert(sz+idx[x]);
		return;
	}
	if(vis[i][sz])
		return;
	vis[i][sz]=1;
	dp(i+1, sz);
	dp(i+1, sz+store[i]);
}

int32_t main()
{
	IOS;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0)
			g[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			cnt++;
			sz=0;
			dfs(i, 1);
			store[cnt]=sz;
		}
	}
	store[comp[x]]=0;
	dp(1, 0);
	for(auto &it:ans)
		cout<<it<<endl;
	return 0;
}