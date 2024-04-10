#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ans, am;
int main()
{
	scanf("%I64d%I64d", &n, &k);
	ll mxbit = 0;
	for (ll i = 0; i < 62; i++)
	{
		if (n & (((ll)1 << i))) { mxbit = i; am++; }
	}
	if (k == 1)
	{
		printf("%I64d\n", n);
	}
	else printf("%I64d\n", ((ll)1 << (mxbit+1))-1);
}