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
ll dp[MAXN], x[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 1; i < n; i++)
		if(x[i] - x[i - 1] > k)
			return cout << -1, 0;
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if(x[i] - x[j] <= k)
				dp[i] = min(dp[j] + 1, dp[i]);
	cout << dp[n - 1];
}