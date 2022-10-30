#include <bits/stdc++.h>
typedef long long ll;
#define int ll
using namespace std;
int ans[500005], sum[500005];
signed main()
{
	int n, k;
	scanf("%lld %lld", &n, &k);
	for(int i = 2; i <= n; i++)
	{
		int x, y;
		cout << "or " << 1 << ' ' << i << endl;
		// fflush(stdout);
		cin >> x;
		cout << "and " << 1 << ' ' << i << endl;
		// fflush(stdout);
		cin >> y;
		sum[i] = x + y;
	}
	int x, y;
	cout << "or 2 3" << endl;
	// fflush(stdout);
	cin >> x;
	cout << "and 2 3" << endl;
	// fflush(stdout);
	cin >> y;
	int ssum = x + y;
	ans[2] = (ssum - sum[3] + sum[2]) >> 1;
	ans[1] = sum[2] - ans[2];
	ans[3] = (ssum + sum[3] - sum[2]) >> 1;
	for(int i = 4; i <= n; i++)
		ans[i] = sum[i] - ans[1];
	sort(ans + 1, ans + n + 1);
	cout << "finish " << ans[k] << endl;
	// fflush(stdout);
	return 0;
}