//Started Late

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N], b[N], c[N];

int check(int x)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	for(int i=1;i<=n;i++)
	{
		c[i] = a[i];
		pq.push({a[i]/b[i], i});
	}
	for(int i=0;i<=k-1;i++)
	{
		if(!pq.size())
			break;
		auto cur = pq.top();
		if(cur.first >= k-1)
			return 1;
		if(cur.first < i)
			return 0;
		pq.pop();
		int idx = cur.second;
		c[idx] += x;
		c[idx] = min(c[idx], (int)1e18);
		if(c[idx] <= (k-1) * b[idx])
			pq.push({c[idx]/b[idx], idx});
	}
	return 1;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid = (lo + hi)/2;
		if(check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	if(!check(lo))
		lo = -1;
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int ans = binsearch(0, 2e12);
	cout<<ans;
	return 0;
}