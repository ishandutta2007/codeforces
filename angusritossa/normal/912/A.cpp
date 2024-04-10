#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, x, y, z;
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d", &a, &b, &x, &y, &z);
	a-=2*x;
	b-=3*z;
	a-=y;
	b-=y;
	ll ans = 0;
	ans += max(-a, (ll)0);
	ans += max(-b, (ll)0);
	printf("%I64d\n", ans);
}