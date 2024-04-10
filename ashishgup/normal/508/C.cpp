#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int m, t, r;
int a[N];

int32_t main()
{
	IOS;
	cin>>m>>t>>r;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	set<int> s;
	priority_queue<int, vector<int>, greater<int> > pq;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		while(pq.size() && abs(a[i]-pq.top())>t)
			pq.pop();
		int cur=a[i]-1;
		while(pq.size()<r)
		{
			while(s.find(cur)!=s.end())
			{
				cur--;
			}
			ans++;
			pq.push(cur);
			s.insert(cur);
		}
		if(abs(a[i]-pq.top())>t)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<ans;
}