#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 55;

int n, m;
int a[N][N], b[N][N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	vector<pair<int, int> > ans;
	for(int i = 1; i <= n - 1; i++)
	{
		for(int j = 1; j <= m - 1; j++)
		{
			if(a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1])
			{
				ans.push_back({i, j});
				b[i][j] = 1;
				b[i + 1][j] = 1;
				b[i][j + 1] = 1;
				b[i + 1][j + 1] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] != b[i][j])
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	for(auto &it:ans)
		cout << it.first << " " << it.second << endl;
	return 0;
}