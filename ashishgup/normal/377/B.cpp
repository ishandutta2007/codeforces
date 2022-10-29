#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, s;
pair<int, int> a[N], b[N];
int c[N], ans[N];

int check(int days)
{
	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;
	int left=1;
	queue<int> q;
	for(int i=1;i<=m;i++)
	{
		q.push(i);
	}
	int passes=0;
	while(q.size())
	{
		while(left<=n && b[left].first>=a[q.front()].first)
		{
			pq.push({c[b[left].second], left});
			left++;
		}
		if(!pq.size())
		{
			return 0;
		}
		int bindex=pq.top().second;
		pq.pop();
		passes+=c[b[bindex].second];
		if(passes>s)
			return 0;
		int cntr=1;
		while(q.size() && cntr<=days)
		{
			int index=q.front();
			q.pop();
			ans[a[index].second]=b[bindex].second;
			cntr++;
		}
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
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].first;
		b[i].second=i;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(a+1, a+m+1);
	reverse(a+1, a+m+1);
	sort(b+1, b+n+1);
	reverse(b+1, b+n+1);
	int days=binsearch(1, 1e5+1);
	if(days==1e5+1)
	{
		cout<<"NO";
		return 0;
	}
	check(days);
	cout<<"YES"<<endl;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}