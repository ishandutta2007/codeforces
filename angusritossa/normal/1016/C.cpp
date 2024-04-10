#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[500010], b[500010], amleft[500010], amright[500010], ans, sum;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]), sum += a[i];
	for (int i = 0; i < n; i++) scanf("%lld", &b[i]), sum += b[i];
	ll delta = 0;
	ll am = 0;
	for (ll i = n-1; i >= 0; i--)
	{
		delta += a[i] + b[i];
		am += delta;
		am += b[i] * (2*(n-i)-1);
		amleft[i] = am;
		//printf("%lld - %lld\n", delta, amleft[i]);
		ll additional = (i);
		additional*=2;
		amleft[i] += delta * additional;
	}
	delta = 0;
	am = 0;
	for (ll i = n-1; i >= 0; i--)
	{
		delta += a[i] + b[i];
		am += delta;
		am += a[i] * (2*(n-i)-1);
		amright[i] = am;
		ll additional = (i);
		additional*=2;
		amright[i] += delta * additional;
	}
	am = 0;
	for (ll i = 0; i < n; i++)
	{
		if (i%2) ans = max(ans, amright[i] + am);
		else ans = max(ans, amleft[i] + am);
		if (i%2)
		{
			am += (2*i+1)*b[i];
			am += (2*i+2)*a[i];
		}
		else
		{
			am += (2*i+1)*a[i];
			am += (2*i+2)*b[i];
		}
		//printf("%lld %lld - %lld\n", amleft[i], amright[i], am);
	}
	ans -= sum;
	printf("%lld\n", ans);
}