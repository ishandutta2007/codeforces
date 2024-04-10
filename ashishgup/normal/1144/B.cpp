#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N];
vector<int> g[2];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		g[a[i] % 2].push_back(a[i]);
	}
	sort(g[0].begin(), g[0].end());
	sort(g[1].begin(), g[1].end());
	while(g[0].size() && g[1].size())
	{
		g[0].pop_back();
		g[1].pop_back();
	}
	if(g[0].size())
		g[0].pop_back();
	if(g[1].size())
		g[1].pop_back();
	int ans = 0;
	for(auto &it:g[0])
		ans += it;
	for(auto &it:g[1])
		ans += it;
	cout << ans;
	return 0;
}