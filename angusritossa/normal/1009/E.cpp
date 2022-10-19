#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
typedef long long ll;
int n;
ll ans;
ll a[1000010];
ll add = 1;
ll freq[1000010];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
	freq[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		freq[i] %= mod;
		ans += freq[i] * a[n-i];
		ans %= mod;
		freq[i+1] = freq[i]*2 + add;
		add*=2;
		add %= mod;
	}
	printf("%I64d\n", ans);
}