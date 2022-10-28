#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int a[N], bit[N];
set<int> g[N];
priority_queue<int, vector<int>, greater<int> > pq;

void update(int idx, int val)
{
	while(idx<=n)
	{
		bit[idx]+=val;
		idx+=(idx&(-idx));
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}

int rsum(int l, int r)
{
	if(r<l)
		return (pref(n) - pref(l-1) + pref(r));
	return pref(r) - pref(l-1);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pq.push(a[i]);
		update(i, 1);
		g[a[i]].insert(i);
	}
	int cur=1;
	while(!pq.empty())
	{
		int val=pq.top();
		auto it=g[val].lower_bound(cur);
		if(it==g[val].end())
			it=g[val].begin();
		int idx=*it;
		int cards=rsum(cur, idx);
		ans+=cards;
		pq.pop();
		update(idx, -1);
		cur=idx;
		g[val].erase(idx);
	}	
	cout<<ans;
	return 0;
}