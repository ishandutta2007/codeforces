#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
string a, b;
int reqd[20][20];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(reqd, 0, sizeof(reqd));
		cin >> n >> a >> b;
		int flag = 1;
		for(int i = 0; i < n; i++)
		{
			if(a[i] > b[i])
			{
				flag = 0;
				break;
			}
		}
		if(!flag)
		{
			cout << -1 << endl;
			continue;
		}
		for(int i = 0; i < n; i++)
		{
			if(a[i] == b[i])
				continue;
			reqd[a[i] - 'a'][b[i] - 'a']++;
		}
		int ans = 0;
		for(int i = 0; i < 20; i++)
		{
			int flag = 0;
			for(int j = i + 1; j < 20; j++)
				flag |= (reqd[i][j] > 0);
			ans += flag;
			if(flag)
			{
				int idx = 0;
				for(int j = i + 1; j < 20; j++)
				{
					if(reqd[i][j])
					{
						idx = j;
						break;
					}
				}
				for(int j = i + 1; j < 20; j++)
					reqd[idx][j] += reqd[i][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}