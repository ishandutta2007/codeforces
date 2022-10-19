#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll best, ans, l;
vector<pair<ll, ll> > things;
ll total;
int main()
{
	best = total = ((ll)1 << 60);
	scanf("%I64d%I64d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		best*=(ll)2;
		ll a;
		scanf("%I64d", &a);
		if (a < best)
		{
			things.emplace_back(((ll)1 << i), a);
			best = a;
		}
	}
	reverse(things.begin(), things.end());
	ans = 0;
	for (int i = 0; i < things.size(); i++)
	{
		ans += (l/things[i].first) * things[i].second;
		l -= (l/things[i].first) * things[i].first;
		total = min(total, ans + (ll)things[i].second);
	}
	if (l == 0) total = min(total, ans);
	printf("%I64d\n", total);
}