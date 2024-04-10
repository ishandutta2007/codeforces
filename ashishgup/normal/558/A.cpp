#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n;
int a[N], x[N];
vector<pair<int, int> > pos, neg;
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> a[i];
		if(x[i] > 0)
			pos.push_back({x[i], a[i]});
		else
			neg.push_back({x[i], a[i]});
	}
	int ans = 0;
	int mn = min(neg.size(), pos.size());
	sort(pos.begin(), pos.end());
	sort(neg.rbegin(), neg.rend());
	for(int i = 0; i < mn; i++)
		ans += pos[i].second + neg[i].second;
	if(pos.size() > mn)
		ans += pos[mn].second;
	if(neg.size() > mn)
		ans += neg[mn].second;
	cout << ans;
	return 0;
}