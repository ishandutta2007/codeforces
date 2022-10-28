#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n, m;
int a[N][N];
set<int> r[N], c[N];
vector<int> row[N], col[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			r[i].insert(a[i][j]);
			c[j].insert(a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(auto &it:r[i])
			row[i].push_back(it);
		sort(row[i].begin(), row[i].end());
	}
	for(int i=1;i<=m;i++)
	{
		for(auto &it:c[i])
			col[i].push_back(it);
		sort(col[i].begin(), col[i].end());
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x1 = lower_bound(row[i].begin(), row[i].end(), a[i][j]) - row[i].begin();
			int y1 = lower_bound(col[j].begin(), col[j].end(), a[i][j]) - col[j].begin();
			int ans = max(x1, y1) + 1;
			int x2 = upper_bound(row[i].begin(), row[i].end(), a[i][j]) - row[i].begin();
			int y2 = upper_bound(col[j].begin(), col[j].end(), a[i][j]) - col[j].begin();
			x2 = row[i].size() - x2;
			y2 = col[j].size() - y2;
			ans += max(x2, y2);
			cout<<ans<<" ";
		}
		cout<<endl;
	}
	return 0;
}