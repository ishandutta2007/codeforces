#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 35;

int n, m;
int a[N][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		map<int, int> c0, c1;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
				c0[i + j] += (a[i][j] == 0);
				c1[i + j] += (a[i][j] == 1);
			}
		}
		vector<pair<int, int> > v;
		for(int diag = 2; diag <= n + m; diag++)
			v.push_back({c0[diag], c1[diag]});
		int i = 0, j = v.size() - 1, ans = 0;
		while(i < j)
		{
			int t0 = v[i].first + v[j].first;
			int t1 = v[i].second + v[j].second;
			ans += min(t0, t1);
			i++, j--;
		}
		cout << ans << endl;
	}
	return 0;
}