#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 5;
const int M = 105;

int n, m, sz, ans = 0;
int a[N][M], b[N][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		memset(b, 0, sizeof(b));
		vector<pair<int, int> > v;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		}
		for(int i = 1; i <= m; i++)
		{
			int mx = 0;
			for(int j = 1; j <= n; j++)
				mx = max(mx, a[j][i]);
			v.push_back({mx, i});
		}
		sort(v.rbegin(), v.rend());
		sz = v.size();
		sz = min(sz, n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < sz; j++)
				b[i][j] = a[i + 1][v[j].second];
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < n; k++)
				{
					for(int l = 0; l < n; l++)
					{
						int cur = 0;
						for(int r = 0; r < n; r++)
						{
							int val = 0;
							for(int c = 0; c < sz; c++)
							{
								if(c == 0)
									val = max(val, b[(r + i) % n][c]);
								if(c == 1)
									val = max(val, b[(r + j) % n][c]);
								if(c == 2)
									val = max(val, b[(r + k) % n][c]);
								if(c == 3)
									val = max(val, b[(r + l) % n][c]);
							}
							cur += val;
						}
						ans = max(ans, cur);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}