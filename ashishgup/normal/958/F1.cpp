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

#define int long long

const int N = 105;

int n, m;
int a[N];
int want[N];
int have[N];
bool check() {
	for (int i = 1; i <= m; i++)
		if (a[i] != want[i])
			return 0;
	return 1;
}
int32_t main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> have[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> want[i];
	}

	bool ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			memset(a, 0, sizeof(a));
			for (int k = i; k <= j; k++) {
				a[have[k]]++;
			}
			ans |= check();
		}
	}
	puts(ans ? "YES" : "NO");

	print_time
}