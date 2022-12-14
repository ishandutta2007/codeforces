#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<pair<int, int>, int>> g;
	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g.push_back({{a, b}, c});
		g.push_back({{b, a}, c});
	}
	
	vector<bool> u(n + 1);
	for(int i = 0; i < k; ++i)
	{
		int a;
		cin >> a;
		u[a] = true;
	}
	
	const int INF = 1000 * 1000 * 1000 + 228;
	int ans = INF;
	
	for(auto i : g)
	{
		if(u[i.first.first] and not u[i.first.second])
		{
			ans = min(ans, i.second);
		}
	}
	
	if(ans == INF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}
	
	return 0;
}