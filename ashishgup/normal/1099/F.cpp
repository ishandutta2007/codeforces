#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, T;
int x[N], t[N], bit[2][N], f[N], best[N], ans[N];
vector<pair<int, int> > g[N];

void update(int i, int idx, int k)
{
	while(idx<N)
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

int check(int y, int remT)
{
	int timeReqd=pref(0, y);
	return timeReqd<=remT;
}

int binsearch(int lo, int hi, int remT)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(check(mid, remT))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}
int work(int remT)
{
	int lastT=binsearch(0, 1e6, remT);
	int cookies=pref(1, lastT);
	if(lastT<1e6)
	{
		int canHave=min(f[lastT+1], (remT - pref(0, lastT))/(lastT+1));
		cookies+=canHave;
	}
	return cookies;
}

void dfs(int k, int par, int remT)
{
	update(0, t[k], t[k]*x[k]);
	update(1, t[k], x[k]);
	f[t[k]]+=x[k];
	best[k]=work(remT);
	ans[k]=best[k];
	for(auto &it:g[k])
	{
		if(it.first==par)
			continue;
		dfs(it.first, k, remT-it.second*2);
	}
	f[t[k]]-=x[k];
	update(0, t[k], -t[k]*x[k]);
	update(1, t[k], -x[k]);
}

int dfs2(int k, int par)
{
	vector<int> v;
	for(auto &it:g[k])
	{
		if(it.first==par)
			continue;
		v.push_back(dfs2(it.first, k));
	}
	sort(v.rbegin(), v.rend());
	if(k==1)
		ans[k]=max(best[k], v[0]);
	else
	{
		ans[k]=best[k];
		if(v.size()>=2)
			ans[k]=max(ans[k], v[1]);
	}
	return ans[k];
}


int32_t main()
{
	IOS;
	cin>>n>>T;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=2;i<=n;i++)
	{
		int p, l;
		cin>>p>>l;
		g[p].push_back({i, l});
	}
	dfs(1, 1, T);
	dfs2(1, 1);
	cout<<ans[1];
	return 0;
}