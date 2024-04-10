#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, ans=1e9, curidx;
int a[N], cnt[N], reqd[N];
int vis[N];

void dfs(int x, int lvl)
{
	if(x<1)
		return;
	if(x>1e5)
		return;
	if(vis[x]==curidx)
		return;
	vis[x]=curidx;
	cnt[x]+=1;
	reqd[x]+=lvl;
	dfs(x*2, lvl+1);
	dfs(x/2, lvl+1);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		curidx=i;
		cin>>a[i];
		dfs(a[i], 0);
	}
	for(int i=1;i<=1e5;i++)
	{
		if(cnt[i]==n)
			ans=min(ans, reqd[i]);
	}
	cout<<ans;
	return 0;
}