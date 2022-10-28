#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=18;

int n;
bool vis[1LL<<N];
double ans[1LL<<N], p[N][N];
queue<int> q;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>p[i][j];
		}
	}	
	int cur=0;
	q.push((1<<n)-1);
	ans[(1<<n)-1]=1;
	while(!q.empty())
	{
		int mask=q.front();
		q.pop();
		int cnt=__builtin_popcount(mask);
		cnt=cnt*(cnt-1)/2;
		for(int i=0;i<n;i++)
		{
			if(!(mask&(1<<i)))
				continue;
			for(int j=0;j<n;j++)
			{
				if(!(mask&(1<<j)))
					continue;
				ans[mask&(~(1<<j))]+=p[i][j]*ans[mask]/cnt;
				if(!vis[mask&(~(1<<j))])
				{
					vis[mask&(~(1<<j))]=1;
					q.push(mask&(~(1<<j)));
				}
			}
		}
	}	
	cout<<fixed<<setprecision(12);
	for(int i=0;i<n;i++)
		cout<<ans[1<<i]<<" ";
	return 0;
}