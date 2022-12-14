//Be Name Khoda
//no comment...
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1007;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
ll a[MAXN], b[MAXN], c[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll g, d, f;
	cin >> g >> d >> f;
	for (int i = 0; i < g; i++)
		cin >> a[i];
	
	for (int i = 0; i < d; i++)
		cin >> b[i];
	
	for (int i = 0; i < f; i++)
		cin >> c[i];
	
	
	sort(a, a + g);
	sort(b, b + d);
	sort(c, c + f);
	
	if(d < 2 || f < 3)
		return cout << 0, 0;
	
	ll ans = 0;
	for (int i = 0; i < d; i++)
		for (int j = i + 1; j < d; j++)
		{
			if(b[j] > 2 * b[i])
				continue;
			ll p1 = upper_bound(a, a + g, b[i]) - a;
			ll p2 = lower_bound(a, a + g, b[j]) - a - 1;
			ll len = max(0LL, p2 - p1 + 1);
			
			p1 = upper_bound(c, c + f, b[i]) - a;
			p2 = lower_bound(c, c + f, b[j]) - a - 1;
			ll len2 = max(0LL, p2 - p1 + 1);
			ans += len * len2 * (len2 - 1) * (len2 - 2) / 6;
		}
	for (int i = 0; i < f; i++)
		for (int j = i + 1; j < f; j++)
		{
			if(c[j] > 2 * c[i])
				continue;
			ll p1 = upper_bound(a, a + g, c[i]) - a;
			ll p2 = lower_bound(a, a + g, c[j]) - a - 1;
			ll len = max(0LL, p2 - p1 + 1);
			
			p1 = upper_bound(b, b + d, c[i]) - b;
			p2 = lower_bound(b, b + d, c[j]) - b - 1;
			ll len2 = max(0LL, p2 - p1 + 1);
			
			p1 = upper_bound(c, c + f, c[i]) - c;
			p2 = lower_bound(c, c + f, c[j]) - c - 1;
			ll len3 = max(0LL, p2 - p1 + 1);
			ans += len * len3 * len2 * (len2 - 1) / 2;
		}
	for (int i = 0; i < g; i++)
		for (int j = 0; j < d; j++)
		{
			ll p = min(a[i], b[j]), q = max(a[i], b[j]);
			if(q > p * 2)
				continue;
			ll p1 = upper_bound(b, b + d, p) - b;
			ll p2 = lower_bound(b, b + d, q) - b - 1;
			ll len = max(0LL, p2 - p1 + 1);
			
			p1 = upper_bound(c, c + f, p) - c;
			p2 = lower_bound(c, c + f, q) - c - 1;
			ll len2 = max(0LL, p2 - p1 + 1);
			ans += len * len2 * (len2 - 1) * (len2 - 2) / 6;
		}
	for (int i = 0; i < g; i++)
		for (int j = 0; j < f; j++)
		{
			ll p = min(a[i], c[j]), q = max(a[i], c[j]);
			if(q > p * 2)
				continue;
			ll p1 = upper_bound(b, b + d, p) - b;
			ll p2 = lower_bound(b, b + d, q) - b - 1;
			ll len = max(0LL, p2 - p1 + 1);
			
			p1 = upper_bound(c, c + f, p) - c;
			p2 = lower_bound(c, c + f, q) - c - 1;
			ll len2 = max(0LL, p2 - p1 + 1);
			
			ans += len * (len - 1) * len2 * (len2 - 1) / 4;
		}
	for (int i = 0; i < d; i++)
		for (int j = 0; j < f; j++)
		{
			ll p = min(b[i], c[j]), q = max(b[i], c[j]);
			if(q > 2 * p)
				continue;
			
			ll p1 = upper_bound(a, a + g, p) - a;
			ll p2 = lower_bound(a, a + g, q) - a - 1;
			ll len = max(0LL, p2 - p1 + 1);
			p1 = upper_bound(c, c + f, p) - c;
			p2 = lower_bound(c, c + f, q) - c - 1;
			ll len2 = max(0LL, p2 - p1 + 1);
			
			p1 = upper_bound(b, b + d, p) - b;
			p2 = lower_bound(b, b + d, q) - b - 1;
			ll len3 = max(0LL, p2 - p1 + 1);
			
			ans += len * len2 * (len2 - 1) * len3 / 2;
		}
	cout << ans;
}