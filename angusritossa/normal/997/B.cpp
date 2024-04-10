#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans;
bool memo[100][10000];
bool seen[10000];
void dp(int a, int b)
{
	if (a == n)
	{
		if (!seen[b]) 
		{
			seen[b] = 1;
			ans++;
		}
		return;
	}
	if (memo[a][b]) return;
	memo[a][b] = 1;
	dp(a+1, b+1);
	dp(a+1, b+5);
	dp(a+1, b+10);
	dp(a+1, b+50);
}
int main()
{
	scanf("%I64d", &n);
	ll newn = n;
	if (n > 30)
	{
		n = 30;
	}
	dp(0, 0);
	ans += (newn-n)*49;
	printf("%I64d\n", ans);
}