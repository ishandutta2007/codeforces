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
int dp[MAXN], a[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	
	dp[0] = min(n, k + 1);
	for (int i = 1; i < n; i++)
	{
		int prev = max(0, i - k), nxt = min(n - 1, i + k);
		dp[i] = nxt - prev + 1;
		if(a[i] != -1)
		{
			dp[i] += dp[a[i]];
			int prev1 = max(0, a[i] - k), nxt1 = min(a[i] + k, n - 1);
			int eshter = max(0, min(nxt, nxt1) - max(prev1, prev) + 1);
			dp[i] -= eshter;
		}
	}
	for (int i = 0; i < n; i++)
		cout << dp[i] << " ";
}