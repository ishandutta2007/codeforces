#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

int n, m;
vector<int> g[N];
set<int> have[N];
int t[N], store[N];
pair<int, int> a[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n  +1);
	vector<int> ans;
	for(int i = 1; i <= n; i++)
	{
		set<int> s;
		s.insert(0);
		int mx = 0;
		for(auto &it:g[a[i].second])
			s.insert(store[it]);
		while(s.find(mx) != s.end())
			mx++;
		if(mx != a[i].first)
		{
			cout << -1;
			return 0;
		}
		store[a[i].second] = mx;
	}
	for(auto i = 1; i <= n; i++)
		cout << a[i].second << " ";
	cout << endl;
	return 0;
}