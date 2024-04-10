#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N], bit[N];

void update(int idx, int val)
{
	while(idx<=n)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int v, x;
			cin>>v>>x;
			a[v]=x;
			int cur=pref(v);
			update(v, -cur);
			update(v+1, cur);
		}
		else if(type==2)
		{
			int y;
			cin>>y;
			update(1, y);
		}
		else
		{
			int x;
			cin>>x;
			int ans=a[x];
			ans+=pref(x);
			cout<<ans<<endl;
		}
	}
	return 0;
}