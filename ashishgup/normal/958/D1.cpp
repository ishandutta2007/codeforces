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
#define float long double

map<pair<int, int>, int> m;
pair<int, int> val[200005];


int32_t main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf(" (%d+%d)/%d", &a, &b, &c);
		int num = a + b;
		int den = c;
		int gcd = __gcd(num, den);
		num /= gcd;
		den /= gcd;
		val[i] = {num,den};
		m[val[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		cout << m[val[i]] << " ";
	}
	print_time
}