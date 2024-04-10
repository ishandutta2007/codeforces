#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll memo[20][300000][2];
bool done[20][300000][2];
ll A[20];
ll B[20], n, m;
ll pow(ll a)
{
	ll ans = 1;
	for (int i = 0; i < a; i++) ans*=(ll)10;
	return ans;
}
ll dp(int a, int b, bool c)
{
	if (a == -1) return 0;
	if (done[a][b][c]) { return memo[a][b][c]; }
	done[a][b][c] = true;
	ll ans = -((ll)1 << 62);
	for (int i = 0; i < n; i++)
	{
		if (!(b & ((ll)1 << i)))
		{
		//	printf("%I64d %I64d\n", A[i], B[a]);
			bool nextc = true;
			if (c && A[i] > B[a]) continue;
			b ^= ((ll)1 << i);
			if (!c || A[i] < B[a]) nextc = false;
			ans = max(ans, dp(a-1, b, nextc) + A[i]*pow(a));
			b ^= ((ll)1 << i);
		}
	}
//	printf("%I64d\n", ans);
	return memo[a][b][c] = ans;
}
ll ans;
int main()
{
	ll a;
	ll b;
	scanf("%I64d%I64d", &a, &b);
	while (a)
	{
		A[n++] = a%10;
		a/=10;
	}
	while (b)
	{
		B[m++] = b%10;
		b/=10;
	}
	assert(m >= n);
	if (n == m)
	{
		ans = dp(n-1, 0, true);
	}
	else
	{
		ans = dp(n-1, 0, false);
	}
	printf("%I64d\n", ans);
}