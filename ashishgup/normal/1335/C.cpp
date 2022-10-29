#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		map<int, int> m;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		int ans = 0;
		for(auto &it:m)
		{
			for(int i = 1; i <= it.second;i++)
			{
				int cur = min(i, (int)m.size() - (i == it.second));
				ans = max(ans, cur);
			}
		}
		cout << ans << endl;
	}	
	return 0;
}