#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update > pbds;

#define print_time cerr << "Time elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

//#define int long long
//#define float long double

const int N = 2e5+5;
int n, m;
int have[N], want[N];
multiset<int> need, extra;

int32_t main(){

	cin >> n >> m;

	for (int i = 1; i <= n; i++) 
		cin >> have[i];
	for (int i = 1; i <= m; i++) {
		cin >> want[i];
		for (int j = 1; j <= want[i]; j++)
			need.insert(i);
	}

	int L = 1;
	int ans = INT_MAX;
	for (int R = 1; R <= n; R++) {
		if (need.find(have[R]) != need.end()) {
			need.erase(need.find(have[R]));
		}
		else {
			extra.insert(have[R]);
		}
		if (!need.empty()) continue;
		while (extra.find(have[L]) != extra.end()) {
			extra.erase(extra.find(have[L]));
			L++;
		}
		ans = min(ans, (int)extra.size());
	}

	if (ans == INT_MAX) ans = -1;
	cout << ans;


	print_time
}