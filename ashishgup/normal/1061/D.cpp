#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n, x, y, ans=0;
int cost[N];
pair<int, int> a[N];
multiset<pair<pair<int, int>, int> > s;

int32_t main()
{
	IOS;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].first>>a[i].second;
		s.insert({{a[i].second, a[i].first}, i});
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
	{
		cost[i] = (x + y * (a[i].second - a[i].first));
		if(!s.size() || s.begin() -> first.first >= a[i].first) 
			continue;
		auto it = s.lower_bound({{a[i].first, 0}, 0});
		int pR = (--it) -> first.first;
		if (y * (a[i].second - pR) >= cost[i]) 
			continue;
		cost[i] = y * (a[i].second - pR);
		s.erase(it);
	}
	for(int i=1;i<=n;i++)
	{
		ans+=cost[i];
		ans%=MOD;
	}
	ans%=MOD;
	cout<<ans;
}