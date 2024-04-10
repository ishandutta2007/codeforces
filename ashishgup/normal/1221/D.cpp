#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n;
int a[N], b[N];
int cache[N][5];

int dp(int idx, int prv)
{
	if(prv > 4)
		return 2e18;
	if(idx > n)
		return 0;
	int &ans = cache[idx][prv];
	if(ans != -1)
		return ans;
	ans = 2e18;
	for(int i = 0; i <= 4; i++)
	{
		if(a[idx] + i == a[idx - 1] + prv)
			continue;
		ans = min(ans, b[idx] * i +  dp(idx + 1, i));
	}
	return ans;

}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i];
			for(int j = 0; j <= 4; j++)
				cache[i][j] = -1;
		}
		int ans = dp(1, 0);
		cout << ans << endl;
	}
	return 0;
}