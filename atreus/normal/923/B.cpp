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
const int MAXN = (int)1e5 + 3;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
ll v[MAXN], t[MAXN], part[MAXN], ans[MAXN], cur[MAXN];
ll sum(ll l, ll r)
{
	if(r < l)
		return 0;
	ll ans = part[r];
	if(l != 0)
		ans -= part[l - 1];
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		cin >> t[i];
	
	for (int i = 0; i < n; i++)
	{
		part[i] = t[i];
		if(i != 0)
			part[i] += part[i - 1];
	}
	for (int i = 0; i < n; i++)
	{
		//day which fucks...
		ll l = i - 1, r = n - 1;
		while(r - l > 1)
		{
			int mid = (l + r) >> 1;
			if(sum(i, mid) >= v[i])
				r = mid;
			else
				l = mid;
		}
		//cur[i, r - 1]++;
		
		cur[i]++;
		cur[r]--;
		
		ans[r] += min(t[r], v[i] - sum(i, r - 1));
	}
	for (int i = 1; i < n; i++)
		cur[i] += cur[i - 1];
	
	for (int i = 0; i < n; i++)
		cout << cur[i] * t[i] + ans[i] << " ";
}