#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int a[N];
stack<pair<int, int> > s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	reverse(a+1, a+n+1);
	for(int i=1;i<=n;i++)
	{
		int cur=0, store=0;
		while(s.size() && s.top().first<a[i])
		{
			cur++;
			cur=max(cur, s.top().second);
			s.pop();
		}
		ans=max(ans, cur);
		s.push({a[i], cur});
	}
	cout<<ans;
	return 0;
}