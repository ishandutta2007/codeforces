#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2e5 + 5;

int n;
int a[N];
int pref[N][201];
vector<int> st[201];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= 200; i++)
			st[i].clear();
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			st[a[i]].push_back(i);
			for(int j = 1; j <= 200; j++)
				pref[i][j] = pref[i - 1][j];
			pref[i][a[i]]++;
		}
		int ans = 0;
		for(int i = 1; i <= 200; i++)
		{
			int sz = st[i].size();
			ans = max(ans, sz);
			for(int j = 0; j < sz / 2; j++)
			{
				int idx1 = st[i][j];
				int idx2 = st[i][sz - 1 - j];
				int mid = 0;
				for(int k = 1; k <= 200; k++)
				{
					if(i == k)
						continue;
					mid = max(mid, pref[idx2][k] - pref[idx1][k]);
				}
				ans = max(ans, 2 * (j + 1) + mid);
			}
		}
		cout << ans << endl;
	}
	return 0;
}