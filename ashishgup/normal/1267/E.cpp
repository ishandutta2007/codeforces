#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m;
int a[N][N];
int mark[N];

int32_t main()
{
	IOS;
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] -= a[i][m];
	int ans = 0;
	vector<int> store;
	for(int i = 1; i <= m - 1; i++)
	{
		vector<pair<int, int> > v;
		for(int j = 1; j <= n; j++)
			v.push_back({a[j][i], j});
		sort(v.rbegin(), v.rend());
		int cur = 0;
		vector<int> out;
		for(auto &it:v)
		{
			cur += it.first;
			if(cur < 0)
				break;
			out.push_back(it.second);
		}
		if(out.size() > ans)
		{
			ans = out.size();
			store = out;
		}
	}
	cout << n - ans << endl;
	for(auto &it:store)
		mark[it] = 1;
	for(int i = 1; i <= n; i++)
		if(!mark[i])
			cout << i << " ";
	return 0;
}