#include <bits/stdc++.h>

using namespace std;

signed main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++)
		cin >> s[i];
	int d[n][m];
	memset(d, 0x0F, sizeof(d));
	int mex, mey;
	pair<int, int> q[n * m];
	int st = 0, fi = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == 'E')
				d[i][j] = 0, q[0] = {i, j};
			else if(s[i][j] == 'S')
				mex = i, mey = j;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	while(st < fi)
	{
		int cx = q[st].first;
		int cy = q[st].second;
		st++;
		for(int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m)
				continue;
			if(s[tx][ty] == 'T')
				continue;
			if(d[tx][ty] > d[cx][cy] + 1)
			{
				d[tx][ty] = d[cx][cy] + 1;
				q[fi++] = {tx, ty};
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(isdigit(s[i][j]) && d[i][j] <= d[mex][mey])
				ans += s[i][j] - '0';
	cout << ans << "\n";
    return 0;
}