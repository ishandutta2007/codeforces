#include <bits/stdc++.h>

using namespace std;

signed main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int x[n], y[n];
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	int a[n][n];
	memset(a, 0, sizeof(a));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] |= x[i] == x[j] || y[i] == y[j];
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				a[i][j] |= a[i][k] & a[k][j];
	int ans = 0;
	int used[n];
	memset(used, 0, sizeof(used));
	for(int i = 0; i < n; i++)
		if(!used[i])
		{
			ans++;
			for(int j = 0; j < n; j++)
				used[j] |= a[i][j];
		}
	cout << ans - 1 << "\n";
}