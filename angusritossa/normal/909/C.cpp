#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll memo[5010][5010], n;
char op[5010];
ll dp(ll i, ll j)
{
	if (i == n-1) return 1;
	if (memo[i][j]) return memo[i][j];
	ll ans = 0;
	ll adding = op[i] == 'f';
//	printf("%lld %d\n", i, adding);
	if (j && !adding) ans+=dp(i, j-1);
	ans+=dp(i+1, j+adding);
	return memo[i][j] = ans % (MOD);
}
int main()
{
	scanf("%I64d", &n);
	for (int i = 0; i < n; i++) scanf(" %c", &op[i]);
	printf("%I64d\n", dp(0, 0));
}