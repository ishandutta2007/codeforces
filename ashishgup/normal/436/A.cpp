#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, x, p=0, q=0;
pair<int, int> a[N], b[N];

int solve()
{
	int cur=x;
	int i=1, j=1, ans=0;
	priority_queue<int, vector<int> > pq, pq2;
	while(true)
	{
		while(i<=p && a[i].first<=cur)
		{
			pq.push(a[i].second);
			i++;
		}
		if(pq.empty())
			return ans;
		ans++;
		cur+=pq.top();
		pq.pop();
		while(j<=q && b[j].first<=cur)
		{
			pq2.push(b[j].second);
			j++;
		}
		if(pq2.empty())
			return ans;
		ans++;
		cur+=pq2.top();
		pq2.pop();
	}	
}

int32_t main()
{
	IOS;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		int type;
		cin>>type;
		if(!type)
		{
			++p;
			cin>>a[p].first>>a[p].second;
		}
		else
		{
			++q;
			cin>>b[q].first>>b[q].second;
		}
	}
	sort(a+1, a+p+1);
	sort(b+1, b+q+1);
	int ans=solve();
	swap(a, b);
	swap(p, q);
	int ans2=solve();
	cout<<max(ans, ans2);
}