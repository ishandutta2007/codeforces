#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000010];
int n;
ll ans;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2*n; i++) scanf("%lld", &a[i]);
	sort(a, a+(2*n));
	ll side1, side2;
	side1 = a[n-1] - a[0];
	side2 = a[2*n-1] - a[n];
	ans = side1*side2;
	for (int i = 1; i < n; i++)
	{
		ll side1, side2;
		side1 = a[i+n-1] - a[i];
		side2 = a[2*n-1] - a[0];
		ans = min(ans, side1*side2);
	}
	printf("%lld\n", ans);
}