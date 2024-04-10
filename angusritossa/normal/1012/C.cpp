#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool done[5010][5010][2];
int memo[5010][5010][2];
int h[5010];
int n, k;
int dp(int a, int b, int c)
{
	if (!a || h[a-1] < h[a]) c = 1;
	if (done[a][b][c]) return memo[a][b][c];
	if (!b) return 0;
	if (a == n) return 1e9;
	int ans = 1e9;
	if (!c)
	{
		if (a == n-1) return 1e9;
		ans = dp(a+1, b, 0);
		int diff = max(0, h[a] - h[a+1] + 1);
		ans = min(ans, dp(a+1, b, 1) + diff);
	}
	else
	{
		if (a == n-1) ans = dp(a+1, b-1, 0);
		else
		{
			ans = dp(a+1, b, 0); // do nothing
			// build
			int diff = max(0, h[a+1] - h[a] + 1);
			ans = min(ans, dp(a+2, b-1, 0) + diff);
			diff = max(diff, h[a+1] - h[a+2] + 1);
			ans = min(ans, dp(a+2, b-1, 1) + diff);
		}
	}
	done[a][b][c] = 1;
//	printf("%d %d %d: %d\n", a, b, c, ans);
	return memo[a][b][c] = ans;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);
	k = (n/2) + (n%2);
	for (int i = 1; i <= k; i++)
	{
		int ans = dp(0, i, 0);
		printf("%d ", ans);
	}
	printf("\n");
}