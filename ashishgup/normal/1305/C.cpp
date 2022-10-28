#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
int a[N];
map<int, int> f;

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i] % m]++;
	}
	for(auto &it:f)
	{
		if(it.second > 1)
		{
			cout << 0;
			return 0;
		}
	}
	int ans = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			ans *= abs(a[j] - a[i]);
			ans %= m;
		}	
	}
	cout << ans;
	return 0;
}