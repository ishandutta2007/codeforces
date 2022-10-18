#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    int a[n];
    for(int i = 0; i < n; i++)
		cin >> a[i];
	int pr[n + 2], sf[n + 2];
	memset(pr, 0, sizeof(pr));
	memset(sf, 0, sizeof(sf));
	for(int i = 1; i <= n; i++)
		pr[i] = pr[i - 1] | a[i - 1];
	for(int i = n; i >= 1; i--)
		sf[i] = sf[i + 1] | a[i - 1];
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int t = a[i];
		for(int j = 0; j < k; j++)
			t *= x;
		ans = max(ans, pr[i] | t | sf[i + 2]);
	}
	cout << ans << "\n";
    return 0;
}