#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n, m;
int a[N], b[N];

int check(int t)
{
	priority_queue<int> pq;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0)
			pq.push(i);
		b[i]=a[i];

	}
	for(int i=1;i<=m;i++)
	{
		int check=0;
		int curtime=t;
		while(pq.size() && b[pq.top()]>0 && curtime>0)
		{
			if(!check)
			{
				check=1;
				curtime-=(pq.top());
				if(curtime<0)
					return 0;
			}
			int store=min(b[pq.top()], curtime);
			b[pq.top()]-=store;
			curtime-=store;
			if(b[pq.top()]==0)
				pq.pop();
		}
	}
	if(pq.size())
		return 0;
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
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=binsearch(0, 1e18);
	cout<<ans;
	return 0;
}