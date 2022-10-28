#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, m, k;
vector<int> ans;
vector<int> a[N];

inline int check(int x)
{
	ans.clear();
	for(int i=1;i<=k;i++)
		ans.push_back(1);
	for(int i=1;i<=2*(n+m);i++)
		a[i].clear();
	int store=1;
	for(;store<=k;store++)
	{
		for(int i=1;i<=2*(n+m);i+=(n+m))
		{
			for(int j=i;j<=i+n-1;j++)
				a[j].push_back(store);
		}
	}
	int idx=n+1;
	x-=k;
	while(idx<=2*(n+m))
	{
		vector<int> v(a[idx].size());
		int sz=set_intersection(a[idx].begin(), a[idx].end(), a[idx-1].begin(), a[idx-1].end(), v.begin()) - v.begin();
		if(sz==0)
		{
			ans.push_back(idx-1);
			x-=1;
			if(x<0)
				return 0;
			for(int i=idx-1;i<=2*(n+m);i+=(n+m))
			{
				for(int j=i;j<=i+n-1;j++)
					a[j].push_back(store);
			}
		}
		while(a[idx].size()<k)
		{
			ans.push_back(idx);
			x-=1;
			if(x<0)
				return 0;
			for(int i=idx;i<=2*(n+m);i+=(n+m))
			{
				for(int j=i;j<=i+n-1;j++)
					a[j].push_back(store);
			}
			store++;
		}
		idx++;
	}
	return 1;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	check(lo);
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	int reqd=binsearch(k, 4000);
	cout<<reqd<<endl;
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}