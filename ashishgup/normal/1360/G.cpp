#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 55;

int n, m, a, b;
int ans[N][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(ans, 0, sizeof(ans));
		cin >> n >> m >> a >> b;
		int cur = 0;
		for(int i = 0; i < n; i++)
		{
			int cnt = a;
			while(cnt > 0)
			{
				ans[i][cur] = 1;
				cur++;
				cur %= m;
				cnt--;
			}
		}
		int flag = 1;
		for(int j = 0; j < m; j++)
		{
			int cnt = 0;
			for(int i = 0; i < n; i++)
				cnt += ans[i][j];
			if(cnt != b)
				flag = 0;
		}
		if(!flag)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
					cout << ans[i][j];
				cout << endl;
			}
		}
	}
	return 0;
}