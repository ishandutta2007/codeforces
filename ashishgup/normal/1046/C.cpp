#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, d;
int s[N], p[N];

int work()
{
	priority_queue<int> pq;
	for(int i=1;i<=n;i++)
		pq.push(p[i]);
	s[d]+=pq.top();
	int ans=d;
	pq.pop();
	for(int i=d-1;i>=1;i--)
	{
		while(!pq.empty() && pq.top() + s[i] > s[d])
			pq.pop();
		if(!pq.empty())
		{
			ans--;
			pq.pop();
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>s[i];	
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int ans=work();
	cout<<ans;
	return 0;
}