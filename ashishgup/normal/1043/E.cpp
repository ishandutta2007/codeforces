#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, m, ctr=0;
int x[N], y[N], diff[N], bit[3][N], cnt[N], ans[N];
vector<int> g[N];
map<int, int> rm;

void update(int i, int idx, int k)
{
	while(idx<=n)
	{
		bit[i][idx]+=k;
		idx+=idx&-idx;
	}
}

int pref(int i, int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[i][idx];
		idx-=idx&-idx;
	}
	return ans;
}

int query(int i, int l, int r)
{
	return pref(i, r) - pref(i, l-1);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		diff[i]=x[i]-y[i];
		rm[diff[i]];
	}
	for(auto &it:rm)
		it.second=++ctr;
	for(int i=1;i<=n;i++)
	{
		update(0, rm[diff[i]], y[i]);
		update(1, rm[diff[i]], 1);
		update(2, rm[diff[i]], x[i]);
		cnt[rm[diff[i]]]++;
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=y[i] * query(1, 1, rm[diff[i]]-1) + query(2, 1, rm[diff[i]] - 1);
		ans[i]+=x[i] * query(1, rm[diff[i]] + 1, n) + query(0, rm[diff[i]] + 1, n);
		ans[i]+=y[i] * (query(1, rm[diff[i]], rm[diff[i]]) - 1) + (query(2, rm[diff[i]], rm[diff[i]]) - x[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		int cur=min(x[u]+y[v], x[v]+y[u]);
		ans[u]-=cur;
		ans[v]-=cur;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}