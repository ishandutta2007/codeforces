#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll Val[200010], TreeL[200010], TreeR[200010];

int main()
{
	ll n, k, a, b, q;
	scanf("%lld%lld%lld%lld%lld", &n, &k, &a, &b, &q);
	for(ll i = 1; i <= q; i++)
	{
		ll op;
		scanf("%lld", &op);
		if(op == 1)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			ll s1 = min(Val[x] + y, b) - min(Val[x], b);
			for(ll i = x; i <= n; i += i & (-i)) TreeL[i] += s1;
			ll s2 = min(Val[x] + y, a) - min(Val[x], a);
			for(ll i = x; i; i -= i & (-i)) TreeR[i] += s2;
			Val[x] += y;
		}
		else
		{
			ll x, ans = 0;
			scanf("%lld", &x);
			for(ll i = x - 1; i; i -= i & (-i)) ans += TreeL[i];
			for(ll i = x + k; i <= n; i += i & (-i)) ans += TreeR[i];
			printf("%lld\n", ans);
		}
	}
	return 0;
}