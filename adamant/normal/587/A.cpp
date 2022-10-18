#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6;
	int w[maxn], c[maxn];
	
signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> w[i];
		c[w[i]]++;
	}
	int ans = 0;
	for(int i = 0; i < maxn; i++)
	{
		if(c[i])
			c[i + 1] += c[i] / 2;
		c[i] %= 2;
		ans += c[i];
	}
	cout << ans << "\n";
	return 0;
}