#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, x;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=-1000;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int curans=0;
			priority_queue<int, vector<int> > pq;
			priority_queue<int, vector<int>, greater<int> > pq2;
			for(int k=1;k<=n;k++)
			{
				if(k>=i && k<=j)
				{
					curans+=a[k];
					pq2.push(a[k]);
				}
				else
					pq.push(a[k]);
			}
			ans=max(ans, curans);
			for(int k=1;k<=x;k++)
			{
				if(pq.empty() || pq2.empty())
					break;
				curans-=pq2.top();
				pq2.pop();
				curans+=pq.top();
				pq.pop();
				ans=max(ans, curans);
			}
		}
	}
	cout<<ans;
}