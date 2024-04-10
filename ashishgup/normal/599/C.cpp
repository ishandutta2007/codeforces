#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n;
int a[N];
priority_queue<int, vector<int>, greater<int> > pq, pq1;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pq.push(a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		pq1.push(a[i]);
		while(pq1.size() && pq1.top()==pq.top())
		{
			pq.pop();
			pq1.pop();
		}
		ans+=(pq1.empty());
	}
	cout<<ans;
}