#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		map<int, int> reqd;
		int ans = 0, mx = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(a[i] % k)
				reqd[k - (a[i] % k)]++;
		}
		for(auto &it:reqd)
			mx = max(mx, it.second);
		if(mx > 0)
		{
			ans += (mx - 1) * k;
			int last = 0;
			for(auto &it:reqd)
				if(it.second == mx)
					last = it.first;
			ans += last;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}